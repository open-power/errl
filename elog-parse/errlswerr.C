/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlswerr.H>

#include <errlparser.H>

void ErrlSwErr::print(
    ErrlParser & i_parser,
    ErrlSwErr & i_obj
) 
{
    // Print the header
    i_obj.iv_header.print( i_obj.flatSize(),  i_parser );

    i_parser.PrintNumber("File Id length", "%hi", i_obj.iv_fidSize);
    i_parser.PrintString("File Identifier", i_obj.iv_strFileId);
    i_parser.PrintNumber("Code Location", "0x%04X", i_obj.iv_codeloc);
    i_parser.PrintNumber("Return Code", "0x%08X", i_obj.iv_rc);
    i_parser.PrintNumber("Object Identifier", "0x%08X", i_obj.iv_objId);
}


