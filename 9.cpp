/*
Dokumentation:

Dieser Code definiert die Zah19-Klasse, die eine Zahl zur Basis 9 darstellt.

Die Klasse enthält Konstruktoren, Operatorüberladungen und Stream-Operatoren für die Eingabe / Ausgabe.

Die Klasse kann verwendet werden, um grundlegende arithmetische Operationen wie Addition,
Subtraktion und Multiplikation auszuführen.

Die Implementierung unterstützt Zahlen bis zu 2 100 000 000,
was die größte Zahl ist, die in Basis 9 mit 9 Ziffern dargestellt und als integer gespeichert werden kann.

Die Methode fak() berechnet die Fakultät einer Zahl bis zu 8 ohne Überlauf.
*/

#include "9.hpp"

Zahl9::Zahl9() : ziffern_() {}

Zahl9::Zahl9(const Zahl9& zahl9) : ziffern_(zahl9.ziffern_) {}

Zahl9 Zahl9::operator+(const Zahl9& zahl) const 
{
    Zahl9 ergebnis;
    ergebnis.ziffern_.clear();
    int uebertrag = 0;
    for (long unsigned int i = 0; i < std::max(ziffern_.size(), zahl.ziffern_.size()); ++i) {
        long unsigned int d1 = i < ziffern_.size() ? ziffern_[i] : 0;
        long unsigned int d2 = i < zahl.ziffern_.size() ? zahl.ziffern_[i] : 0;
        long unsigned int summe = d1 + d2 + uebertrag;
        ergebnis.ziffern_.push_back(summe % 9);
        uebertrag = summe / 9;
    }
    if (uebertrag > 0) ergebnis.ziffern_.push_back(uebertrag);
    return ergebnis;
}

Zahl9 Zahl9::operator-(int zahl) const 
{
    Zahl9 ergebnis(*this);
    ergebnis.ziffern_[0] -= zahl;
    for (long unsigned int i = 0; i < ergebnis.ziffern_.size(); ++i) 
    {
        if (ergebnis.ziffern_[i] < 0) 
        {
            ergebnis.ziffern_[i] += 9;
            --ergebnis.ziffern_[i + 1];
        }
    }
    while (ergebnis.ziffern_.size() > 1 && ergebnis.ziffern_.back() == 0)
        ergebnis.ziffern_.pop_back();
    return ergebnis;
}

Zahl9 Zahl9::operator*(int zahl) const 
{
    Zahl9 ergebnis;
    ergebnis.ziffern_.clear();
    int uebertrag = 0;
    for (long unsigned int i = 0; i < ziffern_.size(); ++i) 
    {
        long unsigned int produkt = ziffern_[i] * zahl + uebertrag;
        ergebnis.ziffern_.push_back(produkt % 9);
        uebertrag = produkt / 9;
    }
    if (uebertrag > 0) ergebnis.ziffern_.push_back(uebertrag);
    return ergebnis;
}

bool Zahl9::operator==(const Zahl9& zahl) const 
{
    if (ziffern_.size() != zahl.ziffern_.size()) return false;
    for (long unsigned int i = 0; i < ziffern_.size(); ++i) 
    {
        if (ziffern_[i] != zahl.ziffern_[i]) return false;
    }
    return true;
}

bool Zahl9::operator!=(const Zahl9& zahl) const 
{
    return !(*this == zahl);
}

bool Zahl9::operator<(const Zahl9& zahl) const 
{
    if (ziffern_.size() != zahl.ziffern_.size())
        return ziffern_.size() < zahl.ziffern_.size();
    for (int i = ziffern_.size() - 1; i >= 0; --i) 
    {
        if (ziffern_[i] != zahl.ziffern_[i])
            return ziffern_[i] < zahl.ziffern_[i];
    }
    return false;
}

bool Zahl9::operator>(const Zahl9& zahl) const 
{
    return !(*this < zahl) && !(*this == zahl);
}

std::ostream& operator<<(std::ostream& os, const Zahl9& zahl) 
{
    for (int i = zahl.ziffern_.size() - 1; i >= 0; --i)
        os << zahl.ziffern_[i];
    return os;
}

std::istream& operator>>(std::istream& is, Zahl9& zahl) 
{
    int dezimalzahl;
    is >> dezimalzahl;
    zahl.ziffern_.clear();
    while (dezimalzahl > 0) 
    {
        zahl.ziffern_.push_back(dezimalzahl % 9);
        dezimalzahl /= 9;
    }
    return is;
}

Zahl9::Zahl9(const std::string& zahl) 
{
    std::stringstream ss(zahl);
    int ziffer;
    while (ss >> ziffer) 
    {
        ziffern_.push_back(ziffer);
    }
}

/*
Die maximale Zahl, die die Funktion "fak" ohne Überlauf verarbeiten kann,
ist 8
*/
Zahl9 Zahl9::fak(int z) 
{
    Zahl9 ergebnis("1");
    for (int i = 2; i <= z; i++) 
    {
        ergebnis = ergebnis * i;
    }
    return ergebnis;
}
