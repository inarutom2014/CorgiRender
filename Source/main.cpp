#include <iostream>
#include "Core/CoreTypes.h"
#include "Core/GenericPlatform/PlatformMisc.h"

int main()
{
    Corgi::Core::PlatformMisc::PlatformInit();
	Corgi::Core::PlatformMisc::MainLoop();
    Corgi::Core::PlatformMisc::PlatformTerminate();
    return 0;
}