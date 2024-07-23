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
# include <QVBoxLayout>
# include <QHBoxLayout>


About::About()
{
  buildStyle();
  buildChildren();
  buildLayouts();
}


void About::buildChildren()
{
  appName.setObjectName("appName");
  appVersion.setObjectName("appVersion");
}


void About::buildStyle()
{
  this->setStyleSheet(
    "QWidget {background-color: #242424; color: #FFFFFF; padding: 0.25em; margin: 0.25em; font-size: 18px; border-radius: 3px;}"
    "QPushButton {background-color: #353535; font-size: 18px; border-radius: 0.35em;}"
    "QPushButton:hover {background-color: #3B3B3B;}"
    "#appVersion {font-size: 14px; border-radius: 0.6em; color: #73A5E1; background-color: #2C3138; padding: 0.2em 0.1em;}"
  );
}


void About::buildLayouts()
{
  mainLayout.addWidget(&appName);
  mainLayout.addWidget(&appVersion);
  mainLayout.addWidget(&toWebsite);
  this->setLayout(&mainLayout);
  mainLayout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  appName.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  appVersion.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

}
