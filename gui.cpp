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



class GUI : public QWidget {
private:
    void buildLinks () {
        closeButton.setParent(&topBar);
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


        bottomLayout.addWidget(&encodingButton);
        bottomLayout.addWidget(&decodingButton);
        bottomLayout.setSpacing(0);
        bottomLayout.setContentsMargins(8, 8, 8, 8);
        bottomLayout.setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
        bottomBar.setLayout(&bottomLayout);

        mainLayout.addWidget(&topBar);
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
        settingsButton.setToolTip("open settings");
        encodingButton.setObjectName("encodingButton");
        decodingButton.setObjectName("decodingButton");
    }

    void buildStyle () {
        this->setStyleSheet(
        "QWidget {color: #FFFFFF; background-color: #242424;}"
        "QToolTip {background-color: #060606; color: #FFFFFF; border: 1px solid #FFFFFF; border-radius: 0.3em; padding: 0.1em;}"
        "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: 0.8em; border: none; border-radius: 0.7em;}"
        "QPushButton:hover {background-color: #454545;}"
        "#closeButton {border-radius: 0.71em; padding: 0.25em 0.4em;}"
        "#settingsButton, #radioButton, #encyclopediaButton {border-radius: 0.35em; padding: 0.3em 0.5em; background-color: 242424;}"
        "#settingsButton:hover, #radioButton:hover, #encyclopediaButton:hover {background-color: #2D2D2D;}"
        "#encodingButton {margin-right: 0.25em;}"
        "#decodingButton {margin-left: 0.25em;}"
        "#settingsButton {margin: 0 0.5em 0 0;}"
        "#encyclopediaButton {margin: 0 0.5em 0 0; font-size: 14px;}"
        );
    }

public:
    GUI () {
        buildStyle ();
        buildLinks ();
        buildLayouts ();
        buildButtons ();
    };

private:
    QWidget bottomBar, topBar;
    QVBoxLayout mainLayout;
    QHBoxLayout bottomLayout, topLayout;
    QPushButton closeButton = QPushButton(""), encyclopediaButton = QPushButton(""), radioButton = QPushButton("󰜟"), settingsButton = QPushButton(""), encodingButton = QPushButton("Write morse"), decodingButton = QPushButton("Read morse");
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI window;
    window.show();
    int code = app.exec();
    return code;
}
