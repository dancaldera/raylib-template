#include "raylib.h"
#include "raymath.h"
#include <iostream>

using namespace std;

void ToggleFullscreen(int screenWidth, int screenHeight)
{
  // check for alt + enter
  if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
  {
    // see what display we are on right now
    int display = GetCurrentMonitor();

    if (IsWindowFullscreen())
    {
      // if we are full screen, then go back to the windowed size
      SetWindowSize(screenWidth, screenHeight);
    }
    else
    {
      // if we are not full screen, set the window size to match the monitor we are on
      // always use the primary monitor
      SetWindowSize(screenWidth, screenWidth);
    }

    // toggle the state
    ToggleFullscreen();
  }
}