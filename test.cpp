#include <iostream>

// Déclaration du namespace
namespace MonNamespace {
    // Déclaration de la fonction
    void maFonction();
}

// Définition de la fonction en dehors du namespace
void MonNamespace::maFonction() {
    std::cout << "Bonjour du namespace MonNamespace!" << std::endl;
}

int main() {
    // Appel de la fonction du namespace
    MonNamespace::maFonction();
    return 0;
}
