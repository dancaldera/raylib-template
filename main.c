#include "draws.c"
#include "include/raylib.h"
#include <math.h>

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const float screenWidth = 800;
  const float screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Hexagon+");

  Vector2 touchPosition = {0, 0};
  Rectangle touchArea = {0, 0, 0, 0};

  int currentGesture = GESTURE_NONE;
  bool touchInput = false;

  GameScreen currentScreen = LOGO;

  // TODO: Initialize all required variables and load all required data here!
  int gameplayFrameCounter =
      0; // Useful to count frames in each gameplay loop iteration
  double arrowPosX = 0.0, arrowPosY = -85.0;
  double arrowSteps = 5;
  double angle = 270.0;
  const double radius = 85.0;
  const int hexagonSize = 80;

  int framesCounter = 0; // Useful to count frames

  SetTargetFPS(60); // Set desired framerate (frames-per-second)

  //--------------------------------------------------------------------------------------
  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // TODO: Handle window resizing #include "window_size.h"
    // ToggleFullscreen(screenWidth, screenHeight);

    // Update
    //----------------------------------------------------------------------------------
    switch (currentScreen) {
    case LOGO: {
      // Logo screen variables
      int secondsLoadingScreen = 2;

      framesCounter++; // Count frames

      // Wait for 5 seconds (300 frames) before jumping to TITLE screen
      if (framesCounter > secondsLoadingScreen * 60) {
        currentScreen = TITLE;
      }
    } break;
    case TITLE: {
      // TODO: Update TITLE screen variables here!

      framesCounter++; // Count frames

      // Press enter to change to GAMEPLAY screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        currentScreen = GAMEPLAY;
      }
    } break;
    case GAMEPLAY: {
      // TODO: Update GAMEPLAY screen variables here!
      int secondsCounter = 0;
      currentGesture = GetGestureDetected();
      touchPosition = GetTouchPosition(0);

      if (currentGesture != GESTURE_NONE) {
        touchArea =
            (Rectangle){touchPosition.x - 30, touchPosition.y - 30, 60, 60};
        touchInput = true;
      } else {
        touchInput = false;
      }

      framesCounter++; // Count frames

      secondsCounter = framesCounter / 60;

      // Press enter to change to ENDING screen
      if (IsKeyPressed(KEY_ENTER)) {
        currentScreen = ENDING;
      }
    } break;
    case ENDING: {
      // TODO: Update ENDING screen variables here!

      // Press enter to return to TITLE screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        currentScreen = TITLE;
      }
    } break;
    default:
      break;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (currentScreen) {
    case LOGO: {
      DrawText("Hexagon+", 20, 20, 60, LIGHTGRAY);
      DrawText("by: DC Game Studio", 20, 80, 30, GRAY);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6, hexagonSize,
               framesCounter, BLACK);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6,
               hexagonSize - 10, framesCounter, RAYWHITE);
      DrawText("LOADING", 290, 350, 40, GRAY);
      // draw dinamically the three dots after the word "LOADING"
      if (framesCounter / 20 % 3 == 0) {
        DrawText(".", 470, 350, 40, GRAY);
      } else if (framesCounter / 20 % 3 == 1) {
        DrawText("..", 470, 350, 40, GRAY);
      } else if (framesCounter / 20 % 3 == 2) {
        DrawText("...", 470, 350, 40, GRAY);
      }
    } break;
    case TITLE: {
      DrawText("Hexagon+", 20, 20, 60, LIGHTGRAY);
      DrawText("by: DC Game Studio", 20, 80, 30, GRAY);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6, hexagonSize,
               framesCounter, BLACK);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6,
               hexagonSize - 10, framesCounter, RAYWHITE);
      DrawText("PRESS [ENTER] or Tap to start", 160, 350, 30, GRAY);
    } break;
    case GAMEPLAY: {
      int clockX = 680;
      int clockY = 40;
      gameplayFrameCounter++; // Count frames
      DrawText("GAME", 20, 20, 60, LIGHTGRAY);
      DrawCounter(clockX, clockY, 30, GRAY, gameplayFrameCounter);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6, hexagonSize,
               framesCounter, BLACK);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6,
               hexagonSize - 10, framesCounter, RAYWHITE);

      if (IsKeyDown(KEY_RIGHT) ||
          (touchPosition.x > screenWidth / 2 && touchInput)) {
        angle += arrowSteps;
        arrowPosX = cos(angle * PI / 180) * radius;
        arrowPosY = sin(angle * PI / 180) * radius;
      } else if (IsKeyDown(KEY_LEFT) ||
                 (touchPosition.x < screenWidth / 2 && touchInput)) {
        angle -= arrowSteps;
        arrowPosX = cos(angle * PI / 180) * radius;
        arrowPosY = sin(angle * PI / 180) * radius;
      }

      DrawArrow(screenWidth / 2 + arrowPosX, screenHeight / 2 + arrowPosY, 10,
                RED, angle);
    } break;
    case ENDING: {
      // TODO: Draw ENDING screen here!
      gameplayFrameCounter = 0;
      // DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
      DrawText("GAME OVER", 20, 20, 60, LIGHTGRAY);
      DrawText("PRESS [ENTER] or Tap", 230, 350, 30, GRAY);
      DrawText("to return to TITLE screen", 200, 380, 30, GRAY);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6, hexagonSize,
               framesCounter, RED);
      DrawPoly((Vector2){screenWidth / 2, screenHeight / 2}, 6,
               hexagonSize - 10, framesCounter, RAYWHITE);
    } break;
    default:
      break;
    }

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
