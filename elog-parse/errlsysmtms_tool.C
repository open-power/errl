/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errlsysmtms.H>

#include <errlparser.H>

/*****************************************************************************/
// Object print
/*****************************************************************************/
void ErrlSysMtms::print(
    ErrlParser & i_parser,
    ErrlSysMtms& i_obj
) 
{
    i_obj.iv_header.print( i_obj.flatSize(), i_parser );
    i_obj.iv_mtms.print( i_parser );
}


