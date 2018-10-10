/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlswv2.H>

#include <errlparser.H>
/*****************************************************************************/
// Object parse
/*****************************************************************************/
void ErrlSwV2::print(
    ErrlParser & i_parser,
    ErrlSwV2   & i_obj
)
{
    i_obj.iv_header.print( i_obj.flatSize(),  i_parser );
    i_parser.PrintNumber("File Identifier", "0x%04X", i_obj.iv_fileId );
    i_parser.PrintNumber("Code Location", "0x%04X", i_obj.iv_codeloc );
    i_parser.PrintNumber("Return Code", "0x%08X", i_obj.iv_rc );
    i_parser.PrintNumber("Object Identifier", "0x%08X", i_obj.iv_objId );
}


