# include <QApplication>
# include <QHBoxLayout>
# include <QMainWindow>
# include <QPropertyAnimation>
# include <QPushButton>
# include <QVBoxLayout>
# include <QWidget>
# include <QBoxLayout>
# include <QSize>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //app.setStyleSheet("* {border: 1px solid red;}"); //< debug

    // Window style:
    QWidget GUI;
    GUI.setMinimumSize(QSize(200, 100));
    GUI.setStyleSheet(
    "QWidget {color: #FFFFFF; background-color: #242424;}"
    "QPushButton {font-size: 16px; background-color: #2E2E2E; padding: 0.8em; border: none; border-radius: 0.7em;}"
    "QPushButton:hover {background-color: #454545;}"
    "#closeButton {border-radius: 0.71em; padding: 0.25em 0.4em;}"
    "#settingsButton, #radioButton, #encyclopediaButton {padding: 0.3em 0.5em; background-color: 242424;}"
    "#encodingButton {margin-left: 0.25em;}"
    "#decodingButton {margin-right: 0.25em;}"
    );

    // Operation buttons:
    QWidget operationButtons;
    QPushButton* decodingButton = new QPushButton("Read morse", &operationButtons);
    decodingButton->setObjectName("decodingButton");
    QPushButton* encodingButton = new QPushButton("Write morse", &operationButtons);
    encodingButton->setObjectName("encodingButton");
    QLayout* operationLayout = new QHBoxLayout;
    operationLayout->addWidget(decodingButton);
    operationLayout->addWidget(encodingButton);
    operationLayout->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    operationLayout->setSpacing(0);
    operationLayout->setContentsMargins(8, 8, 8, 8);
    operationButtons.setLayout(operationLayout);

    // Top bar:
    QWidget topBar;
    QPushButton* closeButton = new QPushButton("", &topBar);
    closeButton->setObjectName("closeButton");
    QPushButton* settingsButton = new QPushButton("", &topBar);
    settingsButton->setObjectName("settingsButton");
    QPushButton* radioButton = new QPushButton("", &topBar);
    radioButton->setObjectName("radioButton");
    QPushButton* encyclopediaButton = new QPushButton("", &topBar);
    encyclopediaButton->setObjectName("encyclopediaButton");

    GUI.connect(closeButton, &QPushButton::clicked, &GUI, &QApplication::quit);
    QBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(encyclopediaButton);
    topLayout->addWidget(radioButton);
    topLayout->addStretch(1000);
    topLayout->addWidget(settingsButton);
    topLayout->addWidget(closeButton);
    topLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    topLayout->setSpacing(0);
    topLayout->setContentsMargins(8, 8, 8, 8);
    topBar.setLayout(topLayout);

    QLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(&topBar);
    mainLayout->addWidget(&operationButtons);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    GUI.setLayout(mainLayout);
    GUI.show();

    int code = app.exec();

    delete mainLayout;
    delete topLayout;
    delete closeButton;
    delete operationLayout;
    delete decodingButton;
    delete encodingButton;

    return code;
}
