#include <QApplication>
#include <QWidget>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QWidget widget(&window);
    widget.setFixedSize(0, 100); // Initial size
    window.show();

    QPropertyAnimation animation(&widget, "size");
    animation.setDuration(1000); // Duration in milliseconds
    animation.setStartValue(QSize(0, 100));
    animation.setEndValue(QSize(300, 100));
    animation.setEasingCurve(QEasingCurve::InOutQuad); // Smooth transition
    animation.start();

    return app.exec();
}
