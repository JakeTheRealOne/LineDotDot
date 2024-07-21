# include <chrono>
# include <random>
# include "../source/convert.hpp"

const int NUM_CHARACTERS = 10000000;
const char CHARACTERS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.?,;=()";
const int CHARSET_SIZE = sizeof(CHARACTERS) - 1;  // Exclude the null terminator

char getRandomCharacter()
{
  return CHARACTERS[rand() % CHARSET_SIZE];
}

void longFormatTest()
{
  std::srand(static_cast<unsigned int>(std::time(0)));

    string myString;

    // Generate and write random characters to the file
    for (int i = 0; i < NUM_CHARACTERS; ++i) {
        myString.push_back(getRandomCharacter());
    }
    const string morse = convertText(myString, '.', '-', " ", "  ");
    // Capture le point de départ
    auto start = chrono::high_resolution_clock::now();

    // Appel de la fonction dont on veut mesurer le temps d'exécution
    convertMorse(morse);

    // Capture le point de fin
    auto end = chrono::high_resolution_clock::now();

    // Calcul de la durée
    chrono::duration<double> duration = end - start;

    // Affichage du temps d'exécution en secondes
    cout << "Runtime: " << duration.count() << " secondes" << endl;

}

int main() {

    return 0;
}