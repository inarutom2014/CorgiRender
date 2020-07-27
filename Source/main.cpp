#include <iostream>
#include "Core/CoreTypes.h"

int main()
{
    Corgi::Core::PlatformMisc::PlatformInit();
    std::cout << "hello" << std::endl;
    Corgi::Core::PlatformMisc::PlatformTerminate();
    return 0;
}