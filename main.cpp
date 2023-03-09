#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "9.hpp"

int main() 
{
    Zahl9 a, b;
    
    int fakul;
    int op;

    std::string temp;
    std::string dateiname;
    
    std::cout << "Dateiname: \n";
    std::cin >> dateiname;

    std::ifstream input(dateiname);

    std::unordered_map<std::string, int> zeichenfolge_zu_codieren 
    {
      {"+", 1},
      {"-", 2},
      {"*", 3},
      {"==", 4},
      {"!=", 5},
      {"<", 6},
      {">", 7},
      {"fak", 8},
    };

    if (!input.is_open()) 
    {
        std::cout << "Fehler beim Oeffnen der Datei " << dateiname << "\n";
        std::cout << "Funktionen: \n";
        std::cout << "1. +\n";
        std::cout << "2. -\n";
        std::cout << "3. *\n";
        std::cout << "4. ==\n";
        std::cout << "5. !=\n";
        std::cout << "6. <\n";
        std::cout << "7. >\n";
        std::cout << "8. fak\n";

        std::cout << "Geben Sie Nummer der notwendigen Operator ein: ";

        std::cin >> op;
        if (op != 8)
        {
            std::cout << "Geben sie A ein: ";
            std::cin >> a;
            std::cout << "Geben sie B ein: ";
            std::cin >> b;
        }
        else
        {
            std::cout << "Geben sie A ein: ";
            std::cin >> fakul;
        }
    }
    else 
    {
        input >> temp;
        op = zeichenfolge_zu_codieren[temp];

        if (zeichenfolge_zu_codieren.count(temp) == 0) {
            std::cout << "Unbekannter typ: " << temp << std::endl;
            return 1;
        }

        if (op != 8)
        {
            if (!(input >> a >> b)) 
            {
                std::cout << "Falsche Daten" << std::endl;
                return 1;
            }
        }
        else
        {
            if (!(input >> fakul)) 
            {
                std::cout << "Falsche Daten" << std::endl;
                return 1;
            }
        } 
    }
    
    switch (op) 
    {
        case 1:
            std::cout << a << " + " << b << " = " << a + b << '\n';
            break;
        case 2:
            std::cout << a << " - " << b << " = " << a - b.ziffern_[0] << '\n';
            break;
        case 3:
            std::cout << a << " * " << b << " = " << a * b.ziffern_[0] << '\n';
            break;
        case 4:
            std::cout << a << " == " << b << " : " << (a == b ? "true\n" : "false\n");
            break;
        case 5:
            std::cout << a << " != " << b << " : " << (a != b ? "true\n" : "false\n");
            break;
        case 6:
            std::cout << a << " < " << b << " : " << (a < b ? "true\n" : "false\n");
            break;
        case 7:
            std::cout << a << " > " << b << " : " << (a > b ? "true\n" : "false\n");
            break;
        case 8:
            std::cout << "Fakultaet von " << fakul <<" = " << Zahl9::fak(fakul) << "\n";
            break;
        default:
            std::cout << "Unbekannter typ." << std::endl;
            break;
    }

    return 0;
}
