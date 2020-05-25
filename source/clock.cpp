#include "shapes.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <vector>



int main(int argc, char* argv[])
{
    
  Window win{std::make_pair(800,800)};
    
    Circle c {370.0f, Vec2 {400.0f, 400.0f}, Color {1.0f, 1.0f, 1.0f}, Color  {1.0f, 1.0f, 0.0f}};
    
    Mat2 rotation_sec;
    Mat2 rotation_min;
    Mat2 rotation_hour;

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
      
      // 3 verschiedene rotationsmatrizen
    
      rotation_sec = make_rotation_mat2 (t / 10);
      rotation_min = make_rotation_mat2 (t / 100);
      rotation_hour = make_rotation_mat2 (t / 1000);
    

      float sec_x = 0.f + 250.f;
      float sec_y = 0.f + 250.f;
      Vec2 sec_vec {sec_x, sec_y};
      sec_vec = rotation_sec * sec_vec;
      
      float min_x = 0.f + 220.f;
      float min_y = 0.f + 220.f;
      Vec2 min_vec {min_x, min_y};
      min_vec = rotation_min * min_vec;
      
      float hour_x = 0.f + 150.f;
      float hour_y = 0.f + 150.f;
      Vec2 hour_vec {hour_x, hour_y};
      hour_vec = rotation_hour * hour_vec;
    
      win.draw_line(400.0f, 400.0f, sec_vec.x + 400.0f, sec_vec.y + 400.0f, 0.0f, 1.0f, 0.0f, 2.0f);
      win.draw_line(400.0f, 400.0f, min_vec.x + 400.0f, min_vec.y + 400.0f, 1.0f, 1.0f, 1.0f, 3.0f);
      win.draw_line(400.0f, 400.0f, hour_vec.x + 400.0f, hour_vec.y + 400.0f, 1.0f, 1.0f, 1.0f, 4.0f);
      
      
    win.update();
  }

  return 0;
}
