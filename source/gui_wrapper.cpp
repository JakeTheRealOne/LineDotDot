/**
 * @file gui_wrapper.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file for the GuiWrapper class
 * @version 0.1
 * @date 24-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// #### Qt inclusions: ####
# include <QWidget>
# include <QGraphicsDropShadowEffect>
# include <QHBoxLayout>
# include <QResizeEvent>
# include <QThread>

// #### Internal inclusions: ####
# include "../header/gui_wrapper.hpp"

// #### Std inclusions: ####
# include <iostream>
using namespace std;


GuiWrapper::GuiWrapper()
{
  buildLayouts();
  buildShadow();
  buildStyle();
}


void GuiWrapper::buildLayouts()
{
  guiWidget.setParent(this);
  mainLayout.addWidget(&guiWidget);
  mainLayout.setSpacing(0);
  mainLayout.setContentsMargins(0, 0, 0, 0);
  this->setLayout(&mainLayout);
}


void GuiWrapper::buildShadow()
{
  windowShadow->setBlurRadius(10);
  windowShadow->setXOffset(0);
  windowShadow->setYOffset(0);
  windowShadow->setColor(Qt::black);
  this->setGraphicsEffect(windowShadow);
}


void GuiWrapper::buildStyle()
{
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setWindowFlags(Qt::FramelessWindowHint);
  this->setAttribute(Qt::WA_NoSystemBackground);
}


void GuiWrapper::paintEvent(QPaintEvent *)
{
    if (!isMaximized() and !isFullScreen()) {
      mainLayout.setContentsMargins(5, 5, 5, 5);
      guiWidget.roundedCorners = true;
    } else {
      mainLayout.setContentsMargins(0, 0, 0, 0);
      guiWidget.roundedCorners = false;
    }
    QWidget::paintEvent(nullptr);
}