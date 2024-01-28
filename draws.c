#include "include/raylib.h"
#include <stdio.h>

// Function to draw a hexagon
void DrawHexagon(float x, float y, float size, Color color, float rotation) {
  DrawPoly((Vector2){x, y}, 6, size, rotation, color);
}

// Function to draw an arrow
void DrawArrow(float x, float y, float size, Color color, float rotation) {
  DrawPoly((Vector2){x, y}, 3, size, rotation, color);
}

// Function to draw a counter
void DrawCounter(float x, float y, float size, Color color, int frames) {
  char buffer[128];

  // Convert frames into seconds and frames
  int seconds = frames / 60;
  int remainderFrames = frames % 60;

  // Draw seconds
  sprintf(buffer, "%d", seconds);
  DrawText(buffer, x, y, size, color);

  // Draw colon
  DrawText(":", x + 30, y, size, color);

  // Draw remainder frames
  sprintf(buffer, "%d", remainderFrames);
  DrawText(buffer, x + 40, y, size, color);
}
