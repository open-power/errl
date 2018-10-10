// IBM_PROLOG_BEGIN_TAG 
// This is an automatically generated prolog. 
//  
// fips920 src/oscc/fsp/firenze/dcc/dcc_stl.hpp 1.16 
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
/*--------------------------- IBM - Confidential ----------------------------*

    (C) Copyright International Business Machines Corporation 2004
    All Rights Reserved
    Licensed Material  -  Program Property of I B M
    Refer to copyright instructions: Form G120-2083

*---------------------------------------------------------------------------*/

#ifndef _DCC_STL_HPP_
#define _DCC_STL_HPP_

#include <string>
#include <sstream>
#include <ostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

namespace dccstl
{
    class string : public std::basic_string<char, std::char_traits<char>, std::allocator<char> >
    {
    public:
        string(void) {};
        string(const std::string& f_str) : std::basic_string<char, std::char_traits<char>, std::allocator<char> >(f_str) {};
        string(const char* f_charArr) : std::basic_string<char, std::char_traits<char>, std::allocator<char> >(f_charArr) {};
        string(const char* f_charArr, size_t f_len) : std::basic_string<char, std::char_traits<char>, std::allocator<char> >(f_charArr,f_len) {};
        string trim(void) const
        {
            size_t start = find_first_not_of(' ');
            size_t end = find_last_not_of(' ');
            if ((start == std::string::npos) || (end == std::string::npos))
                return "";
            return substr(start, end - start + 1);
        };
        void toLowercase(void) 
        {
            std::transform(begin(), end(), begin(), ::tolower);
        };
        void toUppercase(void) 
        {
            std::transform(begin(), end(), begin(), ::toupper);
        };
    };

    typedef std::basic_ostringstream<char, std::char_traits<char>, std::allocator<char> > ostringstream;
    typedef std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> > stringstream;
    typedef std::basic_ostream<char, std::char_traits<char> > ostream;
    typedef std::basic_ofstream<char, std::char_traits<char> > ofstream;

    template <typename _VALUETYPE>
        class vector : public std::vector<_VALUETYPE/*, dccAllocator*/>
        {
        public:
            vector(void) {};
            vector(typename std::vector<_VALUETYPE>::size_type _Count) : std::vector<_VALUETYPE>(_Count) {};
            vector(const std::vector<_VALUETYPE>& f_vec) : std::vector<_VALUETYPE>(f_vec) {};
        };

    template <typename _VALUETYPE>
        class list : public std::list<_VALUETYPE/*, dccAllocator*/>
        {};

    template <typename _VALUETYPE>
        class queue : public std::queue<_VALUETYPE/*, dccAllocator*/>
        {};

    template <typename _VALUETYPE, typename _COMPARETYPE = std::less<_VALUETYPE> >
        class set : public std::set<_VALUETYPE, _COMPARETYPE/*, dccAllocator*/>
        {};

    template <typename _KEYTYPE, typename _VALUETYPE, typename _COMPARETYPE = std::less<_KEYTYPE> >
        class map : public std::map<_KEYTYPE, _VALUETYPE, _COMPARETYPE/*, dccAllocator*/>
        {};
}

#endif //_DCC_STL_HPP_

