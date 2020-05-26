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
      //draws the circle for the clock
      c.draw (win);
      
      //draws the digits of the clock
      win.draw_text(370, 50, 60, "12");
      win.draw_text(710, 365, 60, "3");
      win.draw_text(375, 705, 60, "6");
      win.draw_text(60, 365, 60, "9");
      
      //time passed in seconds
    auto t = win.get_time();
      
      // 3 different rotation matrices for each time unit (seconds, minutes, hours)
    
      rotation_sec = make_rotation_mat2 (t * 2 * M_PI / 60.0f);
      rotation_min = make_rotation_mat2 (t * 2 * M_PI / 60.0f / 60.0f);
      rotation_hour = make_rotation_mat2 (t * 2 * M_PI / 60.0f / 60.0f / 60.0f);
    
      //Ending point of clock hand for the seconds, get's rotated with rotation matrix for the seconds
      float sec_x = 0.f + 250.f;
      float sec_y = 0.f + 250.f;
      Vec2 sec_vec {sec_x, sec_y};
      sec_vec = rotation_sec * sec_vec;
      
      //Ending point of clock hand for the minutes, get's rotated with rotation matrix for the minutes
      float min_x = 0.f + 220.f;
      float min_y = 0.f + 220.f;
      Vec2 min_vec {min_x, min_y};
      min_vec = rotation_min * min_vec;
      
      //Ending point of clock hand for the hours, get's rotated with rotation matrix for the hours
      float hour_x = 0.f + 150.f;
      float hour_y = 0.f + 150.f;
      Vec2 hour_vec {hour_x, hour_y};
      hour_vec = rotation_hour * hour_vec;
    
      //draws the three clock hands
      win.draw_line(400.0f, 400.0f, sec_vec.x + 400.0f, sec_vec.y + 400.0f, 0.0f, 1.0f, 0.0f, 2.0f);
      win.draw_line(400.0f, 400.0f, min_vec.x + 400.0f, min_vec.y + 400.0f, 1.0f, 1.0f, 1.0f, 3.0f);
      win.draw_line(400.0f, 400.0f, hour_vec.x + 400.0f, hour_vec.y + 400.0f, 1.0f, 1.0f, 1.0f, 4.0f);
      
      
    win.update();
  }

  return 0;
}
