#include <attributeenums.H>
using namespace TARGETING;
EntityPath l_path;
const char * name = NULL;
const char * test_string = "Unknown path type";
size_t size = strlen( test_string );
name = l_path.pathElementTypeAsString( TYPE_NA );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_NA - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_SYS );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_SYS - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_NODE );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_NODE - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_DIMM );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_DIMM - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_MEMBUF );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_MEMBUF - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PROC );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PROC - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_EX );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_EX - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_CORE );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_CORE - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_L2 );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_L2 - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_L3 );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_L3 - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_L4 );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_L4 - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_MCS );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_MCS - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_MBA );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_MBA - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_XBUS );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_XBUS - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_ABUS );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_ABUS - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PCI );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PCI - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_DPSS );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_DPSS - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_APSS );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_APSS - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_OCC );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_OCC - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PSI );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PSI - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_FSP );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_FSP - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PNOR );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PNOR - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_OSC );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_OSC - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_TODCLK );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_TODCLK - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_CONTROL_NODE );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_CONTROL_NODE - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_OSCREFCLK );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_OSCREFCLK - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_OSCPCICLK );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_OSCPCICLK - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_REFCLKENDPT );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_REFCLKENDPT - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PCICLKENDPT );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PCICLKENDPT - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_NX );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_NX - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PORE );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PORE - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_PCIESWITCH );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_PCIESWITCH - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_CAPP );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_CAPP - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_FSI );
size = strlen( name );
if( !memcmp( name, test_string, size ))
{
TS_FAIL("undefined TYPE attribute TYPE_FSI - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_TEST_FAIL );
size = strlen( name );
if( memcmp( name, test_string, size ))
{
TS_FAIL("type attribute TYPE_TEST_FAIL - did not return expected error message. - update entitypath.C");
}
name = l_path.pathElementTypeAsString( TYPE_LAST_IN_RANGE );
size = strlen( name );
if( memcmp( name, test_string, size ))
{
TS_FAIL("type attribute TYPE_LAST_IN_RANGE - did not return expected error message. - update entitypath.C");
}
