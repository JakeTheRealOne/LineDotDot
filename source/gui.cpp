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

// #### Std inclusions: ####
# include <iostream>
# include <string>
using namespace std;

// #### Intern inclusions: ####
# include "../header/gui.hpp"
# include "../header/convert.hpp"


GUI::GUI()
{
  buildStyle();
  buildButtons();
  buildBars();
  buildLayouts();
  buildTranslateBox();
};


void GUI::buildBars()
{
  closeButton.setParent(&topBar);
  encyclopediaButton.setParent(&topBar);
  radioButton.setParent(&topBar);
  settingsButton.setParent(&topBar);

  textButton.setParent(&bottomBar);
  flashButton.setParent(&bottomBar);
}


void GUI::buildLayouts()
{
  topLayout.addWidget(&encyclopediaButton);
  topLayout.addWidget(&radioButton);
  topLayout.addStretch();
  topLayout.addWidget(&settingsButton);
  topLayout.addWidget(&closeButton);
  topLayout.setSpacing(0);
  topLayout.setContentsMargins(8, 8, 8, 8);
  topLayout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
  topBar.setLayout(&topLayout);

  translateLayout.addWidget(&inputTextBox);
  translateLayout.addWidget(&warningLabel);
  translateLayout.addWidget(&switchBox);
  translateLayout.addWidget(&outputTextBox);
  translateLayout.setContentsMargins(8, 8, 8, 8);
  translateLayout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
  translateBox.setLayout(&translateLayout);

  bottomLayout.addWidget(&textButton);
  bottomLayout.addWidget(&fileButton);
  bottomLayout.addWidget(&materialButton);
  bottomLayout.addWidget(&flashButton);
  bottomLayout.setSpacing(0);
  bottomLayout.setContentsMargins(8, 8, 8, 8);
  bottomLayout.setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
  bottomBar.setLayout(&bottomLayout);

  mainLayout.addWidget(&topBar);
  mainLayout.addWidget(&translateBox);
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
    "QTextEdit {font-size: 24px; background-color: #2E2E2E; margin: 0 "
    "0.5em; border-radius: 0.35em; padding: 0.5em;}"
    "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: "
    "0.8em; border: none;}"
    "QPushButton:hover {background-color: #454545;}"
    "QScrollBar {border: none; color: #000000; background-color: #242424;}"

    "#warningLabel {color: #FD1D58; font-size: 16px;}"

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
  outputTextBox.setReadOnly(true);
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


void GUI::inputChanged()
{
  const string& inputText = this->inputTextBox.toPlainText().toStdString();
  const QString newQstring = QString::fromStdString(
      inputIsMorse ? Decoder::convert(inputText) : Encoder::convert(inputText)
  );
  int scrollPosition = outputTextBox.verticalScrollBar()->value();
  outputTextBox.setPlainText(newQstring);
  outputTextBox.verticalScrollBar()->setValue(scrollPosition);
  warningLabel.setVisible(inputText.size() > 300);
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
}


void GUI::swapTextBoxes()
{
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