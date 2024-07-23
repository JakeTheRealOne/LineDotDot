/**
 * @file about.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for the About class
 * @version 0.1
 * @date 23-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */



// #### Internal inclusions: ####
# include "../header/about.hpp"

// #### Qt inclusions: ####
# include <QWidget>
# include <QLabel>
# include <QPushButton>
# include <QLayout>


About::About()
{
  buildChildren();
  buildLayouts();
  buildStyle();
}


void About::buildChildren()
{

}


void About::buildStyle()
{

}


void About::buildLayouts()
{
  mainLayout.addWidget(&appName);
  mainLayout.addWidget(&appVersion);
  mainLayout.addWidget(&toWebsite);
  this->setLayout(&mainLayout);
  mainLayout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
}
