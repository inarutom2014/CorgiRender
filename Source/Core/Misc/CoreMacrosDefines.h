#pragma once

namespace Corgi
{
    namespace Internal
    {
        //Suppresses 'unused varaible ' warnings
        template <typename T>
        void ignore_unused_variable(const T &) {}
    } // namespace Internal
} // namespace Corgi

#define CORGI_UNUSED_VARIABLE(var) Corgi::Internal::ignore_unused_variable(var)
#define CORGI_LINE_SIZE 256