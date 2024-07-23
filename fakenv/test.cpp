#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");

    // Make buttons checkable
    button1->setCheckable(true);
    button2->setCheckable(true);

    // Apply style sheet
    QString styleSheet = "QPushButton:checked { background-color: red; }";
    button1->setStyleSheet(styleSheet);
    button2->setStyleSheet(styleSheet);

    layout->addWidget(button1);
    layout->addWidget(button2);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
