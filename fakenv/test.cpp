#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>

class NotificationWidget : public QWidget {
public:
    NotificationWidget(QWidget* parent = nullptr) : QWidget(parent) {
        setStyleSheet("background-color: rgba(0, 0, 0, 0.8); color: white; padding: 10px;");
        QLabel* label = new QLabel("This is a notification!", this);
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(label);
        layout->setAlignment(Qt::AlignCenter);
        setLayout(layout);
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget mainWindow;
    mainWindow.setWindowTitle("Main Window");
    mainWindow.resize(800, 600);
    
    QVBoxLayout* mainLayout = new QVBoxLayout(&mainWindow);
    QPushButton* showNotificationButton = new QPushButton("Show Notification", &mainWindow);
    
    NotificationWidget* notification = new NotificationWidget(&mainWindow);
    notification->setGeometry(0, 0, 300, 50);  // Initial size and position, will be adjusted later
    notification->hide();  // Initially hidden

    QObject::connect(showNotificationButton, &QPushButton::clicked, [notification]() {
        notification->show();  // Show the notification when button is clicked
    });

    // Add widgets to mainLayout
    mainLayout->addWidget(showNotificationButton);
    mainLayout->addStretch();  // Stretch to push the button to the top

    // Center notification at the top of the mainWindow
    notification->setGeometry(
        (mainWindow.width() - notification->width()) / 2,  // Center horizontally
        0,  // Top of the mainWindow
        notification->width(),
        notification->height()
    );

    mainWindow.show();

    return app.exec();
}
