/**
 * @file gui.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Source file of the GUI (Qt)
 * @version 0.1
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// #### Qt inclusions: ####
# include <QApplication>
# include <QHBoxLayout>
# include <QMainWindow>
# include <QPropertyAnimation>
# include <QPushButton>
# include <QVBoxLayout>
# include <QWidget>
# include <QBoxLayout>
# include <QSize>
# include <QString>
# include <QTextEdit>
# include <QLabel>


// #### Std inclusions: ####
# include <string>
# include <iostream>
using namespace std;


// #### Intern inclusions: ####
# include "source/convert.hpp"


class inputBox : public QWidget {
    // Here we have the box where characters are written for translation (base: english)
    // += SOS button, += settings button
public:
    inputBox () {

    }
private:
    QWidget main, buttonsBar, settingsBar;
    QTextEdit textBox;
    QPushButton settingsButton = QPushButton("settings"), emergencyButton = QPushButton("emergency");
};

class GUI : public QWidget {
public:
    GUI () {
        buildStyle ();
        buildButtons ();
        buildBars ();
        buildLayouts ();
        buildTranslateBox ();
    };

private:
    // #### Attributes: ####
    QWidget bottomBar, topBar, translateBox, switchBox;
    QVBoxLayout mainLayout, translateLayout;
    QHBoxLayout bottomLayout, topLayout, sbLayout;
    QPushButton closeButton = QPushButton(""), encyclopediaButton = QPushButton(""), radioButton = QPushButton("󰜟"), settingsButton = QPushButton(""),textButton = QPushButton(""), fileButton = QPushButton("󰈙"), materialButton = QPushButton("󰳽"), flashButton = QPushButton(""), swapButton = QPushButton("󰯎");
    QTextEdit inputTextBox, outputTextBox;
    QLabel warningLabel = QLabel("File mode is recommended for processing large amounts of data.");

    bool inputIsMorse = false;
    char currentMode = 0; // 0: text mode, 1: file mode, 2: material mode, 3: flash mode

    // #### Building methods: ####
    void buildBars () {
        closeButton.setParent(&topBar);
        encyclopediaButton.setParent(&topBar);
        radioButton.setParent(&topBar);
        settingsButton.setParent(&topBar);

        textButton.setParent(&bottomBar);
        flashButton.setParent(&bottomBar);
    }

    void buildLayouts () {
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

    void buildButtons () {
        closeButton.setObjectName("closeButton");
        this->connect(&closeButton, &QPushButton::clicked, this, &QApplication::quit);
        encyclopediaButton.setObjectName("encyclopediaButton");
        encyclopediaButton.setToolTip("open the knowledge book");
        radioButton.setObjectName("radioButton");
        radioButton.setToolTip("open the broadcast center");
        settingsButton.setObjectName("settingsButton");
        textButton.setObjectName("textButton");
        this->connect(&textButton, &QPushButton::clicked, this, &GUI::switchToTextMode);
        fileButton.setObjectName("fileButton");
        this->connect(&fileButton, &QPushButton::clicked, this, &GUI::switchToFileMode);
        materialButton.setObjectName("materialButton");
        this->connect(&materialButton, &QPushButton::clicked, this, &GUI::switchToMaterialMode);
        flashButton.setObjectName("flashButton");
        this->connect(&flashButton, &QPushButton::clicked, this, &GUI::switchToFlashMode);
    }

    void buildStyle () {
        this->setMinimumSize(400, 400);
        this->setStyleSheet(
        "QWidget {color: #FFFFFF; background-color: #242424;}"
        "QToolTip {background-color: #060606; color: #FFFFFF; border: 1px solid #FFFFFF; border-radius: 0.3em; padding: 0.1em;}"
        "QTextEdit {font-size: 24px; background-color: #2E2E2E; margin: 0 0.5em; border-radius: 0.71em; padding: 0.5em;}"
        "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: 0.8em; border: none;}"// border-radius: 0.7em;}"
        "QPushButton:hover {background-color: #454545;}"

        "#warningLabel {color: #FD1D58; font-size: 16px;}"

        "#closeButton {border-radius: 0.71em; padding: 0.25em 0.4em;}"
        "#settingsButton, #radioButton, #encyclopediaButton {border-radius: 0.35em; padding: 0.3em 0.5em; background-color: 242424;}"
        "#settingsButton:hover, #radioButton:hover, #encyclopediaButton:hover {background-color: #2D2D2D;}"
        "#settingsButton {margin: 0 0.5em 0 0;}"
        "#encyclopediaButton {margin: 0 0.5em 0 0; font-size: 14px;}"
        "#swapButton {margin: 0.25em; border-radius: 0.71em; font-size: 32px; padding: 0.2em 0.4em;}"

        "#textButton {border-top-left-radius: 0.7em; padding-left: 0.9em; padding-right: 0.8em;}"
        "#textButton, #fileButton, #materialButton, #flashButton {margin: 0.1em;}"
        "#fileButton, #materialButton {font-size: 19px; padding: 0.56em}"
        "#flashButton {border-top-right-radius: 0.7em;}"
        );
    }

    void buildTranslateBox () {
        outputTextBox.setReadOnly(true);
        swapButton.setObjectName("swapButton");
        warningLabel.setAlignment(Qt::AlignHCenter);
        warningLabel.setObjectName("warningLabel");
        warningLabel.setVisible(false);
        switchBox.setLayout(&sbLayout);
        sbLayout.addWidget(&swapButton);
        sbLayout.setAlignment(Qt::AlignHCenter);
        sbLayout.setContentsMargins(0, 0, 0, 0);
        sbLayout.setSpacing(0);
        switchToTextMode();
        connect(&inputTextBox, &QTextEdit::textChanged, this, &GUI::inputChanged);
        connect(&swapButton, &QPushButton::clicked, this, &GUI::swapTextBoxes);
    }

    // #### Button actions:
    void inputChanged () {
        const string& inputText = this->inputTextBox.toPlainText().toStdString(), letterSep = " ", wordSep = "  ";
        const char longSignal = '-', shortSignal = '.';
        const QString newQstring = QString::fromStdString(inputIsMorse ? convertMorse(inputText, shortSignal, longSignal, letterSep, wordSep) : convertText(inputText, shortSignal, longSignal, letterSep, wordSep));
        outputTextBox.setPlainText(newQstring);
        warningLabel.setVisible(inputText.size() > 300);
        //this->outputTextBox.setPlainText(QString::fromStdString(convertMorse(englishText)));
    }

    void switchToTextMode () {
        textButton.setStyleSheet("background-color: #7B7BF3;");
        fileButton.setStyleSheet("background-color: #2E2E2E");
        materialButton.setStyleSheet("background-color: #2E2E2E");
        flashButton.setStyleSheet("background-color: #2E2E2E");
    }

    void switchToFileMode () {
        fileButton.setStyleSheet("background-color: #7B7BF3;");
        textButton.setStyleSheet("background-color: #2E2E2E");
        materialButton.setStyleSheet("background-color: #2E2E2E");
        flashButton.setStyleSheet("background-color: #2E2E2E");
    }

    void switchToMaterialMode () {
        materialButton.setStyleSheet("background-color: #7B7BF3;");
        fileButton.setStyleSheet("background-color: #2E2E2E");
        textButton.setStyleSheet("background-color: #2E2E2E");
        flashButton.setStyleSheet("background-color: #2E2E2E");
    }

    void switchToFlashMode () {
        flashButton.setStyleSheet("background-color: #7B7BF3;");
        fileButton.setStyleSheet("background-color: #2E2E2E");
        materialButton.setStyleSheet("background-color: #2E2E2E");
        textButton.setStyleSheet("background-color: #2E2E2E");
    }

    void swapTextBoxes () {
        inputIsMorse = not inputIsMorse;
        const QString previousInput = inputTextBox.toPlainText();
        inputTextBox.setPlainText(outputTextBox.toPlainText());
        outputTextBox.setPlainText(previousInput);
    }
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI window;
    window.show();
    int code = app.exec();
    return code;
}
