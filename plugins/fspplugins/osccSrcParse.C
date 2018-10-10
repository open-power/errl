// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/plugins/osccSrcParse.C 1.3 
//  
// IBM CONFIDENTIAL 
//  
// OBJECT CODE ONLY SOURCE MATERIALS 
//  
// COPYRIGHT International Business Machines Corp. 2008,2009 
// All Rights Reserved 
//  
// The source code for this program is not published or otherwise 
// divested of its trade secrets, irrespective of what has been 
// deposited with the U.S. Copyright Office. 
//  
// IBM_PROLOG_END_TAG 


/* 
 * Module Specification
 * 
 * NAME: ciniSrcParse.C
 *
 * AUTHOR: Chris Ingram
 *
 * DESCRIPTION: 
 * 	This module provides an interface to the ERRL component for parsing 
 *
 * 	SRC's logged by this component.
 */

#include <dlfcn.h>
#include <srcisrc.H>
#include <fips_comp_id.H>
#include <errlplugins.H>

// Forward
static bool SrcDataParse(
    ErrlUsrParser & i_parser,
    const SrciSrc & i_src
);

// Globals
static errl::SrcPlugin g_SrcPlugin(OSCC_COMP_ID, SrcDataParse);

bool SrcDataParse(ErrlUsrParser &i_parser, const SrciSrc &i_src)
{
  bool l_rc = false;

 // l_rc = homParseSrc(i_parser, i_src, (const char *)"oscc.edb");

  return l_rc;
}

