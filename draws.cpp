#include "include/raylib.h"
#include <string>

// Function to draw an hexagon
void DrawHexagon(float x, float y, float size, Color color, float rotation = 0,
                 int speed = 50) {
  DrawPoly((Vector2){x, y}, 6, size, rotation, color);
}

void DrawArrow(float x, float y, float size, Color color, float rotation = 0,
               int speed = 50) {
  DrawPoly((Vector2){x, y}, 3, size, rotation, color);
}

void DrawCounter(float x, float y, float size, Color color, int frames) {
  DrawText(std::to_string(frames / 60).c_str(), x, y, size, color);
  DrawText(":", x + 30, y, size, color);
  DrawText(std::to_string(frames % 60).c_str(), x + 40, y, size, color);
}
