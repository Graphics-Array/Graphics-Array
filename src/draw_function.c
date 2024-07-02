//Draw && color

// SimpleGL
#include<SDL2/SDL.h>
#include<stdbool.h>
#include<stdio.h>
// Color scheme
typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
} Color;

Color colorFromRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
	Color.r=r;
	Color.g=g;
	Color.b=b;
	Color.a=a;
	return color;
}

// shape scheme

// Shape struct
typedef struct {
  int type; // 0 for rectangle, 1 for circle, 2 for triangle
  union {
    struct {
      int w, h; // For rectangles
    } rect;
    struct {
      int radius; // For circles
    } circle;
    struct {
      int x1, y1, x2, y2, x3, y3; // For triangles
    } triangle;
  };
} Shape;

// Create shape functions
Shape rect(int w, int h) {
  Shape shape;
  shape.type = 0; // Rectangle
  shape.rect.w = w;
  shape.rect.h = h;
  return shape;
}

Shape circle(int radius) {
  Shape shape;
  shape.type = 1; // Circle
  shape.circle.radius = radius;
  return shape;
}

Shape triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  Shape shape;
  shape.type = 2; // Triangle
  shape.triangle.x1 = x1;
  shape.triangle.y1 = y1;
  shape.triangle.x2 = x2;
  shape.triangle.y2 = y2;
  shape.triangle.x3 = x3;
  shape.triangle.y3 = y3;
  return shape;
}

// Draw function
void Draw(Shape shape, int color, int x, int y) {
  switch (shape.type) {
    case 0: // Rectangle
      // Draw rectangle using shape.rect.w and shape.rect.h
       // Draw a rectangle
    SDL_Rect rect = { 100, 100, 200, 200 }; // x, y, w, h
    SDL_RenderFillRect(renderer, &rect);

    // Present the changes
    SDL_RenderPresent(renderer);
      break;
    case 1: // Circle
      // Draw circle using shape.circle.radius
      break;
    case 2: // Triangle
      // Draw triangle using shape.triangle.x1, y1, x2, y2, x3, y3
      break;
  }
}

int main(){
	// usage : Shape (rect, w,h);
	// Color color =RGBA{255, 0, 255, 0};
	//Draw(shape, x, y, color);
}
