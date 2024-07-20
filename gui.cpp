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
# include <QLabel>
# include <string>
# include "source/convert.hpp"
using namespace std;

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
        fileButton.setObjectName("fileButton");
        materialButton.setObjectName("materialButton");
        flashButton.setObjectName("flashButton");
    }

    void buildStyle () {
        this->setMinimumSize(400, 400);
        this->setStyleSheet(
        "QWidget {color: #FFFFFF; background-color: #242424;}"
        "QToolTip {background-color: #060606; color: #FFFFFF; border: 1px solid #FFFFFF; border-radius: 0.3em; padding: 0.1em;}"
        "QTextEdit {font-size: 24px; background-color: #2E2E2E; margin: 0 0.5em; border-radius: 0.71em; padding: 0.5em;}"
        "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: 0.8em; border: none;}"// border-radius: 0.7em;}"
        "QPushButton:hover {background-color: #454545;}"

        "#warningLabel {color: #FD1D58;}"

        "#closeButton {border-radius: 0.71em; padding: 0.25em 0.4em;}"
        "#settingsButton, #radioButton, #encyclopediaButton {border-radius: 0.35em; padding: 0.3em 0.5em; background-color: 242424;}"
        "#settingsButton:hover, #radioButton:hover, #encyclopediaButton:hover {background-color: #2D2D2D;}"
        "#settingsButton {margin: 0 0.5em 0 0;}"
        "#encyclopediaButton {margin: 0 0.5em 0 0; font-size: 14px;}"
        "#swapButton {margin: 0.25em; border-radius: 0.71em; font-size: 32px; padding: 0.2em 0.4em;}"

        "#textButton {border-top-left-radius: 0.7em;}"
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
        connect(&inputTextBox, &QTextEdit::textChanged, this, &GUI::inputChanged);
    }

    // #### Button actions:
    void inputChanged () {
        const string englishText = this->inputTextBox.toPlainText().toStdString(), letterSep = " ", wordSep = "  ";
        const char longSignal = '-', shortSignal = '.';
        const QString newQstring = QString::fromStdString(convertText(englishText, shortSignal, longSignal, letterSep, wordSep));
        outputTextBox.setPlainText(newQstring);
        warningLabel.setVisible(englishText.size() > 300);
        //this->outputTextBox.setPlainText(QString::fromStdString(convertMorse(englishText)));
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
