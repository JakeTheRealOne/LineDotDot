#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class GUI : public QWidget {
    Q_OBJECT // Nécessaire pour toute classe qui définit des slots

public:
    GUI(QWidget *parent = nullptr) : QWidget(parent) {
        buildButtons();
    }

private slots: // Slots personnalisés
    void closeApplication() {
        QApplication::quit();
    }

private:
    void buildButtons() {
        QPushButton *closeButton = new QPushButton("Fermer", this);
        // ... Configuration du bouton

        // Connexion du signal au slot personnalisé
        connect(closeButton, &QPushButton::clicked, this, &GUI::closeApplication);

        // ... Ajout du bouton à un layout, etc.
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GUI gui;
    gui.show();
    return app.exec();
}
