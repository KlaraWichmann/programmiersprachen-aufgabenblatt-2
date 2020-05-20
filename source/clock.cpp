#include "window.hpp"
#include "shapes.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
    
  Window win{std::make_pair(800,800)};
    
    Circle c {370.0f, Vec2 {400.0f, 400.0f}, Color {1.0f, 1.0f, 1.0f}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
      c.draw (win);
      
      win.draw_text(370, 50, 60, "12");
      win.draw_text(710, 365, 60, "3");
      win.draw_text(375, 705, 60, "6");
      win.draw_text(60, 365, 60, "9");
      
      
    auto t = win.get_time();

    float sec_x = 400.f + 350.f * std::cos(t / 10);
    float sec_y = 400.f + 350.f * std::sin(t / 10);
      
      float min_x = 400.f + 320.f * std::cos(t / 70);
      float min_y = 400.f + 320.f * std::sin(t / 70);
      
      float hour_x = 400.f + 200.f * std::cos(t / 130);
      float hour_y = 400.f + 200.f * std::sin(t / 130);

      win.draw_line(400.0f, 400.0f, sec_x, sec_y, 0.0f, 1.0f, 0.0f, 2.0f);
      win.draw_line(400.0f, 400.0f, min_x, min_y, 1.0f, 1.0f, 1.0f, 3.0f);
      win.draw_line(400.0f, 400.0f, hour_x, hour_y, 1.0f, 1.0f, 1.0f, 4.0f);
      
    win.update();
  }

  return 0;
}
