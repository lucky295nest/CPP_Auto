#include "Auto.h"
#include <iostream>
#include <string>

int main() {
    std::string spz;
    double spotrebaPaliva;
    int rokVyroby;

    std::cout << "Vítejte v programu pro ověření třídy Auto!\n";

    do {
        // Vstup SPZ od uživatele
        std::cout << "\nZadejte SPZ (platná SPZ má délku 7 znaků a obsahuje pouze velká písmena abecedy bez diakritiky s výjimkou G, O, Q, W nebo číslice): ";
        std::cin >> spz;

        // Vstup spotřeby paliva od uživatele
        std::cout << "Zadejte spotřebu paliva (kladné číslo): ";
        std::cin >> spotrebaPaliva;

        // Vstup roku výroby od uživatele
        std::cout << "Zadejte rok výroby (starší nebo roven aktuálnímu roku, nesmí být menší než rok 1900): ";
        std::cin >> rokVyroby;

        // Vytvoření instance třídy Auto s uživatelským vstupem
        Auto autoObj(spz, spotrebaPaliva, rokVyroby);

        // Výpis informací o vozidle pomocí přetíženého operátoru <<
        std::cout << "\nInformace o vozidle:\n" << autoObj;

        // Uživatel může opakovat ověření
        std::cout << "\nChcete ověřit další vozidlo? (ano/ne): ";
        std::string volba;
        std::cin >> volba;

        if (volba != "ano")
            break;

    } while (true);

    std::cout << "\nDěkujeme za použití programu. Ukončuji.\n";

    return 0;
}