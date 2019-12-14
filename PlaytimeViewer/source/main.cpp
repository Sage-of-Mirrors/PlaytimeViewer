#include <switch.h>
#include <iostream>

#include "PlaytimeRecords.h"

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    PlaytimeLogFile f("test.ptl");

    // Main loop
    while (appletMainLoop())
    {
        // Scan all the inputs. This should be done once for each frame
        hidScanInput();

        // hidKeysDown returns information about which buttons have been
        // just pressed in this frame compared to the previous one
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_A)
            std::cout << "Pressed A button!\n" << std::endl;

        if (kDown & KEY_PLUS)
            break; // break in order to return to hbmenu

        // Your code goes here

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}