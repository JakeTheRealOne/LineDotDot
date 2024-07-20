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
# include <string>
# include "source/convert.hpp"
# include <iostream>
using namespace std;

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
    // #### Attributes:
    QWidget bottomBar, topBar, translateBox;
    QVBoxLayout mainLayout, translateLayout;
    QHBoxLayout bottomLayout, topLayout;
    QPushButton closeButton = QPushButton(""), encyclopediaButton = QPushButton(""), radioButton = QPushButton("󰜟"), settingsButton = QPushButton(""), encodingButton = QPushButton("Write morse"), decodingButton = QPushButton("Read morse"), conversionButton = QPushButton("Convert");
    QTextEdit englishTextBox, morseTextBox;

    // 
    void buildBars () {
        closeButton.setParent(&topBar);
        encyclopediaButton.setParent(&topBar);
        radioButton.setParent(&topBar);
        settingsButton.setParent(&topBar);

        encodingButton.setParent(&bottomBar);
        decodingButton.setParent(&bottomBar);
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

        translateLayout.addWidget(&englishTextBox);
        translateLayout.addWidget(&conversionButton);
        translateLayout.addWidget(&morseTextBox);
        translateLayout.setContentsMargins(8, 8, 8, 8);
        translateLayout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
        translateBox.setLayout(&translateLayout);   

        bottomLayout.addWidget(&encodingButton);
        bottomLayout.addWidget(&decodingButton);
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
        encodingButton.setObjectName("encodingButton");
        decodingButton.setObjectName("decodingButton");
    }

    void buildStyle () {
        this->setMinimumSize(400, 400);
        this->setStyleSheet(
        "QWidget {color: #FFFFFF; background-color: #242424;}"
        "QToolTip {background-color: #060606; color: #FFFFFF; border: 1px solid #FFFFFF; border-radius: 0.3em; padding: 0.1em;}"
        "QTextEdit {font-size: 24px;}"
        "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: 0.8em; border: none;}"// border-radius: 0.7em;}"
        "QPushButton:hover {background-color: #454545;}"
        "#closeButton {border-radius: 0.71em; padding: 0.25em 0.4em;}"
        "#settingsButton, #radioButton, #encyclopediaButton {border-radius: 0.35em; padding: 0.3em 0.5em; background-color: 242424;}"
        "#settingsButton:hover, #radioButton:hover, #encyclopediaButton:hover {background-color: #2D2D2D;}"
        "#encodingButton {border-top-left-radius: 0.7em; margin-right: 0.2em;}"
        "#decodingButton {border-top-right-radius: 0.7em; margin-left: 0.2em;}"
        "#settingsButton {margin: 0 0.5em 0 0;}"
        "#encyclopediaButton {margin: 0 0.5em 0 0; font-size: 14px;}"
        );
    }

    void buildTranslateBox () {
        this->morseTextBox.setReadOnly(true);
        this->connect(&conversionButton, &QPushButton::clicked, this, &GUI::textToMorse);
    }

    // #### Button actions:
    void textToMorse () {
        const string englishText = this->englishTextBox.toPlainText().toStdString(), letterSep = " ", wordSep = "  ";
        const char longSignal = '-', shortSignal = '.';
        const QString newQstring = QString::fromStdString(convertText(englishText, shortSignal, longSignal, letterSep, wordSep));
        this->morseTextBox.setPlainText(newQstring);
        //this->morseTextBox.setPlainText(QString::fromStdString(convertMorse(englishText)));
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
