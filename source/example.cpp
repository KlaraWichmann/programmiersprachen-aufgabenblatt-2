#include "window.hpp"
#include "shapes.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

#include <iostream>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
    
    Color white {1.0f, 1.0f, 1.0f};
    Vec2 max {100.0f, 100.0f};
    Vec2 min {0.0f, 0.0f};
    Rectangle rec {min, max, white};
    
    Vec2 max_highlight {200.0f, 300.0f};
    Vec2 min_highlight {100.0f, 50.0f};
    Rectangle rec_highlight {min_highlight, max_highlight, white};
    
    Circle c {100.0f, Vec2 {200.0f, 200.0f}, white};
    Circle c_highlight {100.0f, Vec2 {400.0f, 400.0f}, white};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
      
    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
      
      float x_rectangle = 0.0f;
      float y_rectangle = 0.0f;
      std::tie (x_rectangle, y_rectangle) = win.mouse_position();
      Vec2 mouse_rec {x_rectangle, y_rectangle};
      if (rec.is_inside (mouse_rec)) {
          rec.draw (win, true);
      } else {
          rec.draw (win);
      }
      
      //rec_highlight.draw (win, true);
      float x_circle = 0.0f;
      float y_circle = 0.0f;
      std::tie (x_circle, y_circle) = win.mouse_position();
      Vec2 mouse_circle {x_circle, y_circle};
      if (c.is_inside (mouse_circle)) {
          c.draw (win, true);
      } else {
          c.draw (win);
      }
      
      //c_highlight.draw (win, true);
      
    win.update();
  }

  return 0;
}
