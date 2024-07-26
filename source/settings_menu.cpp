/**
 * @file settingsMenu.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for SettingsMenu widget
 * @version 0.1
 * @date 25-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// #### Qt inclusions: ####
# include <QWidget>
# include <QVBoxLayout>
# include <QPushButton>
# include <QResizeEvent>
# include <QLabel>
# include <QCheckBox>


// #### Internal inclusions: ####
# include "../header/settings_menu.hpp"


SettingsMenu::SettingsMenu()
{
  setWindowFlags(Qt::Window | Qt::Tool);
  buildButtons();
  buildLayouts();
  buildStyle();
}


void SettingsMenu::buildButtons()
{
  
}


void SettingsMenu::buildLayouts()
{
  mainLayout.addWidget(&languageButton);
  mainLayout.addWidget(&aboutButton);
  // mainLayout.setContentsMargins(2, 2, 2, 2);
  mainBox.setLayout(&mainLayout);
  mainBox.setObjectName("mainBox");

  voidLayout.addWidget(&mainBox);
  this->setLayout(&voidLayout);
}


void SettingsMenu::buildStyle()
{
    this->resize(150, 150);
    this->setFixedSize(150, 150);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setStyleSheet(
      "QWidget {background-color: green; font-size: 12px;}"
      "#mainBox {border-radius: 5px; background-color: blue;}"
      "QPushButton {background-color: red;}"
    );
}


void SettingsMenu::resizeEvent(QResizeEvent* event)
{
  event->ignore();
}