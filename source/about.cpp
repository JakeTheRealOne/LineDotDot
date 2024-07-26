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
# include <QDesktopServices>
# include <QUrl>
# include <QTextEdit>


About::About()
{
  buildChildren();
  buildLayouts();
  buildStyle();
}


void About::buildChildren()
{
  this->setWindowTitle("About");
  appName.setParent(&nameBox);
  appVersion.setParent(&versionBox);
  appAuthor.setParent(&authorBox);

  appName.setObjectName("appName");
  appVersion.setObjectName("appVersion");
  appAuthor.setObjectName("appAuthor");
  aboutBox.setObjectName("aboutBox");
  mainBox.setObjectName("mainBox");
  legalButton.setObjectName("legalButton");
  legalBox.setObjectName("legalBox");
  legalTitle.setObjectName("legalTitle");
  legalSubtitle.setObjectName("legalSubtitle");
  legalText.setObjectName("legalText");
  closeButton.setObjectName("closeButton");
  gobackButton.setObjectName("gobackButton");

  gobackButton.setVisible(false);
  legalBox.setVisible(false);

  legalText.setReadOnly(true);

  this->connect(&legalButton, &QPushButton::clicked, this,
                &About::showLegal);

  this->connect(&gobackButton, &QPushButton::clicked, this,
                &About::hideLegal);

  this->connect(&closeButton, &QPushButton::clicked, this,
                &QWidget::hide);

  toGithub.setObjectName("toGithub");
  this->connect(&toGithub, &QPushButton::clicked, [&]() {
      QUrl url("https://github.com/JakeTheRealOne/LineDotDot");
      QDesktopServices::openUrl(url);
  });

  toWiki.setObjectName("toWiki");
  this->connect(&toWiki, &QPushButton::clicked, [&]() {
      QUrl url("https://en.wikipedia.org/wiki/Morse_code");
      QDesktopServices::openUrl(url);
  });
}


void About::buildStyle()
{
  this->resize(250, 373);
  this->setFixedSize(250, 373);

  windowShadow.setBlurRadius(10);
  windowShadow.setXOffset(0);
  windowShadow.setYOffset(0);
  windowShadow.setColor(Qt::black);
  this->setGraphicsEffect(&windowShadow);

  this->setStyleSheet(
    "QWidget {color: #FFFFFF; padding: 0.25em; margin: 0em; font-size: 18px; border-radius: 3px;}"
    "QPushButton {background-color: #353535; font-size: 18px; border-radius: 0.35em; margin: 0.25em;}"
    "QPushButton:hover {background-color: #3B3B3B;}"
    "QScrollBar {background-color: #2E2E2E; padding: 0; margin: 0;} QScrollBar::handle"
    "{background-color: #202020; border: none; border-radius: 5px; margin: 0; width: 1em; padding: 0;}"
    "QScrollBar::up-arrow, QScrollBar::down-arrow {border: none; width: 0; height: 0; background: none;}"
    "QScrollBar::sub-line, QScrollBar::add-line { border: none; background: none; height: 0px; subcontrol-origin: margin;}"

    "#toGithub {margin-bottom: 0;}"
    "#appVersion {font-size: 15px; border-radius: 0.71em; color: #73A5E1; background-color: #2C3138; padding: 0.25em 1em; margin-bottom: 1em; font-weight: bold;}"
    "#appAuthor {font-size: 15px;}"
    "#appName {font-size: 24px; margin-top: 0.75em; padding: 0; font-weight: bold;}"
    "#mainBox, #legalBox {border-radius: 12px; background-color: #242424; padding: 0.5em;}"
    "#closeButton, #gobackButton {border-radius: 0.71em; padding: 0.25em 0.4em; font-size: 16px; background-color: #2E2E2E;}"
    "#gobackButton {padding: 0.25em 0.5em;}"
    "#closeButton:hover, #gobackButton:hover {background-color: #454545;}"
    "#legalButton {margin-top: 0.5em;}"
    "#legalTitle {font-weight: bold; text-align: center; padding: 0;}"
    "#legalSubtitle {font-size: 10px; padding: 0;}"
    "#legalText {font-size: 14px; background-color: #353535;}"
  );

  this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
}


void About::buildLayouts()
{
  nameLayout.setContentsMargins(0, 0, 0, 0);
  authorLayout.setContentsMargins(0, 0, 0, 0);
  versionLayout.setContentsMargins(0, 0, 0, 0);
  mainLayout.setContentsMargins(0, 0, 0, 0);
  voidLayout.setContentsMargins(0, 0, 0, 0);
  buttonsLayout.setContentsMargins(0, 0, 0, 0);
  topLayout.setContentsMargins(0, 0, 0, 0);

  topLayout.addWidget(&gobackButton);
  topLayout.addStretch();
  topLayout.addWidget(&closeButton);
  topBar.setLayout(&topLayout);

  buttonsLayout.addWidget(&toGithub);
  buttonsLayout.addWidget(&toWiki);
  buttonsLayout.addWidget(&legalButton);
  buttonsBox.setLayout(&buttonsLayout);

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

  aboutLayout.addWidget(&nameBox);
  aboutLayout.addWidget(&authorBox);
  aboutLayout.addWidget(&versionBox);
  aboutLayout.addWidget(&buttonsBox);
  aboutLayout.addStretch();
  aboutBox.setLayout(&aboutLayout);

  legalLayout.addWidget(&legalTitle);
  legalLayout.addWidget(&legalSubtitle);
  legalLayout.addWidget(&legalText);
  legalBox.setLayout(&legalLayout);

  mainLayout.addWidget(&topBar);
  mainLayout.addWidget(&aboutBox);
  mainLayout.addWidget(&legalBox);
  // mainLayout.addStretch();
  mainBox.setLayout(&mainLayout);
  mainLayout.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  appName.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
  appVersion.setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

  voidLayout.addWidget(&mainBox);
  this->setLayout(&voidLayout);
}


void About::resizeEvent(QResizeEvent* event)
{
  if (isMaximized() or isFullScreen()){
    mainBox.setStyleSheet("#mainBox {border-radius: 0;}");
    voidLayout.setContentsMargins(0, 0, 0, 0);
  } else {
    mainBox.setStyleSheet("#mainBox {border-radius: 10px;}");
    voidLayout.setContentsMargins(5, 5, 5, 5);
  }
}



void About::showLegal()
{
  gobackButton.show();
  aboutBox.hide();
  legalBox.show();
}


void About::hideLegal()
{
  gobackButton.hide();
  aboutBox.show();
  legalBox.hide();
}