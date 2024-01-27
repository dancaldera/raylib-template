#include "include/raylib.h"

// Function to draw an hexagon
void DrawHexagon(float x, float y, float size, Color color, float rotation = 0,
                 int speed = 50) {
  DrawPoly((Vector2){x, y}, 6, size, rotation, color);
}

void DrawArrow(float x, float y, float size, Color color, float rotation = 0,
               int speed = 50) {
  DrawPoly((Vector2){x, y}, 3, size, rotation, color);
}

void DrawCounter(float x, float y, float size, Color color, int seconds) {
  // minutes and seconds
  int minutes = seconds / 60;
  seconds = seconds % 60;

  // draw minutes
  DrawText(TextFormat("%02i", minutes), x, y, size, color);
  // draw seconds
  DrawText(TextFormat(":%02i", seconds), x + size * 0.5, y, size * 0.5, color);
}
