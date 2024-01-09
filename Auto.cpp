#include "Auto.h"

int Auto::ZjistiAktualniRok() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

bool Auto::PlatnaSPZ(const std::string& spz) {
    if (spz.length() != 7)
        return false;

    for (char ch : spz) {
        if (!(std::isalpha(ch) && std::isupper(ch) && ch != 'G' && ch != 'O' && ch != 'Q' && ch != 'W') && !std::isdigit(ch))
            return false;
    }

    return true;
}

Auto::Auto(const std::string& SPZ, double spotrebaPaliva, int rokVyroby) : SPZ(""), spotrebaPaliva(0.0), rokVyroby(0) {
    SetSPZ(SPZ);
    SetSpotrebaPaliva(spotrebaPaliva);
    SetRokVyroby(rokVyroby);
}

Auto::Auto(const Auto& other) : SPZ(other.SPZ), spotrebaPaliva(other.spotrebaPaliva), rokVyroby(other.rokVyroby) {}

int Auto::ZjistiStariVozu() const {
    return ZjistiAktualniRok() - rokVyroby;
}

std::string Auto::GetSPZ() const {
    return SPZ;
}

double Auto::GetSpotrebaPaliva() const {
    return spotrebaPaliva;
}

int Auto::GetRokVyroby() const {
    return rokVyroby;
}

void Auto::SetSPZ(const std::string& newSPZ) {
    if (PlatnaSPZ(newSPZ)) {
        SPZ = newSPZ;
    } else {
        std::cerr << "Neplatna SPZ." << std::endl;
    }
}

void Auto::SetSpotrebaPaliva(double newSpotrebaPaliva) {
    if (newSpotrebaPaliva >= 0.0) {
        spotrebaPaliva = newSpotrebaPaliva;
    } else {
        std::cerr << "Spotreba paliva musi byt nezaporna hodnota." << std::endl;
    }
}

void Auto::SetRokVyroby(int newRokVyroby) {
    int aktualniRok = ZjistiAktualniRok();
    if (newRokVyroby >= 1900 && newRokVyroby <= aktualniRok) {
        rokVyroby = newRokVyroby;
    } else {
        std::cerr << "Rok vyroby musi byt od 1900 do " << aktualniRok << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Auto& autoObj) {
    os << "SPZ: " << autoObj.SPZ << "\n";
    os << "Spotreba paliva: " << autoObj.spotrebaPaliva << " l/100km\n";
    os << "Rok vyroby: " << autoObj.rokVyroby << "\n";
    os << "Stari vozu: " << autoObj.ZjistiStariVozu() << " let\n";
    return os;
}
