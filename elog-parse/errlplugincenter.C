/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlplugincenter.H>
#include <errlutility.H>
#include <errlbase.H>
#include <dlfcn.h>


namespace errl {


/*****************************************************************************/
// Constants
/*****************************************************************************/
const uint32_t ERRL_MAX_LIB_NAME    = 20;



    
/*****************************************************************************/
// PluginCenter access
/*****************************************************************************/
PluginCenter * PluginCenter::Instance()
{
    static PluginCenter * l_p = new PluginCenter;
    return l_p;
}



/*****************************************************************************/
// Data Plugin registration
/*****************************************************************************/
void PluginCenter::Register( Plugin & i_plugin )
{
    itr_t   l_itr, l_end;
    bool    l_added = false;

    l_itr = iv_Plugins.begin();
    l_end = iv_Plugins.end();

    while ( l_itr != l_end )
    {
	if ( i_plugin < (**l_itr) )
	{
	    iv_Plugins.insert( l_itr, &i_plugin );
	    l_added = true;
	    break;
	}
	++l_itr;
    }

    if ( l_added == false )
    {
	iv_Plugins.push_back( &i_plugin );
    }
}



/*****************************************************************************/
// Data Plugin deregistration
/*****************************************************************************/
void PluginCenter::Deregister( Plugin & i_plugin )
{
    itr_t   l_itr;

    l_itr = Find( i_plugin );

    if ( l_itr != iv_Plugins.end() )
    {
	iv_Plugins.erase( l_itr );
    }
}

/*****************************************************************************/
// Data plugin parse call
/*****************************************************************************/
bool PluginCenter::LoadPlugin(
    errlCreator i_ssid,
    comp_id_t   i_cid
)
{
  return true;
}

/*****************************************************************************/
// Data plugin parse call
/*****************************************************************************/
bool PluginCenter::CallDataPlugin(
    comp_id_t	    i_cid,
    ErrlUsrParser & i_parser,
    void *	    i_buffer,
    uint32_t	    i_buflen,
    errlver_t	    i_ver,
    errlsubsec_t    i_sst,
    errlCreator     i_ssid
)
{
    bool	l_rc = false;
    itr_t	l_itr;
    DataPlugin	l_Plugin( i_cid, 0, i_ssid );

    l_itr = Find( l_Plugin );

    if ( l_itr != iv_Plugins.end() )
    {
	l_rc = (**l_itr)( i_parser, i_buffer, i_buflen, i_ver, i_sst );
    }

    return l_rc;
}



/*****************************************************************************/
// Src plugin parse call
/*****************************************************************************/
bool PluginCenter::CallSrcPlugin(
    comp_id_t	    i_cid,
    ErrlUsrParser & i_parser,
    const SrciSrc & i_src,
    errlCreator     i_ssid 
)
{
    bool	l_rc = false;
    itr_t	l_itr;
    SrcPlugin	l_Plugin( i_cid, 0, i_ssid );

    l_itr = Find( l_Plugin );

    if ( l_itr != iv_Plugins.end() )
    {
	l_rc = (**l_itr)( i_parser, i_src );
    }

    return l_rc;
}




/*****************************************************************************/
// Mru plugin parse call
/*****************************************************************************/
bool PluginCenter::CallMruPlugin(
    comp_id_t	    i_cid,
    ErrlUsrParser & i_parser,
    uint32_t	    i_mru,
    errlCreator     i_ssid
)
{
    bool	l_rc = false;
    itr_t	l_itr;
    MruPlugin	l_Plugin( i_cid, 0, i_ssid  );

    l_itr = Find( l_Plugin );

    if ( l_itr != iv_Plugins.end() )
    {
	l_rc = (**l_itr)( i_parser, i_mru );
    }

    return l_rc;
}

/*****************************************************************************/
// Pwr plugin parse call
/*****************************************************************************/
bool PluginCenter::CallPwrPlugin(
    comp_id_t       i_cid,
    ErrlUsrParser & i_parser,
    const char *    i_pwr,
    errlCreator     i_ssid
)
{
    bool        l_rc = false;
    itr_t       l_itr;
    PwrPlugin   l_Plugin( i_cid, 0, i_ssid  );

    l_itr = Find( l_Plugin );

    if ( l_itr != iv_Plugins.end() )
    {
        l_rc = (**l_itr)( i_parser, i_pwr );
    }

    return l_rc;
}

/*****************************************************************************/
// Lookup plugin on list
/*****************************************************************************/
PluginCenter::itr_t PluginCenter::Find( const Plugin & i_plugin )
{
    itr_t  l_itr, l_end;

    l_itr = iv_Plugins.begin();
    l_end = iv_Plugins.end();
    while ( l_itr != l_end )
    {
	if ( i_plugin == (**l_itr) )
	{
	    break;
	}
	++l_itr;
    }


    return l_itr;

}

//  @brief Destructor
    
PluginCenter::~PluginCenter()
{
}

} // namespace errl
