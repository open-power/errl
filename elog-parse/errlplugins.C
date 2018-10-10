/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlplugincenter.H>
#include <errlutility.H>



namespace errl {
    
/*****************************************************************************/
// Plugin virtual destructor
/*****************************************************************************/
Plugin::~Plugin()
{
}

    
/*****************************************************************************/
// Data plugin access
/*****************************************************************************/
bool Plugin::operator() (
    ErrlUsrParser & i_parser,
    void *	    i_buffer,
    uint32_t	    i_buflen,
    errlver_t	    i_ver,
    errlsubsec_t    i_sst
)
{
    return false;
}


/*****************************************************************************/
// Src plugin access
/*****************************************************************************/
bool Plugin::operator() (
    ErrlUsrParser & i_parser,
    const SrciSrc & i_src
)
{
    return false;
}


/*****************************************************************************/
// Mru plugin access
/*****************************************************************************/
bool Plugin::operator() (
    ErrlUsrParser & i_parser,
    uint32_t	    i_mru
)
{
    return false;
}

/*****************************************************************************/
// Pwr plugin access
/*****************************************************************************/
bool Plugin::operator() (
    ErrlUsrParser & i_parser,
    const char *    i_pwr
)
{
    return false;
}



/*****************************************************************************/
// Data Plugin constructor - registration
/*****************************************************************************/
DataPlugin::DataPlugin(
    comp_id_t   i_cid,
    func_t	i_func,
    errlCreator i_ssid
)
: Plugin( i_cid, DATA, i_ssid ), iv_pFunc( i_func )
{
    if ( i_func )
    {
	PluginCenter::Instance()->Register( *this );
    }
}


/*****************************************************************************/
// Data plugin destructor - deregistration
/*****************************************************************************/
DataPlugin::~DataPlugin()
{
    if ( iv_pFunc )
    {
	PluginCenter::Instance()->Deregister( *this );
    }
}


/*****************************************************************************/
// Data plugin access
/*****************************************************************************/
bool DataPlugin::operator() (
    ErrlUsrParser & i_parser,
    void *	    i_buffer,
    uint32_t	    i_buflen,
    errlver_t	    i_ver,
    errlsubsec_t    i_sst
)
{
    return (*iv_pFunc)( i_parser, i_buffer, i_buflen, i_ver, i_sst);
}


/*****************************************************************************/
// Src plugin constructor - registration
/*****************************************************************************/
SrcPlugin::SrcPlugin(
    comp_id_t   i_cid,
    func_t	i_func,
    errlCreator i_ssid
)
: Plugin( i_cid, SRC, i_ssid ), iv_pFunc( i_func )
{
    if ( i_func )
    {
	PluginCenter::Instance()->Register( *this );
    }
}


/*****************************************************************************/
// Src plugin destructor - deregistration
/*****************************************************************************/
SrcPlugin::~SrcPlugin()
{
    if ( iv_pFunc )
    {
	PluginCenter::Instance()->Deregister( *this );
    }
}


/*****************************************************************************/
// Src plugin access
/*****************************************************************************/
bool SrcPlugin::operator() (
    ErrlUsrParser & i_parser,
    const SrciSrc & i_src
)
{
    return (*iv_pFunc)( i_parser, i_src );
}


/*****************************************************************************/
// Mru plugin constructor - registration
/*****************************************************************************/
MruPlugin::MruPlugin(
    comp_id_t   i_cid,
    func_t	i_func,
    errlCreator i_ssid
)
: Plugin( i_cid, MRU, i_ssid), iv_pFunc( i_func )
{
    if ( i_func )
    {
	PluginCenter::Instance()->Register( *this );
    }
}


/*****************************************************************************/
// Pwr plugin constructor - registration
/*****************************************************************************/
PwrPlugin::PwrPlugin(
    comp_id_t   i_cid,
    func_t      i_func,
    errlCreator i_ssid
)
: Plugin( i_cid, PWR,i_ssid ), iv_pFunc( i_func )
{
    if ( i_func )
    {
        PluginCenter::Instance()->Register( *this );
    }
}



/*****************************************************************************/
// Mru plugin destructor - deregistration
/*****************************************************************************/
MruPlugin::~MruPlugin()
{
    if ( iv_pFunc )
    {
	PluginCenter::Instance()->Deregister( *this );
    }
}

/*****************************************************************************/
// Pwr plugin destructor - deregistration
/*****************************************************************************/
PwrPlugin::~PwrPlugin()
{
    if ( iv_pFunc )
    {
        PluginCenter::Instance()->Deregister( *this );
    }
}



/*****************************************************************************/
// Mru plugin access
/*****************************************************************************/
bool MruPlugin::operator() (
    ErrlUsrParser & i_parser,
    uint32_t	    i_mru
)
{
    return (*iv_pFunc)( i_parser, i_mru );
}

/*****************************************************************************/
// Pwr plugin access
/*****************************************************************************/
bool PwrPlugin::operator() (
    ErrlUsrParser & i_parser,
    const char *    i_pwr
)
{
    return (*iv_pFunc)( i_parser, i_pwr );
}
} // namespace errl
