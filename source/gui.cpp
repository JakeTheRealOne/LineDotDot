/**
 * @file gui.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file of the GUI class
 * @version 0.1
 * @date 2024-07-19
 *
 * @copyright Copyright (c) 2024
 *
 */


// #### Qt inclusions: ####
# include <QApplication>
# include <QBoxLayout>
# include <QHBoxLayout>
# include <QLabel>
# include <QMainWindow>
# include <QPropertyAnimation>
# include <QPushButton>
# include <QScrollBar>
# include <QSize>
# include <QString>
# include <QTextEdit>
# include <QVBoxLayout>
# include <QWidget>
# include <QMenu>
# include <QAction>

// #### Std inclusions: ####
# include <iostream>
# include <string>
using namespace std;

// #### Intern inclusions: ####
# include "../header/gui.hpp"
# include "../header/convert.hpp"


GUI::GUI()
{
  buildButtons();
  buildBars();
  buildLayouts();
  buildTranslateBox();
  buildMenus();
  buildAnimations();
  buildNotification();
  buildStyle();
};


void GUI::buildBars()
{
  closeButton.setParent(&topBar);
  encyclopediaButton.setParent(&topBar);
  radioButton.setParent(&topBar);
  settingsButton.setParent(&topBar);

  textButton.setParent(&bottomBar);
  fileButton.setParent(&bottomBar);
  materialButton.setParent(&bottomBar);
  flashButton.setParent(&bottomBar);

}


void GUI::buildLayouts()
{
  topLayout.addWidget(&encyclopediaButton);
  topLayout.addWidget(&radioButton);
  topLayout.addStretch();
  topLayout.addWidget(&notificationBox);
  topLayout.addStretch();
  topLayout.addWidget(&settingsButton);
  topLayout.addWidget(&closeButton);
  topLayout.setSpacing(0);
  topLayout.setContentsMargins(8, 8, 8, 8);
  topLayout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
  topBar.setLayout(&topLayout);

  translateTextLayout.addWidget(&inputTextBox);
  translateTextLayout.addWidget(&warningLabel);
  translateTextLayout.addWidget(&switchBox);
  translateTextLayout.addWidget(&outputTextBox);
  translateTextLayout.setContentsMargins(8, 8, 8, 8);
  translateTextLayout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
  translateTextBox.setLayout(&translateTextLayout);

  bottomLayout.addWidget(&textButton);
  bottomLayout.addWidget(&fileButton);
  bottomLayout.addWidget(&materialButton);
  bottomLayout.addWidget(&flashButton);
  bottomLayout.setSpacing(0);
  bottomLayout.setContentsMargins(8, 8, 8, 8);
  bottomLayout.setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
  bottomBar.setLayout(&bottomLayout);

  notificationIcon.setParent(&notificationBox);
  notificationText.setParent(&notificationBox);
  notificationLayout.addWidget(&notificationIcon);
  notificationLayout.addWidget(&notificationText);
  notificationLayout.setSpacing(0);
  notificationLayout.setContentsMargins(0, 0, 0, 0);
  notificationLayout.setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
  notificationBox.setLayout(&notificationLayout);

  // tmpLayout.addWidget(&notificationBox);
  // tmpLayout.addStretch();

  mainLayout.addWidget(&topBar);
  mainLayout.addWidget(&translateTextBox);
  mainLayout.addWidget(&bottomBar);
  mainLayout.setSpacing(0);
  mainLayout.setContentsMargins(0, 0, 0, 0);
  this->setLayout(&mainLayout);
}


void GUI::buildButtons()
{
  closeButton.setObjectName("closeButton");
  this->connect(&closeButton, &QPushButton::clicked, this,
                &QApplication::quit);
  encyclopediaButton.setObjectName("encyclopediaButton");
  encyclopediaButton.setToolTip("open the knowledge book");
  radioButton.setObjectName("radioButton");
  radioButton.setToolTip("open the broadcast center");
  settingsButton.setObjectName("settingsButton");
  textButton.setObjectName("textButton");
  this->connect(&textButton, &QPushButton::clicked, this,
                &GUI::switchToTextMode);
  fileButton.setObjectName("fileButton");
  this->connect(&fileButton, &QPushButton::clicked, this,
                &GUI::switchToFileMode);
  materialButton.setObjectName("materialButton");
  this->connect(&materialButton, &QPushButton::clicked, this,
                &GUI::switchToMaterialMode);
  flashButton.setObjectName("flashButton");
  this->connect(&flashButton, &QPushButton::clicked, this,
                &GUI::switchToFlashMode);
}


void GUI::buildStyle()
{
  this->setMinimumSize(400, 400);
  this->setStyleSheet(
    "QWidget {color: #FFFFFF; background-color: #242424;}"
    "QToolTip {background-color: #060606; color: #FFFFFF; border: 1px "
    "solid #FFFFFF; border-radius: 0.3em; padding: 0.1em;}"
    "QAbstractScrollArea::corner { background: none; border: none;}"
    "QScrollBar {background-color: #2E2E2E;} QScrollBar::handle"
    "{background-color: #202020; border: none; border-radius: 5px; margin: 0.1em; width: 1em;}"
    "QScrollBar::up-arrow, QScrollBar::down-arrow {border: none; width: 0; height: 0; background: none;}"
    "QScrollBar::sub-line, QScrollBar::add-line { border: none; background: none; height: 0px; subcontrol-origin: margin;}"
    "QTextEdit {font-size: 24px; background-color: #2E2E2E; margin: 0"
    "0.5em; border-radius: 0.35em; padding: 0.5em 0.25em 0.25em 0.5em;}"
    "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: "
    "0.8em; border: none;}"
    "QPushButton:hover {background-color: #454545;}"
    // "QMenu::item {border-radius: 3px; margin: 0.2em; padding: 0.2em; font-size: 16px;}"// background-color: 060606; color: #FFFFFF;}"

    "#warningLabel {color: #FD1D58; font-size: 16px; margin: 0.25em}"
    
    "#closeButton {border-radius: 0.71em; padding: 0.25em 0.4em;}"
    "#settingsButton, #radioButton, #encyclopediaButton {border-radius: "
    "0.35em; padding: 0.3em 0.5em; background-color: 242424;}"
    "#settingsButton:hover, #radioButton:hover, #encyclopediaButton:hover "
    "{background-color: #2D2D2D;}"
    "#settingsButton {margin: 0 0.5em 0 0;}"
    "#encyclopediaButton {margin: 0 0.5em 0 0; font-size: 14px;}"
    "#swapButton {margin: 0.25em; border-radius: 0.71em; font-size: 32px; "
    "padding: 0.2em 0.4em;}"

    "#textButton, #fileButton, #materialButton, #flashButton {margin: "
    "0.1em;}"
    "#textButton {border-top-left-radius: 0.7em;}"
    "#fileButton, #materialButton {font-size: 19px; padding: 0.56em}"
    "#flashButton {border-top-right-radius: 0.7em;}"

    "#notificationBox {border-radius: 0.35em; padding: 0.5em; background-color: #181818;}"
    "#notificationText {padding: 0.25em; background-color: #181818; margin-right: 0.25em;}"
    "#notificationIcon {padding: 0.25em; background-color: #181818; margin-left: 0.25em; color: #FFFFFF; font-size: 16px;}"

);

  int bottomButtonSize = 55;

  textButton.setFixedWidth(bottomButtonSize);
  textButton.setFixedHeight(bottomButtonSize);

  fileButton.setFixedWidth(bottomButtonSize);
  fileButton.setFixedHeight(bottomButtonSize);

  materialButton.setFixedWidth(bottomButtonSize);
  materialButton.setFixedHeight(bottomButtonSize);

  flashButton.setFixedWidth(bottomButtonSize);
  flashButton.setFixedHeight(bottomButtonSize);
}


void GUI::buildTranslateBox()
{
  outputTextBox.setPlaceholderText("Read");
  outputTextBox.setReadOnly(true);
  inputTextBox.setPlaceholderText("Write");
  swapButton.setObjectName("swapButton");
  warningLabel.setAlignment(Qt::AlignHCenter);
  warningLabel.setObjectName("warningLabel");
  warningLabel.setVisible(false);
  warningLabel.setWordWrap(true);
  switchBox.setLayout(&sbLayout);
  sbLayout.addWidget(&swapButton);
  sbLayout.setAlignment(Qt::AlignHCenter);
  sbLayout.setContentsMargins(0, 0, 0, 0);
  sbLayout.setSpacing(0);
  switchToTextMode();
  connect(&inputTextBox, &QTextEdit::textChanged, this, &GUI::inputChanged);
  connect(&swapButton, &QPushButton::clicked, this, &GUI::swapTextBoxes);
}


void GUI::buildAnimations()
{
  swapAnimation.setDuration(5000);
  swapAnimation.setStartValue("QPushButton {color: red;}");
  swapAnimation.setEndValue("QPushButton {color: green;}");
}

void GUI::buildNotification()
{
  notificationBox.setParent(&topBar);
  notificationIcon.setText("");
  notificationIcon.setStyleSheet("#notificationIcon {color: #FFFFFF;}");
  notificationIcon.setObjectName("notificationIcon");
  notificationIcon.setParent(&notificationBox);
  notificationText.setText("this is a notification");
  notificationText.setObjectName("notificationText");
  notificationText.setParent(&notificationBox);
  notificationBox.setObjectName("notificationBox");
  notificationBox.show();
}

void GUI::buildMenus()
{

}

void GUI::inputChanged()
{
  const wstring& inputText = this->inputTextBox.toPlainText().toStdWString();
  const QString newQstring = QString::fromStdWString(
      inputIsMorse ? Decoder::convert(inputText) : Encoder::convert(inputText)
  );
  int scrollPosition = outputTextBox.verticalScrollBar()->value();
  outputTextBox.setPlainText(newQstring);
  outputTextBox.verticalScrollBar()->setValue(scrollPosition);
  warningLabel.setVisible((inputIsMorse ? newQstring.toStdString().size() : inputText.size()) > 1000);
}


void GUI::notify(const QString& content, const char type, const int duration)
{
  // init the notification box
  if (content.size() > 64)
  {
    cout << "[ERR] cannot display notification with 64 or more characters" << endl;
    return;
  } else if (not content.size())
  {
    cout << "[ERR] cannot display empty notification" << endl;
    return;
  }
  switch (type)
  {
    case 0: // neutral
      notificationIcon.setText("");
      notificationIcon.setStyleSheet("#notificationIcon {color: #FFFFFF;}");
      break;
    case 1: // error
      notificationIcon.setText("");
      notificationIcon.setStyleSheet("#notificationIcon {color: #FD1D58;}");
      break;
    case 2: // warning
      notificationIcon.setText("");
      notificationIcon.setStyleSheet("#notificationIcon {color: #FCD71C;}");
      break;
    case 3: // success
      notificationIcon.setText("");
      notificationIcon.setStyleSheet("#notificationIcon {color: #3FE28B;}");
      break;
    case 4: // info
      notificationIcon.setText("");
      notificationIcon.setStyleSheet("#notificationIcon {color: #9258EA;}");
      break;
    case 5: // question
      notificationIcon.setText("󰠗");
      notificationIcon.setStyleSheet("#notificationIcon {color: #9258EA;}");
      break;
    default:
      cout << "[ERR] unknown type for notification (should be 0 -> 5)" << endl;
      return;
  }
  notificationText.setText(content);
  notificationBox.show();

  // run the animation 
}

void GUI::switchToTextMode()
{
  if (currentMode == 0)
  {
    return; // Abort
  }
  currentMode = 0;

  textButton.setStyleSheet("QPushButton {background-color: #724DC7;}");
  fileButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  materialButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  flashButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");

  notify(QString("hello"), 5, 10);

  translateTextBox.show();
}


void GUI::switchToFileMode()
{
  if (currentMode == 1)
  {
    return; // Abort
  }
  currentMode = 1;

  fileButton.setStyleSheet("QPushButton {background-color: #724DC7;}");
  textButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  materialButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  flashButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");

  notify(QString("hello"), 4, 10);

  translateTextBox.hide();
}


void GUI::switchToMaterialMode()
{
  if (currentMode == 2)
  {
    return; // Abort
  }
  currentMode = 2;

  materialButton.setStyleSheet("QPushButton {background-color: #724DC7;}");
  fileButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  textButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  flashButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");

  notify(QString("hello"), 1, 10);

  translateTextBox.hide();
}


void GUI::switchToFlashMode()
{
  if (currentMode == 3)
  {
    return; // Abort
  }
  currentMode = 3;

  flashButton.setStyleSheet("QPushButton {background-color: #724DC7;}");
  fileButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  materialButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");
  textButton.setStyleSheet("QPushButton {background-color: #2E2E2E} QPushButton:hover {background-color: #454545}");

  notify(QString("hello"), 2, 10);


  translateTextBox.hide();
}


void GUI::swapTextBoxes()
{
  swapAnimation.start();
  inputIsMorse = not inputIsMorse;
  const QString previousInput = inputTextBox.toPlainText();

  if (inputIsMorse)
  {
    inputTextBox.setPlainText(outputTextBox.toPlainText());
    outputTextBox.setPlainText(previousInput.toLower());
  } else
  {
    inputTextBox.setPlainText(outputTextBox.toPlainText().toLower());
    outputTextBox.setPlainText(previousInput);
  }
}