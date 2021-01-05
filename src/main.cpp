/*     GUI application to handle     */
/*            text input             */
/*                                   */
/* To run the program, within a      */
/* terminal compile it with:         */ 
/*                                   */
/* make clean && make                */
/*                                   */
/* And run it with (In Linux):       */
/*                                   */
/* vblank_mode=0 ./application       */
/*                                   */
/* Made by: M. Lazarotto (04/12/21)  */
/*                                   */
/* Credits: To the One Lone Coder,   */ 
/* Javidx9.                          */
/* Check 'licenses' folder for more  */
/* info.                             */
/* github.com/OneLoneCoder/olcPixelGameEngine */

#include "Application.h"

int main()
{
    // App window settings
    olcApplication application;
    int32_t ScreenWidth  = 920;
    int32_t ScreenHeight = 640;
 
    // Main game loop  
    if (application.Construct(ScreenWidth, ScreenHeight, 1, 1))
    {
        application.Start();
    }

    return 0;
}