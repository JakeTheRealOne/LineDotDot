/**
 * @file main.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief To execute the program (display the Qt interface)
 * @version 0.1
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// #### Qt inclusions: ####
# include <QApplication>

// #### Internal inclusions: ####
# include "../header/gui.hpp"


int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  GUI window;

  window.show();
  int code = app.exec();
  return code;
} 