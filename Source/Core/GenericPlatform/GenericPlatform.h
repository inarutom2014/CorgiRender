#pragma once

namespace Corgi
{
    namespace Core
    {
        struct GenericPlatformTypes
        {
            //unsigned type
            typedef unsigned char uint8;
            typedef unsigned short int uint16;
            typedef unsigned int uint32;
            typedef unsigned long long uint64;

            //signed type
            typedef signed char int8;
            typedef signed short int int16;
            typedef signed int int32;
            typedef signed long long int64;

            //character type
            typedef char ANSICHAR;
            typedef wchar_t WIDECHAR;
            typedef WIDECHAR TCHAR;
        };
    } // namespace Core
    
} // namespace Corgi
