#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>
#include <ctime>

class Auto {
private:
    std::string SPZ;
    double spotrebaPaliva;
    int rokVyroby;

    static int ZjistiAktualniRok();

    static bool PlatnaSPZ(const std::string& spz);

public:
    Auto(const std::string& SPZ, double spotrebaPaliva, int rokVyroby);

    Auto(const Auto& other);

    int ZjistiStariVozu() const;

    std::string GetSPZ() const;

    double GetSpotrebaPaliva() const;

    int GetRokVyroby() const;

    void SetSPZ(const std::string& newSPZ);

    void SetSpotrebaPaliva(double newSpotrebaPaliva);

    void SetRokVyroby(int newRokVyroby);

    friend std::ostream& operator<<(std::ostream& os, const Auto& autoObj);
};

#endif // AUTO_H
