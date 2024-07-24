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
# include <QPainter>
# include <QPainterPath>
# include <QColor>
# include <QFont>
# include <QGraphicsDropShadowEffect>

# include <iostream>
using namespace std;

About::About()
{
  buildStyle();
  buildChildren();
  buildLayouts();
}


void About::buildChildren()
{
  this->setWindowTitle("About");
  appName.setObjectName("appName");
  appName.setParent(&nameBox);
  appVersion.setObjectName("appVersion");
  appVersion.setParent(&versionBox);
  appAuthor.setObjectName("appAuthor");
  appAuthor.setParent(&authorBox);
}


void About::buildStyle()
{
  // QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
  // windowShadow.setBlurRadius(5); // Adjust the blur radius
  // windowShadow.setXOffset(5);    // Horizontal offset
  // windowShadow.setOffset(5);    // Vertical offset
  // windowShadow.setColor(Qt::black); // Shadow color

  versionFont.setBold(true);
  versionBox.setFont(versionFont);

  nameFont.setBold(true);
  nameBox.setFont(nameFont);

  this->setWindowFlags(Qt::FramelessWindowHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setStyleSheet(
    "QWidget {color: #FFFFFF; padding: 0.25em; margin: 0em; font-size: 18px; border-radius: 3px;}"
    "QPushButton {background-color: #353535; font-size: 18px; border-radius: 0.35em;}"
    "QPushButton:hover {background-color: #3B3B3B;}"
    "#appVersion {font-size: 15px; border-radius: 0.71em; color: #73A5E1; background-color: #2C3138; padding: 0.25em 1em; margin-bottom: 1em;}"
    "#appAuthor {font-size: 15px;}"
    "#appName {font-size: 24px; margin-top: 0.75em; padding: 0;}"
  );
}


void About::buildLayouts()
{
  nameLayout.setContentsMargins(0, 0, 0, 0);
  authorLayout.setContentsMargins(0, 0, 0, 0);
  versionLayout.setContentsMargins(0, 0, 0, 0);
  mainLayout.setContentsMargins(0, 0, 0, 0);

  nameLayout.addStretch();
  nameLayout.addWidget(&appName);
  nameLayout.addStretch();
  nameBox.setLayout(&nameLayout);

  authorLayout.addStretch();
  authorLayout.addWidget(&appAuthor);
  authorLayout.addStretch();
  authorBox.setLayout(&authorLayout);

  versionLayout.addStretch();
  versionLayout.addWidget(&appVersion);
  versionLayout.addStretch();
  versionBox.setLayout(&versionLayout);

  mainLayout.addWidget(&nameBox);
  mainLayout.addWidget(&authorBox);
  mainLayout.addWidget(&versionBox);
  // mainLayout.addWidget(&);
  this->setLayout(&mainLayout);
  mainLayout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  appName.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  appVersion.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

}

void About::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  if (!isMaximized() and !isFullScreen()) {
    QPainterPath path;
    path.addRoundedRect(rect(), 12, 12);
    painter.fillPath(path, QColor(36, 36, 36));
  } else {
    painter.fillRect(rect(), QColor(36, 36, 36));
  }

  QWidget::paintEvent(nullptr);
}