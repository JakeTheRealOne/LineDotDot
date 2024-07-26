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
# include <QGraphicsDropShadowEffect>
# include <QPoint>


// #### Internal inclusions: ####
# include "../header/settings_menu.hpp"

# include <iostream>
using namespace std;

SettingsMenu::SettingsMenu(QWidget* parent)
{
  // this->setParent(parent);
  buildButtons();
  buildLayouts();
  buildStyle();
}


void SettingsMenu::buildButtons()
{
  this->connect(&aboutButton, &QPushButton::clicked, this,
                &SettingsMenu::showAboutPage);
}


void SettingsMenu::buildLayouts()
{
  // mainLayout.addWidget(&languageButton);
  mainLayout.addWidget(&aboutButton);
  mainBox.setLayout(&mainLayout);
  mainBox.setObjectName("mainBox");
  voidLayout.addWidget(&mainBox);
  this->setLayout(&voidLayout);
}


void SettingsMenu::buildStyle()
{
  windowShadow.setBlurRadius(10);
  windowShadow.setXOffset(0);
  windowShadow.setYOffset(0);
  windowShadow.setColor(Qt::black);
  this->setGraphicsEffect(&windowShadow);

  this->resize(200, 75);
  this->setFixedSize(200, 75);
  this->setStyleSheet(
    "QWidget {background-color: #1E1E1E; font-size: 14px; color: #FFFFFF;}"
    "#mainBox {border-radius: 10px;}"
    "QPushButton {border: none; padding: 0.5em 0.25em; border-radius: 5px; margin: 0.1em; text-align: left;}"
    "QPushButton:hover {background-color: #2F2F2F;}"
  );

  this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
  this->setAttribute(Qt::WA_TranslucentBackground);

}


void SettingsMenu::resizeEvent(QResizeEvent* event)
{
  if (isMaximized() or isFullScreen()){
    mainBox.setStyleSheet("#mainBox {border-radius: 0;}");
    voidLayout.setContentsMargins(0, 0, 0, 0);
  } else {
    mainBox.setStyleSheet("#mainBox {border-radius: 10px;}");
    voidLayout.setContentsMargins(5, 5, 5, 5);
  }
  event->ignore();
}


void SettingsMenu::toggle()
{
  if (this->isVisible())
  {
    this->hide();
  }
  else
  {
    this->show();
    aboutPage.hide();
  }

}

void SettingsMenu::showAboutPage()
{
  this->hide();
  aboutPage.show();
}