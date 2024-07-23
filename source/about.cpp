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
  appVersion.setObjectName("appVersion");
}


void About::buildStyle()
{
  this->setWindowFlags(Qt::FramelessWindowHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setStyleSheet(
    "QWidget {background-color: #242424; color: #FFFFFF; padding: 0.25em; margin: 0.25em; font-size: 18px; border-radius: 3px;}"
    "QPushButton {background-color: #353535; font-size: 18px; border-radius: 0.35em;}"
    "QPushButton:hover {background-color: #3B3B3B;}"
    "#appVersion {font-size: 14px; border-radius: 0.71em; color: #73A5E1; background-color: #2C3138; padding: 0.25em 1em;}"
  );
}


void About::buildLayouts()
{
  // nameLayout.addStretch();
  // nameLayout.addWidget(&appName);
  // nameLayout.addStretch();
  // nameBox.setLayout(&nameLayout);

  // versionLayout.addStretch();
  // versionLayout.addWidget(&appVersion);
  // versionLayout.addStretch();
  // versionBox.setLayout(&versionLayout);



  mainLayout.addWidget(&nameBox);
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
        path.addRoundedRect(rect(), 15, 15);
        painter.fillPath(path, QColor(36, 36, 36));
    } else {
        painter.fillRect(rect(), QColor(36, 36, 36));
    }

    QWidget::paintEvent(nullptr);
}