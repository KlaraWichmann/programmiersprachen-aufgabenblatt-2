#include "window.hpp"
#include "shapes.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <array>


int main(int argc, char* argv[])
{
    //circle objects saved in an array
    std::array<Circle, 2> circles = {{
        {100.0f, Vec2 {200.0f, 200.0f}, Color {1.0f, 1.0f, 1.0f}, Color  {1.0f, 1.0f, 0.0f}},
        {100.0f, Vec2 {400.0f, 400.0f}, Color {1.0f, 1.0f, 1.0f}, Color  {1.0f, 1.0f, 0.0f}}
    }};
    
    //rectangle objects saved in an array
    std::array<Rectangle, 3> rectangles = {{
        {Vec2 {0.0f, 0.0f}, Vec2 {100.0f, 100.0f}, Color {1.0f, 1.0f, 1.0f}, Color  {1.0f, 0.0f, 1.0f}},
        {Vec2 {100.0f, 50.0f}, Vec2 {200.0f, 300.0f}, Color {1.0f, 1.0f, 1.0f}, Color  {1.0f, 0.0f, 1.0f}},
        {Vec2 {100.0f, 50.0f}, Vec2 {300.0f, 300.0f}, Color {1.0f, 1.0f, 1.0f}, Color  {1.0f, 0.0f, 1.0f}}
    }};
    
    
  Window win{std::make_pair(800,800)};



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
      
      //current mouse position as vector
      float x_mouse = 0.0f;
      float y_mouse = 0.0f;
      std::tie (x_mouse, y_mouse) = win.mouse_position();
      Vec2 mouse_pos {x_mouse, y_mouse};
      
      //see if mouse position is in the rectangle object, if true set reactangle to highlight color
      for (int i = 0; i < rectangles.size(); i++) {
          if (rectangles[i].is_inside (mouse_pos)) {
              rectangles[i].draw (win, true);
          } else {
              rectangles[i].draw (win);
          }
      }
      
      //see if mouse position is in circle object, if true set circle to highlight color
      for (int i = 0; i < circles.size(); i++) {
          if (circles[i].is_inside (mouse_pos)) {
              circles[i].draw (win, true);
          } else {
              circles[i].draw (win);
          }
      }
      
    win.update();
  }

  return 0;
}
