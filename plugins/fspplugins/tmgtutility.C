// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips911 src/tmgt/fsp/tmgtutility.C 1.13.16.18 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2005,2018 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 
//  LAST_VERSION_FROM_CC:
// $Source: fips740 fsp/src/tmgt/fsp/tmgtutility.C 4$


/**
 * @file tmgtutility.C
 *
 * @brief This file contains the implementation of various thermal management
 *        internal utility functions.
 */

#include <tmgtutility.H>
#ifndef _X86NFP
#include <utilregx.H>
#include <srcisrc.H>
#include <fstp.H>
#include <sink.H>
#include <tmgtmsg.H>
#include <tmgt_pcap.H>
#include <tmgtPwrDef.H>
#include <fwdbClient.H>
#include <hwsvCommonUtility.H>
#include <forbappclient.H>
#include <utilfile.H>
#include <attributeenums.H>
#include <dirent.h>
#include <fnmatch.h>
#include <utilfile.H>
#include <mnfgPolicyFlags.H>
#include <hwsvRequestContext.H>
#include <tmgt_pexcmd.H>
#include <tmgt_p1p2file.H>
#include <tmgt.H>

/**
 * @brief Operation field in a netc/nets message.
 */
const uint16_t TMGT_NO_OPERATION              = 0;

/*-----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*-----------------------------------------------------------------------------*/
extern tracDesc_t g_tmgtTraceDesc;

char TOIF_DAEMON_NAME[TMGT_MAX_NUMBER_OF_NODES][14] =
{
    { "toif0.daemon_" },
    { "toif1.daemon_" },
    { "toif2.daemon_" },
    { "toif3.daemon_" }
};


/*-----------------------------------------------------------------------------*/
/* Constants/Tables                                                            */
/*-----------------------------------------------------------------------------*/
/********************************************************************************/
/* Document: 11/11/13   FN = p1_p2_file_definitions.doc                         */
/********************************************************************************/
//
const struct p1_p2_file_table_t G_p1_p2_file_table[] =
{
/* NOTE! Both files have a max of 512 bytes (0x200).  So if your index + size goes over that, its not going to work */

/******************************* P1 File Data *******************************/
// Item                                Node     File          Size    Index
    {TMGT_FILE_VERSION,             NO_NODE,      TMGT_P1_FILE,   1,      0x000},
    {TMGT_FILE_OVERSUBSCRIPTION_PCAP,     0,      TMGT_P1_FILE,   2,      0x001}, // non-ITE: from def file, ITE: from CMM
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,  16,      0x005}, // RESERVED for additional nodes - one more byte
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,  18,      0x01E}, // RESERVED
    {TMGT_FILE_PCAP_MAX,                  0,      TMGT_P1_FILE,   2,      0x030},
    {TMGT_FILE_PCAP_MAX,                  1,      TMGT_P1_FILE,   2,      0x032},
    {TMGT_FILE_PCAP_MAX,                  2,      TMGT_P1_FILE,   2,      0x034},
    {TMGT_FILE_PCAP_MAX,                  3,      TMGT_P1_FILE,   2,      0x036},
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,   8,      0x038}, // RESERVED
    // NODE_CURR_PCAP is different from CURR_POWER_CAP (which is the customer set value)
    // This value is how TMGT divided up the CURR_POWER_CAP between the nodes.
    {TMGT_FILE_NODE_CURR_PCAP,            0,      TMGT_P1_FILE,   2,      0x040},
    {TMGT_FILE_NODE_CURR_PCAP,            1,      TMGT_P1_FILE,   2,      0x042},
    {TMGT_FILE_NODE_CURR_PCAP,            2,      TMGT_P1_FILE,   2,      0x044},
    {TMGT_FILE_NODE_CURR_PCAP,            3,      TMGT_P1_FILE,   2,      0x046},
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,   8,      0x048}, // RESERVED
    {TMGT_FILE_PCAP_MIN,                  0,      TMGT_P1_FILE,   2,      0x050}, // DC W calculated by TMGT
    {TMGT_FILE_PCAP_MIN,                  1,      TMGT_P1_FILE,   2,      0x052},
    {TMGT_FILE_PCAP_MIN,                  2,      TMGT_P1_FILE,   2,      0x054},
    {TMGT_FILE_PCAP_MIN,                  3,      TMGT_P1_FILE,   2,      0x056},
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,   8,      0x058}, // RESERVED
    {TMGT_FILE_SOFT_PCAP_MIN,             0,      TMGT_P1_FILE,   2,      0x060}, // from def file
    {TMGT_FILE_PCAP_TURBO,                0,      TMGT_P1_FILE,   2,      0x064},
    {TMGT_FILE_DVFS_PCAP_MIN,             0,      TMGT_P1_FILE,   2,      0x068},
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,   4,      0x06C}, // RESERVED
    // stored as: AC Watts
    {TMGT_FILE_AC_PCAP_MAX,               0,      TMGT_P1_FILE,   2,      0x070},
    {TMGT_FILE_AC_PCAP_MAX,               1,      TMGT_P1_FILE,   2,      0x072},
    {TMGT_FILE_AC_PCAP_MIN,               0,      TMGT_P1_FILE,   2,      0x074},
    {TMGT_FILE_AC_PCAP_MIN,               1,      TMGT_P1_FILE,   2,      0x076},
    {TMGT_FILE_AC_SOFT_PCAP_MIN,          0,      TMGT_P1_FILE,   2,      0x078},
    {TMGT_FILE_AC_SOFT_PCAP_MIN,          1,      TMGT_P1_FILE,   2,      0x07A},
    {TMGT_FILE_AC_PCAP_TURBO,             0,      TMGT_P1_FILE,   2,      0x07C},
    {TMGT_FILE_AC_PCAP_TURBO,             1,      TMGT_P1_FILE,   2,      0x07E},
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P1_FILE,  16,      0x080}, // RESERVED leftover bytes. Out of 272bytes.


/******************************* P2 File Data *******************************/
// Item                                Node     File          Size    Index
    {TMGT_FILE_VERSION,             NO_NODE,      TMGT_P2_FILE,   1,      0x000},
    {TMGT_FILE_SMS_ENCODE,                0,      TMGT_P2_FILE,   2,      0x001},
    {TMGT_FILE_SMS_ENCODE,                1,      TMGT_P2_FILE,   2,      0x003},
    {TMGT_FILE_CUST_SET_MODE,       NO_NODE,      TMGT_P2_FILE,   1,      0x005},
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P2_FILE,  59,      0x006}, // RESERVED

    {TMGT_FILE_CURR_POWER_CAP,            0,      TMGT_P2_FILE,   2,      0x041}, // DC Watts
    {TMGT_FILE_AC_CURR_POWER_CAP,         0,      TMGT_P2_FILE,   2,      0x045}, // AC Watts
    {TMGT_FILE_RESERVED_BYTES,      NO_NODE,      TMGT_P2_FILE,  71,      0x049}, // RESERVED. Left over bytes out of 144


/******************************* END OF TABLE *******************************/
    {TMGT_FILE_END,                       0,      TMGT_P1_FILE,   0,      0},
};


/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       get_item_offset                                                 */
/*                                                                              */
/*  Function:   Get table offset of specified item/node                         */
/*                                                                              */
/*  Thread:     Should support all threads                                      */
/*                                                                              */
/* End Function Specification ***************************************************/
uint16_t get_item_offset(const tmgtP1P2FileItem i_item, const uint8_t i_node)
{
    uint16_t l_table_index;

    for(l_table_index = 0; TMGT_FILE_END != G_p1_p2_file_table[l_table_index].item; l_table_index++)
    {
        if (i_item == G_p1_p2_file_table[l_table_index].item)
        {
            // Now check if node matches (or is not required)
            if ((i_node == G_p1_p2_file_table[l_table_index].node) ||
                (NO_NODE == G_p1_p2_file_table[l_table_index].node))
            {
                // We found the matching one...break out
                break;
            }
        }
    }
    if (TMGT_FILE_END == G_p1_p2_file_table[l_table_index].item)
    {
        l_table_index = 0xFFFF;
    }

    return l_table_index;

} // end get_item_offset()


/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       p1_p2_file_read                                                 */
/*                                                                              */
/*  Function:   Read value(s) from the P1/P2 file                               */
/*                                                                              */
/*  Thread:     Should support all threads                                      */
/*                                                                              */
/*  Note:       All values must be from the same file (P1 or P2)                */
/*                                                                              */
/*  Flow:   03/08/09    FN=p1_p2_file_read_write_2.sdr                          */
/*                                                                              */
/* End Function Specification ***************************************************/
errlHndl_t p1_p2_file_read(UtilFile *i_file,
                           const uint16_t  i_table_index,
                           p1_p2_file_item_t & io_data)
{
    errlHndl_t l_errlHndl = NULL;

    // Get the correct read size from our file size table
    io_data.length = G_p1_p2_file_table[i_table_index].size;

    // Zero out the data buffer
    bzero(io_data.value, io_data.length);

    // Make sure the file exists...
    if( i_file->exists() )
    {
        // Seek to our entry and read it
        i_file->seek(G_p1_p2_file_table[i_table_index].index, UtilStream::START);
        i_file->read(io_data.value, io_data.length);
#ifdef P1P2_DEBUG_TRACES
        TMGT_INF("p1_p2_file_read(%s) read 0x%04X", tmgtP1P2FileItemString[io_data.item_name], UINT16_GET(io_data.value));
#endif
    }
    // else defaulted to 0s


    return l_errlHndl;

} // end p1_p2_file_read()


/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       p1_p2_file_read_data                                            */
/*                                                                              */
/*  Function:   Read our files in P1/P2                                         */
/*                                                                              */
/*  Thread:     Should support all threads                                      */
/*                                                                              */
/*  Flow:   02/10/12    FN=p1_p2_file_read_data.sdr                             */
/*                                                                              */
/* End Function Specification ***************************************************/
errlHndl_t p1_p2_file_read_data(p1_p2_file_item_t *io_items,
                                const uint16_t i_num_items)
{
    const char *l_file_path = NULL;
    uint16_t l_which_file = 0xFFFF;
    errlHndl_t l_errlHndl = NULL;
    UtilFile * l_file = NULL;

    // Validate each item
    for (uint16_t l_item_index = 0; l_item_index < i_num_items; l_item_index++)
    {
        uint16_t l_item_offset = get_item_offset(io_items[l_item_index].item_name, io_items[l_item_index].node);
        if (l_item_offset != 0xFFFF)
        {
            if (l_file == NULL)
            {
                l_which_file = G_p1_p2_file_table[l_item_offset].file;
                // Open the file
                if(TMGT_P1_FILE == l_which_file)
                {
                    l_file_path = TMGT_tmgtP1Data;
                }
                else
                {
                    l_file_path = TMGT_tmgtP2Data;
                }
                l_file = new UtilFile(l_file_path);
                // Make sure the file exists...
                if( l_file->exists() )
                {
                    // It exists, open for reading
                    l_errlHndl = l_file->open("r");
                }
            }

            if ((NULL != l_file) && (NULL == l_errlHndl))
            {
                if (l_which_file == G_p1_p2_file_table[l_item_offset].file)
                {
                    if ((io_items[l_item_index].length == G_p1_p2_file_table[l_item_offset].size) &&
                        (io_items[l_item_index].length <= 4))
                    {
                        // p1_p2_file_read_write_2.sdr
                        l_errlHndl = p1_p2_file_read(l_file, l_item_offset, io_items[l_item_index]);
                    }
                    else
                    {
                        TMGT_ERR("p1_p2_file_read_data: Ignoring item %d because length mismatch %d vs %d (index %d, node %d)",
                                 io_items[l_item_index].item_name, io_items[l_item_index].length,
                                 G_p1_p2_file_table[l_item_offset].size, l_item_index, io_items[l_item_index].node);
                    }
                }
                else
                {
                    TMGT_ERR("p1_p2_file_read_data: Ignoring item %d because it is not in same file %s (index %d, node %d)",
                             io_items[l_item_index].item_name, l_file_path, l_item_index, io_items[l_item_index].node);
                }
            }
            else
            {
                TMGT_ERR("p1_p2_file_read_data: Unable to open %s",l_file_path);
            }
        }
        else
        {
            TMGT_ERR("p1_p2_file_read_data: Ignoring invalid item 0x%x (index %d, node %d). Given %d items.",
                     io_items[l_item_index].item_name, l_item_index, io_items[l_item_index].node, i_num_items);
        }
    }

    if (l_file != NULL)
    {
        // Get any errors created
        if(NULL == l_errlHndl)
        {
            l_errlHndl = l_file->getLastError();
        }

        l_file->Close();

        delete l_file;
        l_file = NULL;
    }

#ifdef P1P2_DEBUG_TRACES
    for (uint16_t l_item_index = 0; l_item_index < i_num_items; l_item_index++)
    {
        TMGT_INF("p1_p2_file_read_data: READ item# %d: %s, len=%d, node=%d, value=0x%08X",
                 l_item_index, tmgtP1P2FileItemString[io_items[l_item_index].item_name],
                 io_items[l_item_index].length, io_items[l_item_index].node,
                 UINT32_GET(io_items[l_item_index].value));
    }
#endif

    return l_errlHndl;

} // end p1_p2_file_read_data()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       get_occ_status                                                */
/*                                                                            */
/*  Function:   Determine OCC status for tmgtQueryModeAndFunction()           */
/*                                                                            */
/*  Thread:     client                                                        */
/*                                                                            */
/*  Flow:   01/07/09    FN=get_tpmf_status.sdr                                */
/*                                                                            */
/* End Function Specification *************************************************/
tmgtEmpathFunction get_occ_status()
{
    tmgtEmpathFunction l_occ_status = TMGT_EMPATH_FUNC_NOT_APPLICABLE;

        const occStateId l_occ_state = current_occ_state();

        if (STATE_IS_RESET(l_occ_state))
        {
            l_occ_status = TMGT_EMPATH_FUNC_DISABLE;
        }
        else
        {
            if (l_occ_state == 0)
            {
                l_occ_status = TMGT_EMPATH_FUNC_NOT_PRESENT;
            }
            else
            {
                // Set as active
                l_occ_status = TMGT_EMPATH_FUNC_ACTIVE;
            }
        }

    return l_occ_status;

} /* end get_occ_status() */



errlHndl_t getFlattenLog(NetcMessage &l_respMsg)
{
    errlHndl_t l_errlHndl = NULL;

    if ((l_respMsg.getFlags() & NetcMessage::anErrorIncl) && (l_respMsg.dataLength() > 0))
    {
        l_errlHndl = new ErrlEntry();
        errlstatus_t flatten_status;

        // Flags indicate this message has an error log.
        flatten_status = l_errlHndl->unflatten(l_respMsg.getData(), l_respMsg.dataLength());

        if (flatten_status != ERRL_STATUS_SUCCESS)
        {
            TMGT_ERR("Unable to get a unflattened a log.  Status = %x", flatten_status);
            delete l_errlHndl;
            l_errlHndl = NULL;

            // Create an error log entry.
            /*@
             * @errortype
             * @refcode    LIC_REFCODE
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode TMGT_RC_INTERNAL_ERROR
             * @moduleid   TMGT_FAILED_TO_UNFLATTEN_ERROR
             * @userdata1  Status returned from unflatten call
             * @userdata2
             * @userdata3
             * @userdata4
             * @devdesc    Failed to unflatten an error log
             */
            tmgtBldErrLog(l_errlHndl, TMGT_FAILED_TO_UNFLATTEN_ERROR, TMGT_RC_INTERNAL_ERROR,
                          flatten_status, 0, 0, 0, ERRL_SEV_INFORMATIONAL);

        }
    }

    return l_errlHndl;
} // END errlHndl_t getFlattenLog(NetcMessage &l_respMsg)



/**
 * @brief Get the sink_path from the sink_name
 *
 * @pre None
 *
 * @post None
 *
 * @param i_sink_name - The sink name
 * @param o_sink_path  - The sink path
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 */
errlHndl_t get_sink_path(const char *i_sink_name, char *&o_sink_path)
{
    errlHndl_t l_err = NULL;
    const char * l_regKey[1];
    uint32_t l_sinkPathSize = 0; // Don't need additional buffer space

    l_regKey[0] = P0_ROOT_PATH;
    l_err = UtilReg::path(l_regKey, 1, i_sink_name, o_sink_path, l_sinkPathSize);

    return l_err;
}

/**
 * @brief Synchronize the client with the server ensuring the server has started
 *        before sending it messages.
 *
 * @pre None
 *
 * @post None
 *
 * @param i_daemonWait - Determines whether or not this method should wait until
 *                       the tmgtnotifier daemon is ready to accept tmgtt requests.
 *                       A value of 0 means do not wait if the daemon is not yet ready.
 *                       A value of TMGT_DAEMON_WAIT_DEFAULT means wait the default
 *                       amount of time (currently 10 seconds).  Any other positive
 *                       value means wait that many seconds.
 * @param i_sink_name  - The path to the 'sink' file used by the daemon that the caller needs to synchronize with.
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval TMGT_RC_NO_DAEMON
 * @retval TMGT_STG_ALLOC
 *
 */
errlHndl_t tmgtSyncServer(uint32_t i_daemonWait, const char *i_sink_name)
{
#ifdef TMGT_INTERFACE_DEBUG
    TMGT_INF("Enter Tmgt:tmgtSyncServer(wait=%d, sink=%s)", i_daemonWait, i_sink_name);
#endif

    errlHndl_t l_errlHndl = NULL;
    uint32_t l_timeToWait;
    char *l_sinkPath;
    l_sinkPath = NULL;

    // Get the path to the file used to synchronize with the server
    l_errlHndl = get_sink_path(i_sink_name, l_sinkPath);
    if (NULL == l_errlHndl)
    {
        TMGT_DBG("sink:file path = %s",l_sinkPath);

        // Set up the synchronization timeout value
        if (0 == i_daemonWait) // essentially no waiting
        {
            l_timeToWait = SINK_ONE_MICROSECOND;
        }
        else // wait as many seconds as requested
        {
            l_timeToWait = SINK_ONE_SECOND * i_daemonWait;
        }

        l_errlHndl = sinkWithServer(l_sinkPath, l_timeToWait);
        if (NULL != l_errlHndl)
        {
            *l_errlHndl = TMGT_RC_NO_DAEMON;
        }
    }

    if (NULL != l_sinkPath)
    {
        free(l_sinkPath);
    }

    if (l_errlHndl)
    {
        // Add our component trace
        l_errlHndl->CollectTrace( TMGT_COMP_NAME, 2048 );
    }

    TMGT_DBG( "Exit Tmgt:tmgtSyncServer");

    return l_errlHndl;

} // end tmgtSyncServer()



/**
 * @brief A message is sent to the event notifier daemon and an acknowledgment
 *        message is received as required.
 *
 * @pre None
 *
 * @post None
 *
 * @param i_msg      - input parameter - The message to send to the event notifier
 * @param i_wait     - input parameter - An indication of whether or not the
 *                     routine should read an acknowledgment message from
 *                     the event notifier.
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval TMGT_RC_IPC_ERROR
 *
 */
errlHndl_t tmgtTalkToServer(NetcMessage     & i_msg,
                            NetcMessage     * io_respMsg,
                            const char      * i_daemon_file_name,
                            const uint32_t    i_resp_timeout)
{
#ifdef TMGT_INTERFACE_DEBUG
    TMGT_INF("Enter Tmgt:tmgtTalkToServer(%s)", i_daemon_file_name);
#endif

    errlHndl_t l_errlHndl = NULL;
    errlHndl_t l_errlHndl2 = NULL;
    NetcAddress *l_clientSocket;
    uint16_t l_function;
    bool l_need_to_add_trace = TRUE;

    l_clientSocket = NULL;

    // Open a socket connection to the event notifier daemon.
    l_clientSocket = new NetcAddress(i_daemon_file_name, l_errlHndl, NetcAddress::UNIX);
    if (NULL == l_errlHndl)
    {
        const uint32_t l_connectTimeout = i_resp_timeout;
        const timeval l_timeout = {(time_t)l_connectTimeout,0};
        l_clientSocket->setTimeout(l_timeout);
        l_errlHndl = netcConnect(*l_clientSocket);
        // Send the  message to the event notifier daemon.
        if (NULL == l_errlHndl)
        {
            l_errlHndl = netcSend(*l_clientSocket, i_msg);
            if (NULL == l_errlHndl)
            {
                if (io_respMsg != NULL)
                {
                    // Ensure timeout is still set before attempting receive
                    l_clientSocket->setTimeout(l_timeout);
                    l_errlHndl = netcRecv(*l_clientSocket, *io_respMsg);
                    if (NULL == l_errlHndl)
                    {
                        l_need_to_add_trace = FALSE;
                        l_function = io_respMsg->getFunction();
                        switch ( l_function )
                        {
                            case TMGT_ACK:
                                l_errlHndl = getFlattenLog(*io_respMsg);
                                break;
                            case TMGT_NACK:
                                ErrlEntry::recv(*l_clientSocket, l_errlHndl);
                                break;
                            default:
                                TMGT_ERR("TMGT server returned invalid function (0x%02X) in response to function (0x%02X)",
                                         l_function, i_msg.getFunction());

                                // Create an error log entry.
                                /*@
                                 * @errortype
                                 * @refcode LIC_REFCODE
                                 * @subsys EPUB_FIRMWARE_SP
                                 * @reasoncode TMGT_RC_INTERNAL_ERROR
                                 * @moduleid TMGT_MODID_TALK_TO_SERVER
                                 * @userdata1 TMGT_RC_UNDEFINED_DAEMON_RESPONSE (return code)
                                 * @userdata2 invalid function field from the message
                                 * @userdata3 data length
                                 * @userdata4 none
                                 * @devdesc The daemon sent a response message with an invalid function field
                                 */
                                tmgtBldErrLog(l_errlHndl, TMGT_MODID_TALK_TO_SERVER, TMGT_RC_INTERNAL_ERROR,
                                              (uint32_t)TMGT_RC_UNDEFINED_DAEMON_RESPONSE, l_function, io_respMsg->dataLength(), 0, ERRL_SEV_INFORMATIONAL);

                                l_errlHndl->addUsrDtls(io_respMsg->getData(),
                                                       io_respMsg->dataLength(),
                                                       TMGT_COMP_ID,
                                                       TMGT_VERSION,
                                                       TMGT_MSG_DATA_TYPE);
                                break;
                        }
                    }
                    else
                    {
                        // netcRecv failure should be very rare, return error if it does happen
                        const uint16_t l_rc = l_errlHndl->getRC();
                        if (NETC_RECV_SELECT_TIMEOUT == l_rc)
                        {
                            TMGT_ERR("tmgtTalkToServer: netcRecv timeout after %d seconds (TMGT busy)", l_connectTimeout);
                        }
                        else
                        {
                            TMGT_INF("tmgtTalkToServer: netcRecv failed with rc=0x%04X", l_rc);
                        }
                    }
                }
                // else no response was expected
            }
            else
            {
                TMGT_ERR("tmgtTalkToServer: netcSend failed with rc=0x%04X", l_errlHndl->getRC());
            }
        }
        else
        {
            // netcConnect should not fail unless server is not started or 6 or more connections
            // have been opened and are not getting processed.  Return error if this happens.
            const uint16_t l_rc = l_errlHndl->getRC();
            if (NETC_CONN_TOUT_EGAIN_ERR == l_rc)
            {
                TMGT_ERR("tmgtTalkToServer: netcConnect timeout after %d seconds (TMGT busy)", l_connectTimeout);
            }
            else
            {
                TMGT_INF("tmgtTalkToServer: netcConnect failed with rc=0x%04X", l_rc);
            }
        }

        // Close the socket even if the netcConnect failed since netcConnect always
        // allocates a socket and depends upon its users to cleanup.
        l_errlHndl2 =  netcClose(*l_clientSocket);
        if (NULL != l_errlHndl2)
        {
            tmgtCmtErrLog(l_errlHndl2);
        }
    }

    if (l_errlHndl && l_need_to_add_trace)
    {
        // Add our component trace
        l_errlHndl->CollectTrace( TMGT_COMP_NAME, 2048 );
    }

    if (NULL != l_clientSocket)
    {
        delete l_clientSocket;
        l_clientSocket = NULL;
    }


    TMGT_DBG( "Exit Tmgt:tmgtTalkToServer");

    return l_errlHndl;

} // end tmgtTalkToServer()



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       forward_cmd                                                   */
/*                                                                            */
/*  Function:   Forward a NETC message to a particular server.                */
/*                                                                            */
/*  Thread:     client                                                        */
/*                                                                            */
/*  References: TMGT Component HLD/LLDD doc                                   */
/*                                                                            */
/*  Notes:      Returns NULL on success, else error handle                    */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t forward_cmd(NetcMessage    & i_msg,
                       NetcMessage    * o_respMsg,
                       const uint32_t   i_resp_timeout,
                       const TmgtCommPolicyFlags i_commFlags,
                       const char*      i_sink_name,
                       const char*      i_daemon_file_name,
                       const uint32_t   i_sink_timeout)
{
    errlHndl_t  l_errl = NULL;
    uint16_t    l_rc = 0;

#ifdef TMGT_INTERFACE_DEBUG
    uint32_t    l_len = i_msg.dataLength();
    TMGT_INF( "forward_cmd(function=0x%02X, length=0x%04X, daemon=%s, sink=%s)", i_msg.getFunction(), l_len,
               i_daemon_file_name, i_sink_name);
    if( l_len )
    {
        TRACFBIN(g_tmgtTraceDesc, "forward_cmd() sending:", i_msg.getData(), l_len);
    }
#endif

    l_errl = tmgtSyncServer(i_sink_timeout, i_sink_name);
    if (NULL == l_errl)
    {
        l_errl = tmgtTalkToServer(i_msg, o_respMsg, i_daemon_file_name, i_resp_timeout);
#ifdef TMGT_INTERFACE_DEBUG
        if (NULL == l_errl)
        {
            if (o_respMsg != NULL)
            {
                if (o_respMsg->dataLength())
                {
                	TMGT_BIN("forward_cmd() received:", o_respMsg->getData(), o_respMsg->dataLength());
                }
            }
        }
#endif
    }

    // If requested, eat all 'sink' errors.
    else if( i_commFlags & TMGT_COMM_IGNORE_SINK_ERRORS )
    {
        l_rc = l_errl->getRC();
        TMGT_INF( "forward_cmd(0x%X,%s) sink failed rc=0x%0X)",
                  i_msg.getFunction(), i_daemon_file_name, l_rc);
        delete l_errl;
        l_errl = NULL;
    }

    if (l_errl)
    {
        l_rc = l_errl->getRC();
        // Determine which thread the request was for
        uint8_t l_node = 0;
        tmgtThreadType l_thread = TMGT_THREAD_MAIN;
        if (0 == strcmp(TMGT_ENERGY_SCALE_SINK_FILE_NAME, i_sink_name))
        {
            l_thread = TMGT_THREAD_ENERGYSCALE;
        }
        else
        {
            // Determine node if TOIF thread
            for (uint8_t tmp_node = 0; tmp_node < TMGT_MAX_NUMBER_OF_NODES; ++tmp_node)
            {
                if (0 == strcmp(TOIF_SYNC_NAME[tmp_node], i_sink_name))
                {
                    l_thread = TMGT_THREAD_TOIF;
                    l_node = tmp_node;
                    break;
                }
            }
        }
        tmgtAddUsrDtls_msg(l_errl, i_msg, l_thread, l_node);
    }

#ifdef TMGT_INTERFACE_DEBUG
    TMGT_INF("forward_cmd() returning rc=0x%0X", l_rc);
#endif

    return l_errl;

} /* end forward_cmd() */



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       forward_cmd_to_es_thread                                      */
/*                                                                            */
/*  Function:   Forward a NETC message to the EnergyScale thread in the       */
/*              tmgt server                                                   */
/*                                                                            */
/*  Thread:     client                                                        */
/*                                                                            */
/*  References: TMGT Component HLD/LLDD doc                                   */
/*                                                                            */
/*  Notes:      Returns NULL on success, else error handle                    */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t forward_cmd_to_es_thread(tmgtMsgType i_msg,
                                    const void        * i_data_ptr,
                                    const uint16_t      i_data_length,
                                    NetcMessage       * o_respMsg,
                                    const uint32_t      i_resp_timeout,
                                    const TmgtCommPolicyFlags i_commFlags,
                                    const uint32_t      i_sink_timeout)
{
    NetcMessage::Flags l_msgFlags = NetcMessage::aNoFlagSet;
    if (o_respMsg != NULL)
    {
        // should receive a response for this message
        l_msgFlags = NetcMessage::netcAppResponseExpected;
    }
    NetcMessage l_msg(TMGT_COMP_ID, i_msg, TMGT_NO_OPERATION, l_msgFlags);

    // Build IPC message to TMGT process
    if (i_data_length)
    {
        l_msg.setData((char *)i_data_ptr, i_data_length);
    }

    return forward_cmd(l_msg, o_respMsg, i_resp_timeout, i_commFlags, TMGT_ENERGY_SCALE_SINK_FILE_NAME, TMGT_ENERGY_SCALE_IPC_FILE_NAME, i_sink_timeout);
}



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       detach_cmd_to_es_thread                                       */
/*                                                                            */
/*  Function:   Forward a NETC message to the EnergyScale thread in the       */
/*              energyscale thread in the tmgt server app                     */
/*                                                                            */
/*  Thread:     detach_cmd_to_es_thread                                       */
/*                                                                            */
/*  Notes:      i_msg must be allocated prior to calling this function        */
/*              and it will be deleted before this call exits.                */
/*              This call is meant to be called as a new thread so it does    */
/*              not hold up the calling function.                             */
/*                                                                            */
/* End Function Specification *************************************************/
void detach_cmd_to_es_thread(NetcMessage * i_msg)
{
    errlHndl_t l_errlHndl = NULL;

    percSetup();

    NetcMessage l_respMsg;
#ifdef TMGT_INTERFACE_DEBUG
    TMGT_INF("detach_cmd_to_es_thread(0x%02X) called (data_length=%d)", i_msg->getFunction(), i_msg->dataLength());
#endif
    l_errlHndl = forward_cmd(*i_msg, &l_respMsg, 1, TMGT_COMM_STANDARD, TMGT_ENERGY_SCALE_SINK_FILE_NAME, TMGT_ENERGY_SCALE_IPC_FILE_NAME);
    if (l_errlHndl)
    {
        TMGT_ERR("detach_cmd_to_es_thread(0x%02X, %d bytes) failed with rc=0x%04X",
                 i_msg->getFunction(), i_msg->dataLength(), l_errlHndl->getRC());
        tmgtCmtErrLog(l_errlHndl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }
#ifdef TMGT_INTERFACE_DEBUG
    else
    {
        TMGT_INF("detach_cmd_to_es_thread(0x%02X) success (rsp_data length=%d)", i_msg->getFunction(), l_respMsg.dataLength());
    }
#endif

    delete i_msg;

} // end detach_cmd_to_es_thread()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       forward_cmd_to_toif_thread                                    */
/*                                                                            */
/*  Function:   Forward a NETC message to the TOIF thread in the tmgt server  */
/*                                                                            */
/*  Thread:     tmgt shared library                                           */
/*                                                                            */
/*  Notes:      Returns NULL on success, else error handle                    */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t forward_cmd_to_toif_thread(const uint8_t             i_node,
                                      const uint8_t             i_occ,
                                      const toifWorkItemTask    i_task,
                                      const void              * i_data_ptr,
                                      const uint16_t            i_data_length,
                                      NetcMessage             * o_respMsg,
                                      const uint32_t            i_resp_timeout,
                                      const TmgtCommPolicyFlags i_commFlags,
                                      const uint32_t            i_sink_timeout,
                                      const bool                i_blocking)
{
    errlHndl_t l_err = NULL;

    if (i_node < TMGT_MAX_NUMBER_OF_NODES)
    {
        // Build IPC message to TOIF thread
        const uint16_t l_operation = (i_blocking?0x8000:0)|i_occ;
        NetcMessage::Flags l_msgFlags = NetcMessage::aNoFlagSet;
        if (o_respMsg != NULL)
        {
            // should receive a response for this message
            l_msgFlags = NetcMessage::netcAppResponseExpected;
        }
        NetcMessage l_msg(TMGT_COMP_ID, i_task, l_operation, l_msgFlags);
        const char *l_sinkName = TOIF_SYNC_NAME[i_node];
        const char *l_daemonName = TOIF_DAEMON_NAME[i_node];
        if (i_data_length)
        {
            l_msg.setData((char *)i_data_ptr, i_data_length);
        }

        l_err = forward_cmd(l_msg, o_respMsg, i_resp_timeout, i_commFlags, l_sinkName, l_daemonName, i_sink_timeout);
    }
    else
    {
        TMGT_ERR("Invalid node number (%d) specified for task 0x%04X", i_node, i_task);
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode TMGT_RC_INVALID_DATA
         * @moduleid  TMGT_MODID_TALK_TO_SERVER
         * @userdata1 node
         * @userdata2 OCC instance
         * @userdata3 task
         * @userdata4 command data length
         * @devdesc Invalid node number specified
         */
        tmgtBldErrLog(l_err, TMGT_MODID_TALK_TO_SERVER, TMGT_RC_INVALID_DATA,
                      i_node, i_occ, i_task, i_data_length, ERRL_SEV_INFORMATIONAL);
    }

    return l_err;

} // end forward_cmd_to_toif_thread



//* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       forward_cmd_to_tmgt_thread                                    */
/*                                                                            */
/*  Function:   Forward a NETC message to the other, non-energy scale thread  */
/*              in the tmgt server.                                           */
/*                                                                            */
/*  Thread:     client                                                        */
/*                                                                            */
/*  References: TMGT Component HLD/LLDD doc                                   */
/*                                                                            */
/*  Notes:      Returns NULL on success, else error handle                    */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t forward_cmd_to_tmgt_thread(NetcMessage       & i_msg,
                                      NetcMessage       * o_respMsg,
                                      const uint32_t      i_resp_timeout,
                                      const TmgtCommPolicyFlags i_commFlags,
                                      const uint32_t      i_sink_timeout)
{
    return forward_cmd(i_msg, o_respMsg, i_resp_timeout, i_commFlags, TMGT_SINK_FILE, TMGT_DAEMON_IPC_FILE_NAME, i_sink_timeout);
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       forward_cmd_to_server                                         */
/*                                                                            */
/*  Function:   Forward a NETC message to the main TMGT thread in the         */
/*              tmgt server                                                   */
/*                                                                            */
/*  Thread:     client                                                        */
/*                                                                            */
/*  References: TMGT Component HLD/LLDD doc                                   */
/*                                                                            */
/*  Notes:      Returns NULL on success, else error handle                    */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t forward_cmd_to_server(tmgtMsgType i_msg, void *i_data_ptr, uint16_t i_data_length, NetcMessage & o_respMsg)
{
    errlHndl_t l_errlHndl = NULL;
    NetcMessage l_msg(TMGT_COMP_ID, i_msg, TMGT_NO_OPERATION, NetcMessage::netcAppResponseExpected);

    // Build IPC message to TMGT process
    if (i_data_length)
    {
        l_msg.setData((char *)i_data_ptr, i_data_length);
    }
    l_errlHndl = forward_cmd_to_tmgt_thread( l_msg, &o_respMsg );

    return l_errlHndl;
} /* end forward_cmd_to_server() */




/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       read_mode_reg                                                   */
/*                                                                              */
/*  Function:   Read mode from registry                                         */
/*                                                                              */
/*  Thread:     client                                                          */
/*                                                                              */
/* End Function Specification ***************************************************/
errlHndl_t read_mode_reg(const char *i_regname, tmgtSysPwrMode & o_mode)
{
    errlHndl_t l_errlHndl = NULL;

    o_mode = TMGT_SYS_PWR_MODE_NO_CHANGE;

    // Read mode registry
    UtilRegX<uint32_t> l_mode_reg(i_regname);
    l_errlHndl = l_mode_reg.read(NULL);
    if (NULL == l_errlHndl)
    {
        o_mode = (tmgtSysPwrMode)l_mode_reg.getData();
    }
    else
    {
        TMGT_INF("Failure reading registry: %s", i_regname);
    }

    return l_errlHndl;
}



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       get_number_of_nodes                                           */
/*                                                                            */
/*  Function:   Get the number of nodes in system                             */
/*                                                                            */
/*  Thread:     many                                                          */
/*                                                                            */
/*  Flow:   06/12/09    FN=get_number_of_nodes.sdr                            */
/*                                                                            */
/* End Function Specification *************************************************/
uint8_t get_number_of_nodes()
{
    uint8_t l_number_of_nodes = 1;

    const uint8_t l_systemType = get_system_type();

    if (SYSTYPE_SINGLE_NODE != (l_systemType & SYSTYPE_SINGLE_NODE))
    {
        // Determine the number of nodes on multi-node system
        fwdbresult l_table("select i.* from part_table p join instance_table i on i.pid=p.id and p.class='enc' and p.type='cec' join collected_vpd c on c.inid=i.nid");
        errlHndl_t l_errlHndl = l_table.getErrl();
        if (l_errlHndl)
        {
            TMGT_ERR("get_number_of_nodes: Unable to get number of nodes from system model (rc=0x%04X)", l_errlHndl->getRC());
            l_errlHndl->CollectTrace(TMGT_COMP_NAME);
            tmgtCmtErrLog(l_errlHndl, ERRL_SEV_UNRECOVERABLE, ERRL_ACTION_REPORT);
        }
        else
        {
            l_number_of_nodes = l_table.numRows();
        }
    }

    return l_number_of_nodes;

} // end get_number_of_nodes()



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       tmgtGetPcapValues                                             */
/*                                                                            */
/*  Function:   Read pcap current, max, and min values from registry          */
/*                                                                            */
/*  Thread:     tmgt shared lib                                               */
/*                                                                            */
/* End Function Specification *************************************************/
void tmgtGetPcapValues(uint8_t    i_node,
                       uint16_t & o_pcap_cur,
                       uint16_t & o_pcap_max,
                       uint16_t & o_pcap_min,
                       uint16_t & o_pcap_over,
                       uint16_t & o_soft_pcap_min,
                       const bool i_ac_switch)
{
    errlHndl_t l_errlHndl = NULL;
    NetcMessage l_respMsg;
    uint8_t l_data[2] = { i_node, i_ac_switch};
    o_pcap_cur  = 0;
    o_pcap_max  = 0;
    o_pcap_min  = 0;
    o_pcap_over = 0;
    o_soft_pcap_min = 0;

    l_errlHndl = forward_cmd_to_es_thread(TMGT_GETPCAPVALUES, l_data, sizeof(l_data), &l_respMsg );
    if (NULL != l_errlHndl)
    {
        TMGT_ERR("Unable to get PCAP values from OCC");
        tmgtCmtErrLog(l_errlHndl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }
    else
    {
        if (sizeof(pcap_data_t) == l_respMsg.dataLength())
        {
            pcap_data_t * rspData = (pcap_data_t *) l_respMsg.getData();
            o_pcap_cur = rspData->pcap_cur;
            o_pcap_max = rspData->pcap_max;
            o_pcap_min = rspData->pcap_min;
            o_pcap_over = rspData->pcap_over;
            o_soft_pcap_min = rspData->soft_pcap_min;
        }
        else
        {
            TMGT_INF("tmgtGetPcapValues(): Unexpected data length %d, expected %d", l_respMsg.dataLength(),sizeof(pcap_data_t));
            TMGT_DBG_BIN("tmgtGetPcapValues() received:", l_respMsg.getData(), l_respMsg.dataLength());
        }
    }
}
/* end tmgtGetPcapValues() */



// Internal utility function to convert the mode change reason to a string
const char *mode_reason_string(const tmgtModeChangeReason i_reason)
{
    static char o_string[32] = "";
    switch(i_reason)
    {
        case TMGT_MODE_REASON_NORMAL:       return("NORMAL"); break;
        case TMGT_MODE_REASON_PWR_ON:       return("PWR_ON"); break;
        case TMGT_MODE_REASON_RE_IPL:       return("RE_IPL"); break;
        case TMGT_MODE_REASON_OCC_FAILURE:  return("OCC_FAILURE"); break;
        case TMGT_MODE_REASON_SAFE_MODE:    return("SAFE_MODE"); break;
        case TMGT_MODE_REASON_POWER_FAULT:  return("POWER_FAULT"); break;
        case TMGT_MODE_REASON_FSP_FAILURE:  return("FSP_FAILURE"); break;
        default: sprintf(o_string, "0x%02X", i_reason); break;
    }
    return o_string;
}


#endif // ifndef _X86NFP

// Internal utility function to convert the occ reset status to a string
const char *occ_reset_status_string(const occResetStatus i_status)
{
    switch(i_status)
    {
        case OCC_RESET_STATUS_SUCCESS:           return("SUCCESS"); break;
        case OCC_RESET_STATUS_MASTER_FAIL:       return("MASTER FAIL"); break;
        case OCC_RESET_STATUS_MAX_RESETS:        return("MAX RESETS"); break;
        default:                                 break;
    }
    return("UNKNOWN");
}

// The following 2 functions are used in the errl plugin and are the only
// only functions that must be compiled in x86.nfp context (_X86NFP)

// Internal utility function to convert the OCC state to a string
const char *state_string(const occStateId i_state)
{
    switch(i_state)
    {
        case OCC_STATE_NO_CHANGE:                return("NO CHANGE"); break;
        case OCC_STATE_STANDBY:                  return("STANDBY"); break;
        case OCC_STATE_OBSERVATION:              return("OBSERVATION"); break;
        case OCC_STATE_ACTIVE:                   return("ACTIVE"); break;
        case OCC_STATE_SAFE:                     return("SAFE"); break;
        case OCC_STATE_RESET:                    return("RESET"); break;
        case OCC_STATE_CHARACTERIZATION:         return("CHARACTERIZATION"); break;
        case OCC_STATE_IN_TRANSITION:            return("IN TRANSITION"); break;
        case OCC_STATE_LOADING:                  return("LOADING"); break;
        case OCC_STATE_UNKNOWN:                  return("UNKNOWN"); break;
        default:                                 break;
    }
    return("UNKNOWN");
}


// Internal utility function to convert the mode to a string
const char *mode_string(const tmgtSysPwrMode i_mode)
{
    switch(i_mode)
    {
        case TMGT_SYS_PWR_MODE_NO_CHANGE:         return("NO CHANGE"); break;
        case TMGT_SYS_PWR_MODE_NOMINAL:           return("NOMINAL"); break;
        case TMGT_SYS_PWR_MODE_TURBO:             return("TURBO"); break;
        case TMGT_SYS_PWR_MODE_SAFE:              return("SAFE"); break;
        case TMGT_SYS_PWR_MODE_POWER_SAVE:        return("POWER SAVE"); break;
        case TMGT_SYS_PWR_MODE_MIN_FREQUENCY:     return("MIN FREQUENCY"); break;
        case TMGT_SYS_PWR_MODE_DYNAMIC_PERF:      return("DYNAMIC PERFORMANCE"); break;
        case TMGT_SYS_PWR_MODE_FFO:               return("FFO"); break;
        case TMGT_SYS_PWR_MODE_MAX_PERF:          return("MAX PERFORMANCE"); break;
        case TMGT_SYS_PWR_MODE_FAILURE:           return("FAILURE"); break;
        case TMGT_SYS_PWR_MODE_IN_TRANSITION:     return("TRANSITION"); break;
        default:                                  break;
    }
    return("UNKNOWN");
}

#ifndef _X86NFP

// Internal utility to convert OOC command type to a string
const char *command_string(occCommandType i_cmd)
{
    // Code change due to this is not a thread safe function since multiple threads could be accessing
    const static struct string_data_t L_cmd_string[] = {{OCC_CMD_POLL, "POLL"},
        {OCC_CMD_CLEAR_ERROR_LOG, "CLEAR_ELOG"},
        {OCC_CMD_SET_MODE_AND_STATE, "SET_MODE_AND_STATE"},
        {OCC_CMD_SETUP_CONFIGURATION_DATA, "SET_CFG_DATA"},
        {OCC_CMD_SET_USER_PCAP, "SET_USER_PCAP"},
        {OCC_CMD_RESET_PREP, "RESET_PREP"},
        {OCC_CMD_SNAPSHOT_SYNC, "SNAPSHOT_SYNC"},
        {OCC_CMD_GET_CPU_TEMPERATURES, "GET_CPU_TEMPS"},
        {OCC_CMD_GET_OCC_SNAPSHOT, "GET_OCC_SNAPSHOT"},
        {OCC_CMD_DEBUG_PASS_THROUGH, "DEBUG_PASSTHRU"},
        {OCC_CMD_AME_PASS_THROUGH, "AME_PASSTHRU"},
        {OCC_CMD_GET_FIELD_DEBUG_DATA, "GET_FIELD_DEBUG_DATA"},
        {OCC_CMD_MFG_TEST, "MFG_TEST"},
        {OCC_CMD_TUNABLE_PARAMETERS, "TUNABLE_PARAMETERS"},
        // OCC_CMD_END_OF_TABLE should be the last entry record of this table
        {OCC_CMD_END_OF_TABLE, "Unknown Command"}};
    const uint8_t l_total = sizeof(L_cmd_string) / sizeof(struct string_data_t);
    uint8_t l_idx = 0;

    for (l_idx=0; l_idx<l_total; l_idx++)
    {
        if (i_cmd == L_cmd_string[l_idx].str_num)
        {
            // Return Code found
            break;
        }
    }

    if (l_total == l_idx)
    {
        // Set index to last entry record
        l_idx = l_total - 1;
    }

    return L_cmd_string[l_idx].str_data;
} // end command_string()




/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       tmgtDebugTrace                                                  */
/*                                                                              */
/*  Function:   Set debug trace level (defined in tmgtserver.H)                 */
/*                                                                              */
/*  Thread:     client                                                          */
/*                                                                              */
/* End Function Specification ***************************************************/
errlHndl_t tmgtDebugTrace(const uint32_t & i_data)
{
    errlHndl_t l_errlHndl = NULL;
    NetcMessage l_respMsg;

    l_errlHndl = forward_cmd_to_server(TMGT_DEBUG_TRACING, (void *)&i_data, sizeof(uint32_t), l_respMsg);

    return l_errlHndl;

} // end tmgtDebugTrace()



/** @brief Return the duration the system has been in the current mode,
 *        as well as the current mode.
 *
 * @param[out]        o_current_mode  Current power mode of the system.
 * @return            duration of time (in seconds) that they system has been
 *                    running in the current mode.
 *
 */
uint32_t tmgtQueryModeDuration(tmgtSysPwrMode & o_current_mode)
{
    errlHndl_t l_errlHndl = NULL;
    NetcMessage l_respMsg;
    uint32_t l_duration = 0;

    l_errlHndl = forward_cmd_to_es_thread(TMGT_QUERYMODEDURATION, NULL, 0, &l_respMsg);
    if (l_errlHndl == NULL)
    {
        uint8_t *l_ptr = (uint8_t *)l_respMsg.getData();
        l_duration = UINT32_GET(l_ptr);
        o_current_mode = (tmgtSysPwrMode)l_ptr[4];
    }
    else
    {
        TMGT_ERR("tmgtQueryModeDuration failed");
        tmgtCmtErrLog(l_errlHndl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }

    return l_duration;
}



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       tmgtRereadDefFile                                             */
/*                                                                            */
/*  Function:   Force re-reading of the power_management.def file             */
/*                                                                            */
/*  Thread:     tmgt shared lib                                               */
/*                                                                            */
/*  Notes:      Used for internal testing and mfg                             */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t tmgtRereadDefFile()
{
    errlHndl_t l_errlHndl = NULL;
    NetcMessage     l_respMsg;

    // Notify TMGT to process def file changes (PowerSave/Turbo frequency)
    l_errlHndl = forward_cmd_to_es_thread(TMGT_REREADDEFFILE, NULL, 0, &l_respMsg);
    if (l_errlHndl)
    {
        TMGT_ERR("TMGT re-reading of power_managment.def file failed");
    }

    return l_errlHndl;

} // end tmgtRereadDefFile()



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       tmgtInternalDebug                                             */
/*                                                                            */
/*  Function:   Used to send debug commands to the EnergyScale thread         */
/*                                                                            */
/*  Thread:     tmgt shared library                                           */
/*                                                                            */
/*  Notes:      INTERNAL TMGT USE ONLY                                        */
/*              i_data/length contains debug info requrested                  */
/*              o_result_string is string containing output for requested     */
/*              data.                                                         */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t tmgtInternalDebug(const uint8_t   i_data_length,
                             const uint8_t * i_data,
                             std::string   * o_result_string)
{
    errlHndl_t l_errlHndl = NULL;
    NetcMessage     l_respMsg;

    TMGT_INF("tmgtInternalDebug()");
    if (i_data_length > 0)
    {
        TMGT_BIN( "data", i_data, i_data_length);
    }
    l_errlHndl = forward_cmd_to_es_thread(TMGT_INTERNAL_DEBUG, i_data, i_data_length, &l_respMsg);
    if (NULL != l_errlHndl)
    {
        TMGT_ERR("tmgtInternalDebug failed with rc=0x%04X", l_errlHndl->getRC());
        tmgtCmtErrLog(l_errlHndl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }
    else
    {
        uint16_t l_rsp_len = l_respMsg.dataLength();
        if ((l_rsp_len > 0) && (o_result_string != NULL))
        {
            *o_result_string = std::string(l_respMsg.getData());
        }
    }

    return l_errlHndl;

} // end tmgtInternalDebug()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       tmgtPwrOnPresenceDetect                                       */
/*                                                                            */
/*  Function:   Called during power on to verify which nodes are present.     */
/*                                                                            */
/*  Thread:     tmgt shared library                                           */
/*                                                                            */
/* End Function Specification *************************************************/
void tmgtPwrOnPresenceDetect()
{
    TMGT_INF("tmgtPwrOnPresenceDetect called");

} /* end tmgtPwrOnPresenceDetect() */



/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       tmgtBldErrLog                                                   */
/*                                                                              */
/*  Function:   Takes the error log arguments and returns a pointer to the      */
/*              newly created error log                                         */
/*                                                                              */
/*  Thread:     client, server, fsp_role_change, thermal_alerts_and_reads       */
/*                                                                              */
/*  References: TMGT and TOIF build error log functions are combined            */
/*                                                                              */
/*  Flow:   03/31/06    FN=tmgt_build_error_log.sdr                             */
/*                                                                              */
/* End Function Specification ***************************************************/
void tmgtBldErrLog(errlHndl_t &i_errlHndl,
                   tmgtModId i_tmgtModId,
                   tmgtReturnCodes i_tmgtReturnCode,
                   uint32_t i_srcData1,
                   uint32_t i_srcData2,
                   uint32_t i_srcData3,
                   uint32_t i_srcData4,
                   errlSeverity i_errlSeverity,
                   bool         i_skipTrace,
                   const uint8_t i_node_num,
                   const comp_id_t i_comp_id)
{
    /*------------------------------------------------------------------*/
    /*  Local Variables                                                 */
    /*------------------------------------------------------------------*/
    uint8_t l_tmgtModId = i_tmgtModId;
    uint16_t l_ReturnAndReasonCode = i_tmgtReturnCode;
    errlEventType i_etype;

    /*------------------------------------------------------------------*/
    /*  Code                                                            */
    /*------------------------------------------------------------------*/

    if(i_skipTrace == FALSE)
    {
        char sev_string[11];
        switch(i_errlSeverity)
        {
            case ERRL_SEV_INFORMATIONAL: strcpy(sev_string, "INFO"); break;
            case ERRL_SEV_PREDICTIVE: strcpy(sev_string, "PRED"); break;
            case ERRL_SEV_UNRECOVERABLE: strcpy(sev_string, "UNREC"); break;
            case ERRL_SEV_UNRECOVERABLE1: strcpy(sev_string, "UNREC+PERF"); break;
            default: sprintf(sev_string, "0x%02X", i_errlSeverity); break;
        }

        if (i_comp_id == TMGT_COMP_ID)
        {
            TRACFCOMP(g_tmgtTraceDesc, ERR_MRK"tmgtBldErrLog: moduleId: 0x%02X, reasonCode: 0x%04X, data: %08X %08X %08X %08X, sev: %s",
                      i_tmgtModId, i_tmgtReturnCode, i_srcData1, i_srcData2, i_srcData3, i_srcData4, sev_string);
        }
        else
        {
            TRACFCOMP(g_tmgtTraceDesc, ERR_MRK"occBldErrLog: moduleId: 0x%02X, reasonCode: 0x%04X, data: %08X %08X %08X %08X, sev: %s",
                      i_tmgtModId, i_tmgtReturnCode, i_srcData1, i_srcData2, i_srcData3, i_srcData4, sev_string);
        }
    }

    // There is a refCode lookup table in src/epub/fsp/epub_map.C, where additional
    // callouts can be added based on the refCode:
    //   FSP_DEFAULT_REFCODE: No additional callouts added
    //   LIC_REFCODE: Add High priority service processor firmware Procedure (FSPSP04) and
    //                    Low priority intermittent problem Procedure (FSPSP06)
    //   FSP_LIC_REFCODE: Add Low priority intermittent problem Procedure (FSPSP06)
    //   FSP_LOGONLY_LIC_REFCODE: Add Med priority service processor firmware Procedure (FSPSP04)
    serviceCodes l_refCode = LIC_REFCODE;
    if (OCCC_COMP_ID == i_comp_id)
    {
        // SRCI should not add any additional callouts
        l_refCode = FSP_DEFAULT_REFCODE;
    }

    // Create the src
    SrciSrc l_src(SRCI_ERR_INFO,
                  SRCI_NO_ATTR,
                  l_tmgtModId,
                  l_refCode,
                  l_ReturnAndReasonCode,
                  i_srcData1,
                  i_srcData2,
                  i_srcData3,
                  i_srcData4);

    if(i_errlHndl == NULL)
    {
        i_etype = ERRL_ETYPE_NOT_APPLICABLE;

        if(i_errlSeverity == ERRL_SEV_INFORMATIONAL)
        {
            i_etype = ERRL_ETYPE_MISCELLANEOUS;
        }

        i_errlHndl = new ErrlEntry(i_comp_id,
                                   i_errlSeverity,
                                   i_etype,
                                   l_src);
    }
    else
    {
        // Add the created src
        i_errlHndl->addSRC(i_comp_id, l_src);
    }

    // Add TMGT component trace
    i_errlHndl->CollectTrace(TMGT_COMP_NAME);

    if (i_node_num != TRACE_NO_TOIF_NODES)
    {
        // Add TOIF node trace(s)
        uint8_t l_num_nodes = 1;
        uint8_t l_node = i_node_num;
        if (i_node_num == TRACE_ALL_TOIF_NODES)
        {
            l_num_nodes = get_max_nodes();
            l_node = 0;
        }

        // Get TOIF node start states.
        uint16_t l_activeNodesValue = 0;
        read_uint16_reg(TMGT_activeNodes, l_activeNodesValue, ERRL_ACTION_HIDDEN);

        while ((l_num_nodes > 0) && (l_num_nodes <= TMGT_MAX_NUMBER_OF_NODES))
        {
            //Make sure tpmd is started.
            if(l_activeNodesValue & (0x8000 >> l_node))
            {
                i_errlHndl->CollectTrace(TOIF_TRACE_COMP_NAME[l_node]);
            }
            l_node++;
            --l_num_nodes;
        }
    }

    // Set the return code
    *i_errlHndl = l_ReturnAndReasonCode;

} // end tmgtBldErrLog()




/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       tmgtCommitErrorLog                                              */
/*                                                                              */
/*  Function:   Will commit, delete, and null the passed in error log using the */
/*              sev/actions supplied                                            */
/*                                                                              */
/*  Thread:     client, server, fsp_role_change, thermal_alerts_and_reads       */
/*                                                                              */
/* End Function Specification ***************************************************/
void tmgtCmtErrLog(errlHndl_t &io_errlHndl,
                   const errlSeverity i_sev,
                   const errlActions i_action,
                   const comp_id_t i_comp_id)
{
#ifdef TMGT_DEBUG_TRACE
    TRACDCOMP0(g_tmgtTraceDesc, "Enter tmgtutility:tmgtCmtErrLog");
#endif

    if (io_errlHndl != NULL)
    {
        uint32_t l_extRefCode, l_modId;
        const SrciSrc *l_primSrc;

        char sev_string[6];
        switch(i_sev)
        {
            case ERRL_SEV_INFORMATIONAL: strcpy(sev_string, "INFO"); break;
            case ERRL_SEV_PREDICTIVE: strcpy(sev_string, "PRED"); break;
            case ERRL_SEV_UNRECOVERABLE: strcpy(sev_string, "UNREC"); break;
            default: sprintf(sev_string, "0x%02X", i_sev); break;
        }

        // Make a field trace of critical SRC data
        // Trace the primary SRC so we can see which component detected 1st error
        l_primSrc = io_errlHndl->getSRC();
        l_modId = l_primSrc->moduleId();
        l_extRefCode = l_primSrc->reasonCode();
        if (i_comp_id == TMGT_COMP_ID)
        {
            TRACFCOMP(g_tmgtTraceDesc, INFO_MRK"tmgtCmtErrLog: moduleId: 0x%02X, reasonCode: 0x%04X, sev: %s, action: 0x%04X",
                      l_modId, l_extRefCode, sev_string, i_action);
        }
        else
        {
            TRACFCOMP(g_tmgtTraceDesc, INFO_MRK"occCmtErrLog: moduleId: 0x%02X, reasonCode: 0x%04X, sev: %s, action: 0x%04X",
                      l_modId, l_extRefCode, sev_string, i_action);
        }

        io_errlHndl->setSev(i_sev);
        io_errlHndl->commit(i_comp_id, i_action);

        // Cleanup
        delete io_errlHndl;
        io_errlHndl = NULL;
    }
    else
    {
        TMGT_ERR("tmgtCmtErrLog() called with NULL error handle!!");
    }

#ifdef TMGT_DEBUG_TRACE
    TRACDCOMP0(g_tmgtTraceDesc, "Exit tmgtutility:tmgtCmtErrLog");
#endif
    return;
} // end tmgtCmtErrLog()



/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       tmgtCmtErrLogWithNoSeverityChange                               */
/*                                                                              */
/*  Function:   Will commit, delete, and null the passed in error log using the */
/*              sev/actions supplied                                            */
/*                                                                              */
/*  Thread:     client, server, fsp_role_change, thermal_alerts_and_reads       */
/*                                                                              */
/* End Function Specification ***************************************************/
void tmgtCmtErrLogWithNoSeverityChange(errlHndl_t &io_errlHndl, errlActions i_action)
{
    tmgtCmtErrLog(io_errlHndl, io_errlHndl->getSev(), i_action);
} // END void tmgtCmtErrLogWithNoSeverityChange



/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       get_pX_root_path                                                */
/*                                                                              */
/*  Function:   Gets the root path (signified by ROOT_PATH) and puts it into    */
/*              root_path_string                                                */
/*                                                                              */
/*  Thread:     Main                                                            */
/*                                                                              */
/* End Function Specification ***************************************************/
uint8_t get_pX_root_path(const uint8_t ROOT_PATH, char *root_path_string)
{
    /*------------------------------------------------------------------*/
    /*  Local Variables                                                 */
    /*------------------------------------------------------------------*/
    errlHndl_t l_errlHndl = NULL;
    static bool l_pX_read[4] = {FALSE, FALSE, FALSE, FALSE};
    static char l_p0_path[P0_ROOT_SZ];
    static char l_p1_path[P1_ROOT_SZ];
    static char l_p2_path[P2_ROOT_SZ];
    static char l_p3_path[P3_ROOT_SZ];

    uint8_t l_rc = 1;
    char *l_px_ptr = NULL;
    /*------------------------------------------------------------------*/
    /*  Code                                                            */
    /*------------------------------------------------------------------*/

    if( (ROOT_PATH <= 3) && (l_pX_read[ROOT_PATH] == FALSE) )
    {
        l_pX_read[ROOT_PATH] = TRUE; // Mark as true...try once per path to avoid logging errors repeatedly
        size_t l_pX_size;

        // Setup the path specific variables
        switch(ROOT_PATH)
        {
            case P0_REGISTRY_PATH:
                l_pX_size = P0_ROOT_SZ;
                strcpy(l_p0_path, "/opt/p0/");
                l_px_ptr = l_p0_path;
                l_errlHndl = UtilReg::read(P0_ROOT_PATH,root_path_string,l_pX_size);
                break;

            case P1_REGISTRY_PATH:
                l_pX_size = P1_ROOT_SZ;
                strcpy(l_p1_path, "/opt/p1/");
                l_px_ptr = l_p1_path;
                l_errlHndl = UtilReg::read(P1_ROOT_PATH,root_path_string,l_pX_size);
                break;

            case P2_REGISTRY_PATH:
                l_pX_size = P2_ROOT_SZ;
                strcpy(l_p2_path, "/opt/p2/");
                l_px_ptr = l_p2_path;
                l_errlHndl = UtilReg::read(P2_ROOT_PATH,root_path_string,l_pX_size);
                break;

            case P3_REGISTRY_PATH:
                l_pX_size = P3_ROOT_SZ;
                strcpy(l_p3_path, "/opt/p3/");
                l_px_ptr = l_p3_path;
                l_errlHndl = UtilReg::read(P3_ROOT_PATH,root_path_string,l_pX_size);
                break;

            default:
                strcpy(root_path_string, "/tmp/");
                l_rc = 0;
                break;
        }

        if (l_rc == 0)
        {
            // Do nothing
        }
        else if(l_errlHndl)
        {
            // There was an error
            l_rc = 0; // Failed

            // Following function deletes error handle for us
            tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, ERRL_ACTION_HIDDEN);
        }
        else
        {
            // Success
            l_rc = 1;
            strcpy(l_px_ptr, root_path_string);
        }
    }
    else // We already tried once, just give l_pX_path
    {
        switch(ROOT_PATH)
        {
            case P0_REGISTRY_PATH:
                strcpy(root_path_string, l_p0_path);
                break;

            case P1_REGISTRY_PATH:
                strcpy(root_path_string, l_p1_path);
                break;

            case P2_REGISTRY_PATH:
                strcpy(root_path_string, l_p2_path);
                break;

            case P3_REGISTRY_PATH:
                strcpy(root_path_string, l_p3_path);
                break;

            default:
                strcpy(root_path_string, "/tmp/");
                l_rc = 0;
                break;
        }
    }

    return l_rc;
} // END uint8_t get_pX_root_path(const uint8_t ROOT_PATH, char *root_path_string)


/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       create_thread                                                   */
/*                                                                              */
/*  Function:   Launches the past in function in a new thread.                  */
/*                                                                              */
/*  Thread:     Multiple                                                        */
/*                                                                              */
/*  References: pthread library                                                 */
/*                                                                              */
/* End Function Specification ***************************************************/
int create_thread(void *function, void *param, pthread_t *i_task)
{
    /*------------------------------------------------------------------*/
    /*  Local Variables                                                 */
    /*------------------------------------------------------------------*/
    int l_rc = 0;
    const uint32_t FAIL_THRESHOLD = 10;
    static uint32_t fail_count = 0;

    pthread_t taskStruct;
    pthread_t *myTask = &taskStruct;
    pthread_attr_t attributes;

    /*------------------------------------------------------------------*/
    /*  Code                                                            */
    /*------------------------------------------------------------------*/

    // Use the input struct if available...
    if(i_task != NULL)
    {
        myTask = i_task;
    }

    if (function != NULL)
    {
        do
        {

            // Get default thread attributes
            l_rc = pthread_attr_init(&attributes);
            if(l_rc != 0)
            {
                TRACFCOMP(g_tmgtTraceDesc, "Failed on pthread_attr_init:  Return code %d", l_rc);
                break;
            }


            l_rc = pthread_attr_setdetachstate(&attributes,PTHREAD_CREATE_DETACHED);
            if(l_rc != 0)
            {
                TRACFCOMP(g_tmgtTraceDesc, "Failed on pthread_attr_setdetachstate:  Return code %d", l_rc);
                break;
            }


            // Start the task
            l_rc = pthread_create(myTask,
                                  &attributes,
                                  (void * (*) (void *))function,
                                  (void *) param);

            if(l_rc != 0)
            {
                fail_count++;
                if (fail_count < FAIL_THRESHOLD)
                {
                    TMGT_ERR("Failed on pthread_create: Return code %d (function=%p, parm=%p, count=%d)",
                            l_rc, function, param, fail_count);
                }
                else if (fail_count == FAIL_THRESHOLD)
                {
                    TMGT_ERR("Failed on pthread_create: Return code %d (function=%p, parm=%p, count=%d), thresholding further errors",
                            l_rc, function, param, fail_count);
                    /*@
                    * @errortype
                    * @refcode LIC_REFCODE
                    * @subsys EPUB_FIRMWARE_SP
                    * @reasoncode TMGT_RC_INTERNAL_ERROR
                    * @moduleid TMGT_MODID_CREATE_THREAD
                    * @userdata1 rc
                    * @userdata2 fail_count
                    * @userdata3 function
                    * @userdata4 parm
                    * @devdesc Unable to create thread
                    */
                    errlHndl_t l_err = NULL;
                    tmgtBldErrLog(l_err, TMGT_MODID_CREATE_THREAD, TMGT_RC_INTERNAL_ERROR,
                                    l_rc, fail_count, (uint32_t)function, (uint32_t)param, ERRL_SEV_INFORMATIONAL);
                    tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
                }
                break;
            }
            else
            {
                if (fail_count > 0)
                {
                    TMGT_INF("pthread_create: success (fail_count=%d)", fail_count);
                    fail_count = 0;
                }
            }
        }while(0);
    }
    else
    {
        TRACFCOMP(g_tmgtTraceDesc, "NULL function pointer passed to create_thread.");
    }

    return l_rc;
}



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       readCecIplType                                                */
/*                                                                            */
/*  Function:   Reads the cec ipl value from smgr and returns to caller       */
/*                                                                            */
/*  Thread:     various                                                       */
/*                                                                            */
/*  References: tran_file_disable_tpmf.sdr                                    */
/*                                                                            */
/*  Notes:      Meant to be a utility function so nothing TMGT specific       */
/*              should be added                                               */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t readCecIplType(smgrIplTypeEnum &ipl_type)
{
    size_t read_size = sizeof(ipl_type);
    errlHndl_t l_errlHndl = NULL;


    // CEC
    l_errlHndl = UtilReg::read(SMGR_REG_CECIPL_TYPE_KEY,   // FSP IPL type key.
                               &ipl_type,                  // Read buffer.
                               read_size,                  // Number of bytes read
                               false);                     // Don't allow a size mismatch.


    return l_errlHndl;
} // END errlHndl_t readCecIplType(...)


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       dump_hex                                                      */
/*                                                                            */
/*  Function:   dump hex data to screen                                       */
/*                                                                            */
/*  Notes:      used by tmgtclient                                            */
/*                                                                            */
/* End Function Specification *************************************************/
#define DUMP_HEX_MAX_SIZE 4096
void dump_hex(const void *data, uint32_t size, const char *header)
{
    uint32_t ii, len;
    const uint8_t *data_ptr = (const uint8_t*)data;

    len = size;
    if (size > DUMP_HEX_MAX_SIZE)
    {
        len = DUMP_HEX_MAX_SIZE;
    }

    if (header)
    {
        printf("%s (%d bytes)", header, size);
    }

    for (ii = 0; ii < len; ii++)
    {
        if (ii % 16 == 0)
        {
            printf("\n");
            printf("%04X: ", ii);
        }
        if (ii % 4 == 0) printf(" ");
        printf("%02X", data_ptr[ii]);
    }
    printf("\n");
}




/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       current_occ_state                                             */
/*                                                                            */
/*  Function:   Returns current OCC state                                     */
/*                                                                            */
/*  Thread:     energyscale                                                   */
/*                                                                            */
/* End Function Specification *************************************************/
occStateId current_occ_state()
{
    errlHndl_t l_errlHndl = NULL;
    occStateId l_occ_state = OCC_STATE_NO_CHANGE;

    // Read OCC state from registry
    UtilRegX<uint32_t> l_reg_state(TMGT_currentState);
    l_errlHndl = l_reg_state.read(NULL);
    if (NULL == l_errlHndl)
    {
        l_occ_state = (occStateId)l_reg_state.getData();
    }
    else
    {
        TMGT_ERR("Failure reading registry: tmgt/currentState");
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, ERRL_ACTION_HIDDEN);
    }

    return l_occ_state;

} // end current_occ_state()




/**
 * @brief Add a user details section to an error log containing information about a network message.
 *
 * @pre   None
 * @post  None
 *
 * @param i_errl - The error log to be appended to.
 * @param i_msg  - The NETC network message object.
 *
 * @return None
 */
void tmgtAddUsrDtls_msg(errlHndl_t i_errl,
                        const NetcMessage& i_msg,
                        const tmgtThreadType i_thread,
                        const uint8_t i_node)
{
    if (i_errl != NULL)
    {
        struct tmgtMsgUsrDtls
        {
            uint16_t type;
            uint16_t length;
            uint8_t occ;
            uint8_t node;
            uint8_t thread;
            uint8_t reserved;
            char data[40];
        } l_dtls = { i_msg.getFunction(), (uint16_t)i_msg.dataLength(), /*OCC*/ (uint8_t)i_msg.getOperation(), i_node, i_thread };

        uint32_t l_len = MIN(l_dtls.length, sizeof(l_dtls.data));
        if (l_len > 0)
        {
            memcpy( &l_dtls.data, i_msg.getData(), l_len );
        }
        i_errl->addUsrDtls((char*)&l_dtls,
                           sizeof(l_dtls) - (sizeof(l_dtls.data) - l_len),
                           TMGT_COMP_ID,
                           TMGT_VERSION+1,
                           TMGT_MSG_DATA_TRUNCATED);
    }
}


/**
 * @brief Read 8 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[out] o_value        Value read from registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if read was successful
 *
 */
bool read_uint8_reg(const char *i_reg, uint8_t & o_value, const errlActions i_severity)
{
    errlHndl_t l_errlHndl = NULL;
    bool success = TRUE;

    UtilRegX<uint8_t> l_reg(i_reg);
    l_errlHndl = l_reg.read();
    if (NULL == l_errlHndl)
    {
        o_value = l_reg.getData();
    }
    else
    {
        success = FALSE;
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_uint8_reg: Failure reading %s", i_reg);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, i_severity);
    }

    return success;
}

/**
 * @brief Write 8 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[in]  i_value        Value to write to registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if write was successful
 *
 */
bool write_uint8_reg(const char *i_reg, const uint8_t & i_value, const errlActions i_severity)
{
    errlHndl_t l_errlHndl = NULL;
    bool success = TRUE;

    UtilRegX<uint8_t> l_reg(i_reg);
    l_errlHndl = l_reg.write(i_value);
    if (l_errlHndl)
    {
        success = FALSE;
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_uint8_reg: Failure writing %s to 0x%04X", i_reg, i_value);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, i_severity);
    }

    return success;
}

/**
 * @brief Read 16 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[out] o_value        Value read from registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if read was successful
 *
 */
bool read_uint16_reg(const char *i_reg, uint16_t & o_value, const errlActions i_severity)
{
    errlHndl_t l_errlHndl = NULL;
    bool success = TRUE;

    UtilRegX<uint16_t> l_reg(i_reg);
    l_errlHndl = l_reg.read();
    if (NULL == l_errlHndl)
    {
        o_value = l_reg.getData();
    }
    else
    {
        success = FALSE;
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_uint16_reg: Failure reading %s", i_reg);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, i_severity);
    }

    return success;
}

/**
 * @brief Write 16 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[in]  i_value        Value to write to registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if write was successful
 *
 */
bool write_uint16_reg(const char *i_reg, const uint16_t & i_value, const errlActions i_severity)
{
    errlHndl_t l_errlHndl = NULL;
    bool success = TRUE;

    UtilRegX<uint16_t> l_reg(i_reg);
    l_errlHndl = l_reg.write(i_value);
    if (l_errlHndl)
    {
        success = FALSE;
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_uint16_reg: Failure writing %s to 0x%04X", i_reg, i_value);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, i_severity);
    }

    return success;
}

/**
 * @brief Read 32 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[out] o_value        Value read from registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if read was successful
 *
 */
bool read_uint32_reg(const char *i_reg, uint32_t & o_value, const errlActions i_severity)
{
    errlHndl_t l_errlHndl = NULL;
    bool success = TRUE;

    UtilRegX<uint32_t> l_reg(i_reg);
    l_errlHndl = l_reg.read();
    if (NULL == l_errlHndl)
    {
        o_value = l_reg.getData();
    }
    else
    {
        success = FALSE;
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_uint32_reg: Failure reading %s", i_reg);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, i_severity);
    }

    return success;
}

/**
 * @brief Write 32 bit registry key
 *
 * @param[in]  i_reg          Registry key string
 * @param[in]  i_value        Value to write to registry
 * @param[in]  i_severity     Severity of error handle to commit if registry error (optional)
 *
 * @return TRUE if write was successful
 *
 */
bool write_uint32_reg(const char *i_reg, const uint32_t & i_value, const errlActions i_severity)
{
    errlHndl_t l_errlHndl = NULL;
    bool success = TRUE;

    UtilRegX<uint32_t> l_reg(i_reg);
    l_errlHndl = l_reg.write(i_value);
    if (l_errlHndl)
    {
        success = FALSE;
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_uint32_reg: Failure writing %s to 0x%08X", i_reg, i_value);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, i_severity);
    }

    return success;
}

/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       getTmgtAppletOpRef                                            */
/*                                                                            */
/*  Function:   Common setup to get Hardware Server TMGT applet object        */
/*              reference                                                     */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/* End Function Specification *************************************************/
TmgtApplet_var *getTmgtAppletOpRef()
{
    TmgtApplet_var* l_pTmgtAppletObj = NULL;
    // HWSV tmgt applet object
    // To preserve the state of this object for subsequent use, this object
    // is defined as global; Otherwise,we need to create this object every time
    // and it is expensive
    static TmgtApplet_var L_TmgtAppletObj;
    static forb::AppClient* L_pHwsvSrvObj = NULL;

    //NOTE: Mutex is not used as only possible case that could cause the
    // problem is single process two threads accessing this routine at the
    //same time. Checking/operating on mutex makes this call heavy with
    // regards to memory/execution. So we can add it later if needed.
    if (CORBA::is_nil(L_TmgtAppletObj))
    {
        if (NULL == L_pHwsvSrvObj)
        {
            L_pHwsvSrvObj = new forb::AppClient(HWSV_SRVR, forb::LOCAL_FSP);
        }

        errlHndl_t l_err = NULL;

        // Server object is successfully created so try to get
        // reference to the Tmgt Applet object.
        l_err = L_pHwsvSrvObj->getObjectRef<TmgtApplet, TmgtApplet_var> (L_TmgtAppletObj, TmgtApplet::TMGTAPPLET_OBJ_NM);
        if (NULL != l_err)
        {
            TMGT_ERR("getTmgtAppletOpRef: Error returned getting Tmgt Applet object reference:"
                     "RC: 0x%04X, serverNm:%s, ObjectNm:%s",
                     l_err->getRC(), HWSV_SRVR, TmgtApplet::TMGTAPPLET_OBJ_NM);
            if (IS_HWSV_ABORT(l_err))
            {
                // HWSV is aborting, noting more we can do
                delete l_err;
                l_err = NULL;
            }
            else
            {
                l_err->CollectTrace(TMGT_COMP_NAME);
                tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            }
        }
        else
        {
            l_pTmgtAppletObj = &L_TmgtAppletObj;
        }
    }
    else
    {
        l_pTmgtAppletObj = &L_TmgtAppletObj;
    }
    // end valid object check

    return l_pTmgtAppletObj;

} // end getTmgtAppletOpRef()



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       validate_ffo_freq                                             */
/*                                                                            */
/*  Function:   Ensure specified FFO frequency is within valid limits         */
/*                                                                            */
/*  Thread:     client, applet                                                */
/*                                                                            */
/*  Notes:      Returns NULL on success, else error handle                    */
/*                                                                            */
/*  Flow:   08/07/13    FN=validate_ffo_freq.odg                              */
/*                                                                            */
/* End Function Specification *************************************************/
errlHndl_t validate_ffo_freq(const uint16_t i_ffo_freq)
{
    errlHndl_t l_err = NULL;

    ::CORBA::ULong l_nominal_freq = 0;
    ::CORBA::ULong l_turbo_freq = 0;
    ::CORBA::ULong l_min_freq = 0;
    ::CORBA::ULong l_sps_freq = 0;
    ::CORBA::ULong l_ultra_turbo_freq = 0;
    ::CORBA::ULong l_ffo_freq = 0;
    ::CORBA::ULong l_reserved = 0;
    // Get object reference
    TmgtApplet_var *l_pTmgtAppletObj = getTmgtAppletOpRef();
    // Check if object reference exists
    if (NULL != l_pTmgtAppletObj)
    {
        // Determine supported frequencies
        (*l_pTmgtAppletObj)->tmgtAppGetFrequencies(l_nominal_freq,
                                                   l_min_freq,
                                                   l_sps_freq,
                                                   l_turbo_freq,
                                                   l_ultra_turbo_freq,
                                                   l_ffo_freq,
                                                   l_reserved);

        if (l_nominal_freq > 0)
        {
            bool l_invalid_freq = FALSE;

            if ((l_min_freq > 0) && (i_ffo_freq < l_min_freq))
            {
                l_invalid_freq = TRUE;
                TMGT_ERR("validate_ffo_freq: Requested FFO frequency (%d) is < min freq (%d)",
                         (uint16_t)i_ffo_freq, (uint16_t)l_min_freq);
            }
            else if (i_ffo_freq > MAX(l_turbo_freq, l_nominal_freq))
            {
                l_invalid_freq = TRUE;
                TMGT_ERR("validate_ffo_freq: Requested FFO frequency (%d) is > max freq (%d)",
                         (uint16_t)i_ffo_freq, (uint16_t)MAX(l_turbo_freq, l_nominal_freq));
            }

            if (l_invalid_freq)
            {
                /*@
                 * @errortype
                 * @refcode LIC_REFCODE
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode TMGT_RC_PARAMETER_OUT_OF_RANGE
                 * @moduleid TMGT_SET_CUST_REQUESTED_MODE
                 * @userdata1 ffo_freq
                 * @userdata2 min_freq
                 * @userdata3 turbo_freq
                 * @userdata4 nominal_freq
                 * @devdesc FFO frequency is not valid
                 */
                tmgtBldErrLog(l_err, TMGT_SET_CUST_REQUESTED_MODE, TMGT_RC_PARAMETER_OUT_OF_RANGE,
                              i_ffo_freq, l_min_freq, l_turbo_freq, l_nominal_freq, ERRL_SEV_INFORMATIONAL);
            }
        }

        if (NULL == l_err)
        {
            const ::CORBA::ULong l_freq = i_ffo_freq;
            HWSV::RequestContext l_context(TMGT_COMP_ID);
            l_err = (*l_pTmgtAppletObj)->tmgtAppWriteAttr(l_context, TARGETING::ATTR_FFO_FREQ_MHZ, l_freq);
            if (NULL == l_err)
            {
                const uint8_t l_success = 1;
                l_err = EvenMgt::signal(EVEN_ID_CURRENT_VOLT_SETTING,&l_success,1,
                                        EVEN_WAIT,EVEN_DAEMON_WAIT_DEFAULT);
                if (l_err != NULL)
                {
                    TMGT_ERR("validate_ffo_freq: Unable to send signal EVEN_ID_CURRENT_VOLT_SETTING");
                    tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
                }
            }
        }
    }
    else
    {
        TMGT_INF("validate_ffo_freq: TMGT applet not ready yet");
    }

    return l_err;
} // end validate_ffo_freq()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       remove_files_with_wildcard                                    */
/*                                                                            */
/*  Function:   Remove files with wildcard                                    */
/*                                                                            */
/*  Thread:     applet                                                        */
/*                                                                            */
/* End Function Specification *************************************************/
uint32_t remove_files_with_wildcard(std::string i_path, std::string i_pattern)
{
    errlHndl_t l_err = NULL;
    struct dirent **l_namelist = NULL;
    int l_files_count = 0;
    int l_count = 0;

    l_count = scandir(i_path.c_str(), &l_namelist, 0, alphasort);

    if (l_count > 0)
    {
        while (l_count--)
        {
            // If match?
            if (!fnmatch(i_pattern.c_str(), l_namelist[l_count]->d_name, 0))
            {
                std::string l_full_file_name = i_path + "/" + l_namelist[l_count]->d_name;
                l_err = UtilFile::remove(l_full_file_name.c_str());
                if(l_err)
                {
                    tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
                    TMGT_ERR("remove_files_with_wildcard: Can't delete file (%s)", l_full_file_name.c_str());
                }
                else
                {
                    TMGT_INF("remove_files_with_wildcard: Delete file (%s)", l_full_file_name.c_str());
                    l_files_count++;
                }
            }

            free(l_namelist[l_count]);
         }
        free(l_namelist);
    }
    return l_files_count;
}


/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:       read_smgr_state                                                 */
/*                                                                              */
/*  Function:   Read smgr/StateData and return CurrentState                     */
/*                                                                              */
/*  Thread:     tmgt server                                                     */
/*                                                                              */
/*  Flow:       Returns SMGR_NO_STATE on registry failure                       */
/*                                                                              */
/* End Function Specification ***************************************************/
smgrStateEnum read_smgr_state()
{
    smgrStateData_t l_smgr_data;
    errlHndl_t l_errlHndl = NULL;

    l_smgr_data.CurrentState = SMGR_NO_STATE;

    // Read current State from StateData registry
    UtilRegX<smgrStateData_t> l_reg_state_data(SMGR_REG_STATE_DATA_KEY);
    l_errlHndl = l_reg_state_data.read(NULL);
    if (NULL == l_errlHndl)
    {
        l_smgr_data = (smgrStateData_t)l_reg_state_data.getData();
    }
    else
    {
        // Commit any errors reading registry as reportable and assume not runtime
        TRACFCOMP(g_tmgtTraceDesc,ERR_MRK"read_smgr_state: Failure reading registry: %s", SMGR_REG_STATE_DATA_KEY);
        tmgtCmtErrLogWithNoSeverityChange(l_errlHndl, ERRL_ACTION_REPORT);
    }

    return l_smgr_data.CurrentState;
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       read_proc_ccin                                                */
/*                                                                            */
/*  Function:   Call SVPD to determine the CCIN of one processor              */
/*                                                                            */
/*  Thread:     client, server                                                */
/*                                                                            */
/*  Notes:      Returns TRUE if CCIN was found and o_ccin will contain        */
/*              null terminated CCIN (5 bytes)                                */
/*              Returns FALSE on error and o_ccin will contain "0" (2 bytes)  */
/*              Elogs will be committed as Info/Hidden                        */
/*                                                                            */
/* End Function Specification *************************************************/
bool read_proc_ccin(char * o_ccin)
{
    uint32_t   l_max_rids = 0;
    uint32_t   l_ccin_reg = 0;
    errlHndl_t l_errlHndl = NULL;
    bool       l_rc = 0;
    char       l_ccin[5] = {0};
    bool       o_found = FALSE;

    o_ccin[0] = '0';
    o_ccin[1] = '\0';

    l_rc = read_uint32_reg(TMGT_procCCIN, l_ccin_reg, ERRL_ACTION_HIDDEN);

    // If CCIN registry contains the CCIN then use it.
    if ((l_rc == TRUE) && (l_ccin_reg != 0))
    {
        o_found = TRUE;
        memcpy(o_ccin, (uint8_t *)&l_ccin_reg, 4);
        o_ccin[4] = '\0';
    }
    else
    {
        l_errlHndl = SVPD_get_max_number_of_RIDs(FRU_PF, l_max_rids);
        if ((NULL == l_errlHndl) && (l_max_rids > 0))
        {
            uint32_t l_RID_array_len = l_max_rids;
            uint32_t l_RID_array_ptr[l_max_rids];

            l_errlHndl = SVPD_get_RID_numbers(FRU_PF, TRUE, l_max_rids, l_RID_array_len, l_RID_array_ptr);
            if (NULL == l_errlHndl)
            {
                uint32_t l_fieldLength;

                for( uint32_t index = 0; index < l_RID_array_len; index++ )
                {
                    l_errlHndl = SVPD_findkeywordData( l_RID_array_ptr[index], sizeof(l_ccin),
                                             (uint8_t *)"CC", (uint8_t *)&l_ccin, l_fieldLength );
                    if ((NULL == l_errlHndl) && (l_fieldLength == 4))
                    {
                        o_found = TRUE;
                        memcpy(o_ccin, &l_ccin, 4);
                        o_ccin[4] = '\0';

                        // write CCIN to registry
                        l_ccin_reg = UINT32_GET(l_ccin);
                        write_uint32_reg(TMGT_procCCIN, l_ccin_reg, ERRL_ACTION_HIDDEN);

                        // Only need to return one CCIN, since mixed processors are not supported
                        break;
                    }
                    else
                    {
                        if (l_errlHndl)
                        {
                            TMGT_ERR("read_proc_ccin: Unable to get FRU_PF CCIN of RID 0x%08X",
                                        l_RID_array_ptr[index]);
                            /*@
                             * @errortype
                             * @refcode LIC_REFCODE
                             * @subsys EPUB_CEC_HDW_VPD_INTF
                             * @reasoncode TMGT_RC_KEY_WORD_FAIL
                             * @moduleid TMGT_MODID_GET_DEF_FILE_PARMS
                             * @userdata1 RID
                             * @userdata2 index
                             * @devdesc SVPD_findkeywordData failed trying to get FRU_PF CCIN
                             */
                             tmgtBldErrLog(l_errlHndl, TMGT_MODID_GET_DEF_FILE_PARMS, TMGT_RC_KEY_WORD_FAIL,
                                            l_RID_array_ptr[index], index, 0, 0, ERRL_SEV_INFORMATIONAL);
                             l_errlHndl->setSubSysId(EPUB_CEC_HDW_VPD_INTF);
                             tmgtCmtErrLog(l_errlHndl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
                        }
                    }
                }
            }
            else
            {
                TMGT_ERR("read_proc_ccin: unable to get FRU_PF RID numbers");
            }
        }
        else
        {
            if (l_errlHndl)
            {
                TMGT_ERR("read_proc_ccin: unable to determine max FRU_PF RIDs");
            }
            else
            {
                TMGT_ERR("read_proc_ccin: SVPD returned max of 0 FRU_PF RIDs!!");
            }
        }
    }


    if (l_errlHndl)
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_CEC_HDW_VPD_INTF
         * @reasoncode TMGT_RC_VPD_FAIL
         * @moduleid TMGT_MODID_GET_DEF_FILE_PARMS
         * @userdata1 max rids
         * @devdesc SVPD call failed attempting to find rids for specified FRU
         */
         l_errlHndl->setSubSysId(EPUB_CEC_HDW_VPD_INTF);
         tmgtBldErrLog(l_errlHndl, TMGT_MODID_GET_DEF_FILE_PARMS, TMGT_RC_VPD_FAIL,
                  l_max_rids, 0, 0, 0, ERRL_SEV_INFORMATIONAL);
         tmgtCmtErrLog(l_errlHndl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }

    return o_found;

} // end read_proc_ccin()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       read_proc_options                                             */
/*                                                                            */
/*  Function:   Read proc_options information from def file                   */
/*                                                                            */
/*  Thread:     client, server                                                */
/*                                                                            */
/*  Flow:       03/09/15    FN=read_proc_options.odg                          */
/*                                                                            */
/* End Function Specification *************************************************/
void read_proc_options(tmgtProcDefParams_t & o_procOption)
{
    errlHndl_t l_err = NULL;
    char l_proc_ccin[5] = {0};

    // Initialize all the outputs to 0 (no turbo)
    // in case here is an error reading them from def file
    memset(&o_procOption, 0x00, sizeof(o_procOption));

    read_proc_ccin(l_proc_ccin);
    tmgtPwrDef l_def;
    int l_rc = l_def.parse();

    if (l_rc == 0)
    {
        tmgtDataBlock l_block;
        bool block_found = FALSE;

        do
        {
            // Scan all proc options blocks for matching CCIN
            if (l_def.getTableDataBlock("p9_options","CCIN", l_proc_ccin, l_block))
            {   // Read attributes and set to 0 if error
                l_block.flattenAttr("FREQ_MAX", &o_procOption.freqMax,
                                    sizeof(o_procOption.freqMax), FLOAT_T, 0);
                                    l_block.flattenAttr("CORE_DTS_WEIGHT", &o_procOption.raw_core_dts_weight,
                                                        sizeof(o_procOption.raw_core_dts_weight), FLOAT_T, 0);
                                    l_block.flattenAttr("QUAD_DTS_WEIGHT", &o_procOption.raw_quad_dts_weight,
                                                        sizeof(o_procOption.raw_quad_dts_weight), FLOAT_T, 0);
                                    o_procOption.tenths_core_dts_weight = (int) (o_procOption.raw_core_dts_weight * 10);
                                    o_procOption.tenths_quad_dts_weight = (int) (o_procOption.raw_quad_dts_weight * 10);

                block_found = TRUE;
            }

            if (FALSE == block_found)
            {
                if ((l_proc_ccin[0]!= '0') || (l_proc_ccin[1]!= '\0'))
                {   // CCIN was not found, use the default block (CCIN = 0)
                    TMGT_INF("read_proc_options: Unable to find proc option block for CCIN %s, using default",
                              l_proc_ccin);
                    l_proc_ccin[0] = '0';
                    l_proc_ccin[1] = '\0';
                }
                else
                {   // No default block (CCIN = 0) was FOUND!
                    TMGT_ERR("read_proc_options: Unable to find default p9_options block");

                    /*@
                     * @errortype
                     * @refcode    LIC_REFCODE
                     * @subsys     EPUB_FIRMWARE_SP
                     * @reasoncode TMGT_RC_INTERNAL_ERROR
                     * @moduleid   TMGT_MODID_GET_DEF_FILE_PARMS
                     * @userdata4  0
                     * @devdesc    Unable to find p9_options block with CCIN = 0
                     */
                     tmgtBldErrLog(l_err, TMGT_MODID_GET_DEF_FILE_PARMS, TMGT_RC_INTERNAL_ERROR,
                                   0, 0, 0, 0, ERRL_SEV_INFORMATIONAL);
                     l_err->CollectTrace("PWRDEF");
                     tmgtCmtErrLog(l_err, ERRL_SEV_UNRECOVERABLE, ERRL_ACTION_REPORT);
                     block_found = TRUE;
                }
            }
        } while (FALSE == block_found);
    }
    else
    {   // Unable to open def file....
        TMGT_ERR("read_proc_options: Unable to open power_management def file");
        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode TMGT_RC_INTERNAL_ERROR
         * @moduleid   TMGT_MODID_GET_DEF_FILE_PARMS
         * @userdata1  rc
         * @devdesc    Unable to open power_managment def file
         */
        tmgtBldErrLog(l_err, TMGT_MODID_GET_DEF_FILE_PARMS, TMGT_RC_INTERNAL_ERROR,
                    l_rc, 0, 0, 0);
        l_err->CollectTrace("PWRDEF");
        tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }

} // end read_proc_options()

/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       get_proc_def_params                                           */
/*                                                                            */
/*  Function:   Read processor information from the def file and HWSV         */
/*                                                                            */
/*  Thread:     client, server                                                */
/*                                                                            */
/*  Flow:       08/22/13    FN=get_proc_def_params.odg                        */
/*                                                                            */
/* End Function Specification *************************************************/
void get_proc_def_params(tmgtProcDefParams_t & o_procParams)
{
    //Get processor options
    read_proc_options(o_procParams);

#define FRAC(f) ( int((f - int(f)) * 100.0) )

    TMGT_INF("get_proc_def_params: FREQ_MAX=%d.%02d",
             int(o_procParams.freqMax), FRAC(o_procParams.freqMax));

} // end get_proc_def_params()

/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       get_system_type                                               */
/*                                                                            */
/*  Function:   Returns system type from system model                         */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/*  Note:       For tmgt/toif threads, use G_system_type global instead of    */
/*              calling this function.                                        */
/*                                                                            */
/* End Function Specification *************************************************/
uint8_t get_system_type(void)
{
    uint8_t l_sysType = 0;
    fwdbresult l_table("select * from sys.im");
    errlHndl_t l_errlHndl = l_table.getErrl();
    if (l_errlHndl)
    {
        TMGT_ERR("get_system_type: Unable to get system type from system model (rc=0x%04X)", l_errlHndl->getRC());
        l_errlHndl->CollectTrace(TMGT_COMP_NAME);
        tmgtCmtErrLog(l_errlHndl, ERRL_SEV_UNRECOVERABLE, ERRL_ACTION_REPORT);
    }
    else
    {
        if ( 1 == l_table.numRows() )
        {
            const std::string l_sys_string(l_table[0]["type"].getString());
            if (0 == l_sys_string.compare("SINGLEDRAWER"))
            {
                l_sysType = SYSTYPE_SINGLE_NODE;
            }
            else if (0 != l_sys_string.compare("MULTIDRAWER"))
            {
                TMGT_ERR("get_system_type: Unknown system type %s", l_sys_string.c_str());
                /*@
                 * @errortype
                 * @refcode LIC_REFCODE
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode TMGT_RC_SYS_MODEL_ERROR
                 * @moduleid TMGT_MODID_GET_SYS_TYPE
                 * @userdata1 0
                 * @userdata2 0
                 * @userdata3 0
                 * @userdata4 0
                 * @devdesc Unknown system type
                 */
                tmgtBldErrLog(l_errlHndl, TMGT_MODID_GET_SYS_TYPE, TMGT_RC_SYS_MODEL_ERROR,
                              0, 0, 0, 0);
                tmgtCmtErrLog(l_errlHndl, ERRL_SEV_UNRECOVERABLE, ERRL_ACTION_REPORT);
            }

            if (kvm_enabled())
            {
                l_sysType |= SYSTYPE_KVM;
            }
        }
        else
        {
            TMGT_ERR("get_system_type: Unable to identify system type from system model (rows=%d)", l_table.numRows());
            /*@
             * @errortype
             * @refcode LIC_REFCODE
             * @subsys EPUB_FIRMWARE_SP
             * @reasoncode TMGT_RC_SYS_MODEL_ERROR
             * @moduleid TMGT_MODID_GET_SYS_TYPE
             * @userdata1 size
             * @userdata2 0
             * @userdata3 0
             * @userdata4 1
             * @devdesc Unable to identify system type
             */
            tmgtBldErrLog(l_errlHndl, TMGT_MODID_GET_SYS_TYPE, TMGT_RC_SYS_MODEL_ERROR,
                          l_table.numRows(), 0, 0, 1);
            tmgtCmtErrLog(l_errlHndl, ERRL_SEV_UNRECOVERABLE, ERRL_ACTION_REPORT);
        }
    }

    return l_sysType;

} // end get_system_type()



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       get_max_nodes                                                 */
/*                                                                            */
/*  Function:   Returns true max nodes from system model                      */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/* End Function Specification *************************************************/
uint8_t get_max_nodes(void)
{
    uint8_t l_nodes = 0;
    fwdbresult l_table("select count(it.nid) from instance_table it, part_table pt where pt.class = 'enc' and pt.type = 'cec' and it.pid = pt.id");
    errlHndl_t l_errlHndl = l_table.getErrl();
    if (l_errlHndl)
    {
        TMGT_ERR("get_max_nodes: Unable to true max node number from system model (rc=0x%04X)", l_errlHndl->getRC());
        l_errlHndl->CollectTrace(TMGT_COMP_NAME);
        tmgtCmtErrLog(l_errlHndl, ERRL_SEV_UNRECOVERABLE, ERRL_ACTION_REPORT);
    }
    else
    {
        if ( 1 == l_table.numRows() )
        {
            l_nodes = l_table[0]["count(it.nid)"].getUint8();
            if (0 == l_nodes)
            {
                TMGT_ERR("get_max_nodes: read 0 from system model for true max node");
            }
            if (l_nodes > TMGT_MAX_NUMBER_OF_NODES)
            {
                TMGT_ERR("get_max_nodes: max nodes from SM %d exceedes TMGT max %d", l_nodes, TMGT_MAX_NUMBER_OF_NODES);
                l_nodes = TMGT_MAX_NUMBER_OF_NODES;
            }
        }
        else
        {
            // should not happen, since we use count() to count total number
            TMGT_ERR("get_max_nodes: Unable to identify true max node number from system model (rows=%d)", l_table.numRows());
        }
    }

    if (0 == l_nodes)
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode TMGT_RC_SYS_MODEL_ERROR
         * @moduleid TMGT_MODID_GET_MAX_NODES
         * @userdata1 0
         * @userdata2 0
         * @userdata3 0
         * @userdata4 0
         * @devdesc Unable to identify true max nodes
         */
        SrciSrc l_src(SRCI_ERR_INFO, SRCI_NO_ATTR, TMGT_MODID_GET_MAX_NODES, LIC_REFCODE, TMGT_RC_SYS_MODEL_ERROR);
        l_errlHndl = new ErrlEntry(TMGT_COMP_ID, ERRL_SEV_UNRECOVERABLE, ERRL_ETYPE_NOT_APPLICABLE, l_src);
        l_errlHndl->CollectTrace(TMGT_COMP_NAME);
        l_errlHndl->commit(TMGT_COMP_ID, ERRL_ACTION_REPORT);
        // cleanup
        delete l_errlHndl;
        l_errlHndl = NULL;
    }

    return l_nodes;
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       os_ready_for_requests                                         */
/*                                                                            */
/*  Function:   Returns TRUE if OS is ready for us to send MBOX command       */
/*              to load or reset the OCCs                                     */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/* End Function Specification *************************************************/
bool os_ready_for_requests()
{
    static bool L_ready = FALSE;

    const smgrStateEnum l_smgrState = read_smgr_state();
    if (SMGR_RUNTIME == l_smgrState)
    {
        uint8_t l_phypState = 0;
        read_uint8_reg("iplp/SysPhypCurrentState", l_phypState, ERRL_ACTION_HIDDEN);
        if (0 != l_phypState)
        {
            if (FALSE == L_ready)
            {
                TMGT_INF("os_ready_for_requests: OS is ready (iplp/SysPhypCurrentState=0x%02X)", l_phypState);
                L_ready = TRUE;
            }
        }
        else
        {
            if (L_ready)
            {
                TMGT_INF("os_ready_for_requests: OS is NOT ready (iplp/SysPhypCurrentState=0x%02X)", l_phypState);
                L_ready = FALSE;
            }
        }
    }
    else
    {
        if (L_ready)
        {
            TMGT_INF("os_ready_for_requests: OS is NOT ready (SMGR State=0x%02X)", l_smgrState);
            L_ready = FALSE;
        }
    }

    static bool L_throttled = FALSE;
    if (int_flags_set(FLAG_SKIP_MBOX_CALLS))
    {
        // Do not need to wait for PHYP, since no MBOX calls
        if (!L_throttled)
        {
            TMGT_INF("os_ready_for_requests: Force OS Ready due to FLAG_SKIP_MBOX_CALLS");
            L_throttled = TRUE;
        }
        return TRUE;
    }
    else
    {
        L_throttled = FALSE;
    }

    return L_ready;
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       update_internal_flags                                         */
/*                                                                            */
/*  Function:   Update tmgt/internalFlags as required                         */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/*  Flow:   03/03/14    FN=update_internal_flags.odg                          */
/*                                                                            */
/* End Function Specification *************************************************/
void update_internal_flags()
{
    bool l_avp_enabled = FALSE;
    errlHndl_t l_err = NULL;
    uint32_t l_flags = 0;

    read_uint32_reg(TMGT_internalFlags, l_flags, ERRL_ACTION_HIDDEN);
    TMGT_INF("update_internal_flags: tmgt/internalFlags=0x%08X", l_flags);

    // TMGT will not update internalFlags if EXTERNAL_OVERRIDE flag is set
    if (0 == (FLAG_EXTERNAL_OVERRIDE & l_flags))
    {
        l_err = mnfgIsPolicyFlagSet(MNFG_AVP_ENABLE, l_avp_enabled);
        if (l_err != NULL)
        {
            tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            l_avp_enabled = FALSE;
        }
        if (l_avp_enabled != TRUE)
        {
            l_err = mnfgIsPolicyFlagSet(MNFG_HDAT_AVP_ENABLE, l_avp_enabled);
            if (l_err != NULL)
            {
                tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
                l_avp_enabled = FALSE;
            }
        }

        if (l_avp_enabled)
        {
            // Set AVP required flags (HostBoot does load, resets not allowed, and terminate on errors)
            l_flags |= AVP_FLAGS;
        }
        else
        {
            // Disable AVP flags
            l_flags &= ~(AVP_FLAGS);
        }

        bool l_disableOccs = FALSE;
        // Determine if OCC should be disabled due to proc EC level
        TmgtApplet_var *l_pTmgtAppletObj = getTmgtAppletOpRef();
        if (NULL != l_pTmgtAppletObj)
        {
            // Determine supported frequencies
            (*l_pTmgtAppletObj)->tmgtAppOccIsDisabled(l_disableOccs);
            if (l_disableOccs)
            {
                TMGT_INF("Disabling OCCs due to unsupported processor EC");
            }
        }
        else
        {
            TMGT_ERR("update_internal_flags: Unable to query HWVS for OCC support (pTmgtAppletObj=NULL)");
        }
        if (l_disableOccs)
        {
            l_flags |= FLAG_HOLD_OCCS_IN_RESET;
        }
        else
        {
            l_flags &= ~FLAG_HOLD_OCCS_IN_RESET;
        }

        // Enable Memory Throttling by default (clear DISABLE_MEM_THROTTLE)
        l_flags &= ~FLAG_DISABLE_MEM_THROTTLE;

        TMGT_INF("update_internal_flags: Updating tmgt/internalFlags to 0x%08X", l_flags);
        write_uint32_reg(TMGT_internalFlags, l_flags, ERRL_ACTION_HIDDEN);
    }
    // else, unable to update flags

} // end update_internal_flags()


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       int_flags_set                                                 */
/*                                                                            */
/*  Function:   Returns TRUE if specified flags are all set in                */
/*              tmgt/internalFlags registry key.                              */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/* End Function Specification *************************************************/
bool int_flags_set(const uint32_t i_mask)
{
    bool flags_are_set = FALSE;

    uint32_t l_flags = 0;
    read_uint32_reg(TMGT_internalFlags, l_flags, ERRL_ACTION_HIDDEN);

    if ((l_flags & i_mask) == i_mask)
    {
        flags_are_set = TRUE;
    }

    return flags_are_set;
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       mfg_use_min_for_ps                                            */
/*                                                                            */
/*  Function:   Returns TRUE if mnfg flag is set indicating that they want    */
/*              Power Save mode to use the min frequency.                     */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/* End Function Specification *************************************************/
bool mfg_use_min_for_ps()
{
    bool l_use_min = FALSE;

    errlHndl_t l_err = mnfgIsPolicyFlagSet(MNFG_POWER_SAVE_CAPABLE, l_use_min);
    if (l_err != NULL)
    {
        l_use_min = FALSE;
        tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }

    return l_use_min;
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       kvm_enabled                                                   */
/*                                                                            */
/*  Function:   Returns TRUE if KVM has been enabled (through ASM)            */
/*              and mnfg didn't disable opal mode.                            */
/*                                                                            */
/*  Thread:     Should support all threads                                    */
/*                                                                            */
/* End Function Specification *************************************************/
bool kvm_enabled()
{
    bool l_kvm_enabled = FALSE;

    uint8_t l_hyp_mode = 0;
    read_uint8_reg("menu/HypMode", l_hyp_mode, ERRL_ACTION_HIDDEN);

    if ( 0x03 == l_hyp_mode )
    {
        uint8_t l_mfg_opal_mode = 0;
        read_uint8_reg(TMGT_mnfgOpalMode, l_mfg_opal_mode, ERRL_ACTION_HIDDEN);

        if (l_mfg_opal_mode == 0x01)
        {
            l_kvm_enabled = TRUE;
        }
    }

    return l_kvm_enabled;
}

/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       get_fan_control_fru_info                                      */
/*                                                                            */
/*  Function:   Read fan control information from def file                    */
/*                                                                            */
/*  Thread:     client, server                                                */
/*                                                                            */
/*  Flow:       09/22/13    FN=get_fan_control_def_params.odg                 */
/*                                                                            */
/* End Function Specification *************************************************/
uint8_t get_fan_control_fru_info(std::vector<tctConfigDataSet_t> &o_data)
{
    TMGT_INF("get_fan_control_fru_info: start" );

    uint8_t     l_rc = 0;

    errlHndl_t  l_errl = NULL;
    tmgtPwrDef  l_def;

    int         l_defRc = l_def.parse();

    if ( l_defRc == 0 )
    {
        tmgtDataBlock       l_block;
        bool                l_notFound = FALSE;

        static const char   l_fanControlLoopTime[] = "FAN_CONTROL_LOOP_TIME";

        // Scan for fan control overall
        if ( l_def.getTableDataBlock( "fan_control_overall", l_fanControlLoopTime, l_rc, l_block) )
        {
            l_block.flattenAttr( l_fanControlLoopTime, &l_rc, sizeof(l_rc), UINT8_T, 0);

            if ( l_rc == 0 )
            {
                // No fan control overall found  or bad data?
                TMGT_ERR("get_fan_control_Fru_info: Unable to find %s", "fan_control_overall");

                l_notFound = TRUE;
            }
            else
            {
                TMGT_INF("get_fan_control_fru_info: fan control loop time = %d", l_rc );
            }
        }
        else
        {
            TMGT_ERR("get_fan_control_Fru_info: Unable to find %s", "fan_control_overall");

            // not able to find fan control overall block!!!
            l_notFound = TRUE;
        }


        if ( l_notFound )
        {
                /*@
                 * @errortype
                 * @refcode    LIC_REFCODE
                 * @subsys     EPUB_FIRMWARE_SP
                 * @reasoncode TMGT_RC_INTERNAL_ERROR
                 * @moduleid   TMGT_MODID_GET_FAN_CONTROL_FRU_INFO
                 * @devdesc    Unable to find fan control overall block
                 */
                 tmgtBldErrLog( l_errl,
                                TMGT_MODID_GET_FAN_CONTROL_FRU_INFO,
                                TMGT_RC_INTERNAL_ERROR,
                                0,
                                0,
                                0,
                                0,
                                ERRL_SEV_INFORMATIONAL);

                 l_errl->CollectTrace("PWRDEF");
                 l_errl->CollectTrace(TMGT_COMP_NAME);

                 tmgtCmtErrLog(l_errl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_REPORT);
        }


        // Proceed to lok for can control fru specific blocks

        // FRU Type
        // NOTE: make sure index to fru type matches
        //       value to be return to occ
        //       ex: VRM is always at index 3 --> l_SupportedFRUs[0x03]
        //           see TMGT to OCC spec for more info
        static const char * l_SupportedFRUs[] = {
            "P9",                           // Processor
            "CENTAUR",                      // Centaur
            "DIMM",                         // DIMM
            "VRMS",                         // VRMs
            NULL,                           // Not used
            NULL,                           // Not used
            "VRM_VDD"                       // VRM Vdd
            };


        // reuse tmgtDataBlock
        l_block.purge();

        // walk through fan control blocks found in def file
        // will only save off ONLY what is supported (see l_SupportedFRUs)
        int l_block_index = 0;
        while ( (l_def.getDataBlock("fan_control_fru", l_block_index, NULL, &l_block) != 0) )
        {
            // Locals
            const char *        l_type = l_block.getAttrStr("NAME");
            bool                l_supportedType = FALSE;
            uint32_t            l_x = 0;
            tctConfigDataSet_t  l_tmp_data;

            for (l_x=0; l_x< (sizeof(l_SupportedFRUs)/sizeof(l_SupportedFRUs[0])); l_x++)
            {
                // Skip unused indexes and look for match
                if ((l_SupportedFRUs[l_x] != NULL) && (strcmp( l_type, l_SupportedFRUs[l_x]) == 0))
                {
                    // break out once we find a supported fru so we can save off info
                    l_supportedType = TRUE;
                    break;
                }
            }

            if ( l_supportedType )
            {
                // note: we need to save off block info and use l_x as index to
                //       know which fru we are dealing with
                FlattenSpec l_spec[] = {
                  {"NAME",                  UINT8_T, 0xFF},
                  {"DVFS",                  UINT8_T, 0xFF},
                  {"ERROR",                 UINT8_T, 0xFF},
                  {"PM_DVFS",               UINT8_T, 0xFF},
                  {"PM_ERROR",              UINT8_T, 0xFF},
                  {"MAX_READ_TIMEOUT",      UINT8_T, 0xFF},
                  {0, 0, 0} };

                // save off into into temp structure
                l_block.flatten( &l_tmp_data, sizeof( l_tmp_data ), l_spec );

                //l_block.display( stdout );

                // update fruType based to correct index value
                l_tmp_data.iv_fruType = l_x;

                TMGT_INF("get_fan_control_fru_info: Found FRU Type %s", l_SupportedFRUs[l_x]);

                // save of into user's vector space
                o_data.push_back( l_tmp_data );

            }
            else
            {
                // currently unsupported or maybe bad data?
                // TMGT_INF("get_fan_control_fru_info: Found unsupported FRU Type, ignoring for now" );
            }

            l_block_index++;

        } // while loop

    }
    else
    {
        // Unable to open def file....

        TMGT_ERR("get_fan_control_fru_info: Unable to open power_management def file");

        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode TMGT_RC_PARSER_ERROR
         * @moduleid   TMGT_MODID_GET_FAN_CONTROL_FRU_INFO
         * @userdata1  rc
         * @devdesc    Unable to open power_managment def file
         */
        tmgtBldErrLog(  l_errl,
                        TMGT_MODID_GET_FAN_CONTROL_FRU_INFO,
                        TMGT_RC_PARSER_ERROR,
                        l_defRc,
                        0,
                        0,
                        0);

        l_errl->CollectTrace("PWRDEF");
        l_errl->CollectTrace(TMGT_COMP_NAME);

        tmgtCmtErrLog(l_errl, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
    }

    TMGT_INF("get_fan_control_fru_info: END - l_rc=%d Found %d FRU's", l_rc, o_data.size() );

    return l_rc;
} // end get_fan_control_fru_info()



/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       add_tmgt_elog_data                                            */
/*                                                                            */
/*  Function:   Add TMGT data to specified error log                          */
/*                                                                            */
/*  Thread:     client, ToifNode                                              */
/*                                                                            */
/*  References: tmgt_add_es_user_details.odg                                  */
/*                                                                            */
/* End Function Specification *************************************************/
void add_tmgt_elog_data(errlHndl_t i_err)
{
    if (i_err != NULL)
    {
        errlHndl_t l_err = NULL;

        uint8_t l_cust_mode = 0;
        tmgtSysPwrMode l_current_cust_volt_setting = TMGT_SYS_PWR_MODE_NO_CHANGE;
        tmgtSysPwrMode l_system_req_mode = TMGT_SYS_PWR_MODE_NO_CHANGE;
        tmgtSysPwrMode l_target_mode = TMGT_SYS_PWR_MODE_NO_CHANGE;
        uint32_t l_occ_state = 0;
        uint32_t l_time_in_mode = 0;
        bool l_reg_error = FALSE;
        // Add UsrDetails to the log
        if (!read_uint32_reg(TMGT_currentState, l_occ_state, ERRL_ACTION_HIDDEN))
        {
            l_reg_error = TRUE;
        }

        if (!read_uint32_reg(TMGT_timeInMode, l_time_in_mode, ERRL_ACTION_HIDDEN))
        {
            l_reg_error = TRUE;
        }
        UtilRegX<uint8_t> l_reg_custmode(TMGT_custReqMode);
        l_err = l_reg_custmode.read(NULL);
        if (NULL == l_err)
        {
            l_cust_mode = l_reg_custmode.getData();
        }
        else
        {
            tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            TMGT_ERR("add_tmgt_elog_data: Failure reading registry: tmgt/custReqMode");
            l_reg_error = TRUE;
        }

        l_err = read_mode_reg(TMGT_currentVoltSetting, l_current_cust_volt_setting);
        if (l_err)
        {
            tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            l_reg_error = TRUE;
        }

        l_err = read_mode_reg(TMGT_currentPwrMode, l_system_req_mode);
        if (l_err)
        {
            tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            l_reg_error = TRUE;
        }

        l_err = read_mode_reg(TMGT_targetMode, l_target_mode);
        if (l_err)
        {
            tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            l_reg_error = TRUE;
        }
        ::CORBA::ULong l_nominal_freq = 0;
        ::CORBA::ULong l_min_freq = 0;
        ::CORBA::ULong l_turbo_freq = 0;
        ::CORBA::ULong l_sps_freq = 0;
        ::CORBA::ULong l_ultra_turbo_freq = 0;
        ::CORBA::ULong l_ffo_freq = 0;
        ::CORBA::ULong l_reserved = 0;
        TmgtApplet_var *l_pTmgtAppletObj = getTmgtAppletOpRef();
        if (NULL != l_pTmgtAppletObj)
        {
            (*l_pTmgtAppletObj)->tmgtAppGetFrequencies(l_nominal_freq,
                                                       l_min_freq,
                                                       l_sps_freq,
                                                       l_turbo_freq,
                                                       l_ultra_turbo_freq,
                                                       l_ffo_freq,
                                                       l_reserved);
        }
        if (l_nominal_freq == 0)
        {
            TMGT_INF("add_tmgt_elog_data: Nominal frequency not currently available");
        }

        // Read SMS from P2 to determine if capping enabled
        bool l_capping_enabled = FALSE;
        uint16_t l_sms_control = 0;
        p1_p2_file_item_t l_items[1] = { {TMGT_FILE_SMS_ENCODE} };
        l_items[0].item_name = TMGT_FILE_SMS_ENCODE;
        l_items[0].length = 2;
        l_items[0].node = 0;
        l_err = p1_p2_file_read_data(l_items, 1);
        if (NULL == l_err)
        {
            l_sms_control = UINT16_GET(l_items[0].value);
            if (POWER_CAPPING_ENABLED(l_sms_control))
            {
                l_capping_enabled = TRUE;
            }
        }
        else
        {
            TMGT_ERR("Error from p1_p2_file_read_data(TMGT_FILE_PCAP_FLAGS)");
            tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
        }

        uint16_t l_current_pcap = 0;
        uint16_t l_pcap_max = 0, l_pcap_min = 0, l_pcap_over = 0, l_soft_pcap_min = 0;
        uint16_t l_pcap_turbo = 0, l_dvfs_min_pcap = 0;
        get_pcap_values(0 /*node*/, l_current_pcap, l_pcap_max, l_pcap_min, l_pcap_over,
                        l_soft_pcap_min, l_pcap_turbo, l_dvfs_min_pcap);
        if (FALSE == l_capping_enabled)
        {
            // Use system power cap when customer cap has not been set
            l_current_pcap = l_pcap_max;
        }


        if (l_reg_error)
        {
            // Create the src
            SrciSrc l_src(SRCI_ERR_INFO,
                          SRCI_NO_ATTR,
                          TMGT_MODID_ADD_ES_USER_DETAILS,
                          LIC_REFCODE,
                          TMGT_RC_REGISTRY_READ_FAIL,
                          0, 0, 0, 0);

            // Add the created src
            i_err->addSRC(TMGT_COMP_ID, l_src);
        }

        uint8_t l_data[25];
        unsigned int l_index = 0;
        // modes
        l_data[l_index++] = l_system_req_mode & 0x000000FF;
        l_data[l_index++] = l_target_mode & 0x000000FF;
        l_data[l_index++] = l_cust_mode & 0x000000FF;
        l_data[l_index++] = l_current_cust_volt_setting & 0x000000FF;
        const uint32_t l_time = time(NULL) - l_time_in_mode;
        UINT32_PUT(&l_data[l_index], l_time);
        l_index+= 4;
        // frequencies
        l_data[l_index++] = (uint16_t)l_min_freq >> 8;
        l_data[l_index++] = (uint16_t)l_min_freq & 0x00FF;
        l_data[l_index++] = (uint16_t)l_sps_freq >> 8;
        l_data[l_index++] = (uint16_t)l_sps_freq & 0x00FF;
        l_data[l_index++] = (uint16_t)l_nominal_freq >> 8;
        l_data[l_index++] = (uint16_t)l_nominal_freq & 0x00FF;
        l_data[l_index++] = (uint16_t)l_turbo_freq >> 8;
        l_data[l_index++] = (uint16_t)l_turbo_freq & 0x00FF;
        l_data[l_index++] = (uint16_t)l_ultra_turbo_freq >> 8;
        l_data[l_index++] = (uint16_t)l_ultra_turbo_freq & 0x00FF;
        l_data[l_index++] = (uint16_t)l_ffo_freq >> 8;
        l_data[l_index++] = (uint16_t)l_ffo_freq & 0x00FF;
        // misc
        l_data[l_index++] = l_occ_state & 0x000000FF;
        l_data[l_index++] = l_capping_enabled ? 1 : 0;
        l_data[l_index++] = l_current_pcap >> 8;
        l_data[l_index++] = l_current_pcap & 0x00FF;
        l_data[l_index++] = kvm_enabled() ? 1 : 0;

        i_err->addUsrDtls((char *)l_data, sizeof(l_data),
                           TMGT_COMP_ID,
                           0, /* version */
                           TMGT_ENERGYSCALE_DATA_TYPE);
    }
    else
    {
        TMGT_ERR("add_tmgt_elog_data: NULL error handle");
    }

} // end add_tmgt_elog_data()

/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       add_occ_scoms_data_to_elog                                    */
/*                                                                            */
/*  Function:   Reads given OCC's scom registers and adds the data to the     */
/*              given errorlog handle.                                        */
/*                                                                            */
/*  Thread:     client, tmgtserver                                            */
/*                                                                            */
/* End Function Specification *************************************************/
void add_occ_scom_data(errlHndl_t io_err, uint32_t i_huid)
{
    if (io_err != NULL)
    {
        errlHndl_t                    l_err = NULL;
        TmgtApplet_var               *l_pTmgtAppletObj = getTmgtAppletOpRef();
        TmgtApplet::OccScomTable_var  l_scomTable;
        uint32_t                      l_scomCount = 0;
        errlidx_t                     l_index = io_err->usrDtlCount();
        bool                          l_add_scom_detail = TRUE;

        while ( (l_index > 0) && (l_add_scom_detail == TRUE) )
        {

            errlslen_t      l_dtl_len;
            comp_id_t       l_dtl_compid;
            errlsubsec_t    l_dtl_subsec;
            errlver_t       l_dtl_ver;

            //Make sure we haven't added this user detail yet.
            io_err->getUsrDtls(l_dtl_len, l_dtl_compid, l_dtl_subsec, l_dtl_ver, l_index);

            if ( (TMGT_COMP_ID == l_dtl_compid) &&
                    (TMGT_PROC_SCOM_REGISTERS == l_dtl_subsec) &&
                    (0 == l_dtl_ver) )
            {
                //Scom detail already added.
                TMGT_INF("add_occ_scom_data: Scom Detail already added.");
                l_add_scom_detail = FALSE;
            }

            l_index--;
        }

        if(l_add_scom_detail)
        {
            //Collect scom Values
            l_err = (*l_pTmgtAppletObj)->tmgtAppGetScoms(i_huid, l_scomTable);
            if (l_err == NULL)
            {
                l_scomCount = l_scomTable->rowData.length();
                TMGT_INF("add_occ_scom_data: success reading proc scoms. huid[0x%X] rows count:%i.",
                        i_huid, l_scomCount);
                if(l_scomCount > 0)
                {
                    uint8_t l_scomData[32 + (l_scomCount * sizeof(TmgtApplet::OccScomRow))];
                    memset(l_scomData, 0x00, sizeof(l_scomData));
                    // Write TableName in first 28 bytes.
                    uint8_t l_strLength = strlen(l_scomTable->tableName);
                    memcpy(l_scomData, (char *)l_scomTable->tableName, l_strLength <= 28? l_strLength: 28);
                    // Write huid in the next 4 bytes.
                    memcpy(&(l_scomData[28]),(void *)&i_huid, 4);
                    // Write scom values in the leftover space.  (8 bytes for scom Address, and 8 bytes for scom Value)
                    memcpy(&(l_scomData[32]), (char *)&(l_scomTable->rowData[0]), l_scomCount * sizeof(TmgtApplet::OccScomRow));

                    io_err->addUsrDtls(l_scomData, sizeof(l_scomData), TMGT_COMP_ID, 0/*version*/, TMGT_PROC_SCOM_REGISTERS);
                }

            }
            else
            {
                TMGT_ERR("add_occ_scom_data: FAILED to read scoms. huid[0x%X]", i_huid);
                tmgtCmtErrLog(l_err, ERRL_SEV_INFORMATIONAL, ERRL_ACTION_HIDDEN);
            }
        }
    }
}

const char TMGT_PCI_LOCKFILE[] = "/tmp/tmgt_pcilockfile";

/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       pci_lock                                                      */
/*                                                                            */
/*  Function:   Lock for use when writing tmgt/pciConfigFile or               */
/*              tmgt/pciLookup                                                */
/*                                                                            */
/*  Thread:     client, energyscale                                           */
/*                                                                            */
/* End Function Specification *************************************************/
void pci_lock()
{
    UtilLock l_pcilock(TMGT_PCI_LOCKFILE);
    if (FALSE == l_pcilock.tlock())
    {
        TMGT_INF("pci_lock: Waiting for PCI lock...");
        if (FALSE == l_pcilock.lock())
        {
            TMGT_ERR("pci_lock: PCI lock failed!");
        }
    }
}


/* Function Specification *****************************************************/
/*                                                                            */
/*  Name:       pci_unlock                                                    */
/*                                                                            */
/*  Function:   Unlock for use when writing tmgt/pciConfigFile or             */
/*              tmgt/pciLookup                                                */
/*                                                                            */
/*  Thread:     client, energyscale                                           */
/*                                                                            */
/* End Function Specification *************************************************/
void pci_unlock()
{
    UtilLock l_pcilock(TMGT_PCI_LOCKFILE);
    l_pcilock.unlock();
}


#endif // ifndef _X86NFP
