#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Zahl9 
{
	
public:
	/*
	* Standardkonstruktor.
	*/
	Zahl9();
    /*
	* Kopierkonstruktor.
	* @param andere Objekt zur kopierenden Zahl9
	*/
    Zahl9(const Zahl9& andere);
	/*
	* Konstruktor, der das Objekt mit einer Zeichenfolgendarstellung initialisiert.
	* @param str Die Zeichenfolgendarstellung der Zahl.
	*/
    Zahl9(const std::string& str);
    /*
	* Gibt die Fakultät einer gegebenen Ganzzahl zurück.
	* @param n Die Ganzzahl, von der die Fakultät ermittelt werden soll.
    * @return Gibt die Fakultät von n zurück.
	*/
	static Zahl9 fak(int n);
	/*
	* Addiert zwei Zahl9-Objekte zusammen.
	* @param andere Das Zahl9-Objekt, das zu einem anderen Zahl9-Objekt addiert werden soll.
    * @return Gibt die Summe der beiden Zahl9-Objekte zurück.
	*/
	Zahl9 operator+(const Zahl9& andere) const;
	/*
	* Subtrahiert eine einstellige Zahl,die in 9er-System auch einstellig ist, von einem Zahl9-Objekt.
	* @param andere Eine einstellige Zahl, die von einem Zahl9-Objekt subtrahiert werden soll.
    * @return Gibt die Differenz zwischen ein Zahl9-Objekt und eine einstelligen Zahl zurück.
	*/
	Zahl9 operator-(int n) const;
	/*
	 * Multipliziert ein Zahl9-Objekt mit einer einstelligen Zahl, die in 9er-System auch einstellig ist.
	 * @param n Eine einstellige Zahl, mit der das Zahl9-Objekt multipliziert werden soll
	 * @return Gibt Ergebnis von der Multiplikation Zahl9-Objekt mit einer einstelligen Zahl n zurück
	 */
	Zahl9 operator*(int n) const;
	/*
	* Vergleicht zwei Zahl9-Objekte auf Gleichheit.
	* @param andere Das Zahl9-Objekt, das mit einem anderen Zahl9-Objekt verglichen werden soll.
	* @return Gibt True zurück, wenn die beiden Zahl9-Objekte gleich sind, andernfalls false.
	*/
	bool operator==(const Zahl9& andere) const;
	/*
	* Vergleicht zwei Zahl9-Objekte auf Ungleichheit.
	* @param andere Das Zahl9-Objekt, das mit einem anderen Zahl9-Objekt verglichen werden soll.
	* @return Gibt True zurück, wenn die beiden Zahl9-Objekte nicht gleich sind, andernfalls false.
	*/
	bool operator!=(const Zahl9& andere) const;
	/*
	* Vergleicht zwei Zahl9-Objekte, um festzustellen, ob das erste kleiner als das zweite ist.
	* @param andere Das Zahl9-Objekt, das mit einem anderen Zahl9-Objekt verglichen werden soll.
	* @return Gibt True zurück, wenn dieses Zahl9-Objekt kleiner als das andere ist, andernfalls false.
	*/
	bool operator<(const Zahl9& andere) const;
	/*
	* Vergleicht zwei Zahl9-Objekte, um festzustellen, ob das erste größer als das zweite ist.
	* @param andere Das Zahl9-Objekt, das mit einem anderen Zahl9-Objekt verglichen werden soll.
	* @return Gibt True zurück, wenn dieses Zahl9-Objekt größer als das andere ist, andernfalls false.
	*/
	bool operator>(const Zahl9& andere) const;
	
	/*
	* Überlädt den Operator << für Zahl9-Objekte, um den Ausgabe zu aktivieren.
	* @param os Der Ausgabestream, in den geschrieben werden soll.
	* @param zahl9 Das Zahl9-Objekt, der ausgegeben werden muss
	* @return Gibt den Ausgabestream zurück, in den geschrieben wurde.
	*/
	friend std::ostream& operator<<(std::ostream& os, const Zahl9& zahl9);
	/*
	* Überlädt den Operator >> für Zahl9-Objekte, um das Lesen aus einem Eingabestream zu aktivieren.
	* @param is Der Eingabestream, aus dem gelesen werden soll.
	* @param zahl9 Das Zahl9-Objekt, das mit den gelesenen Werten befüllt werden soll.
	* @return Gibt den Eingabestream zurück, aus dem gelesen wurde.
	*/
	friend std::istream& operator>>(std::istream& is, Zahl9& zahl9);
	
	/*
	Speichern von Zahlen im 9-Zahlensystem
	*/
	std::vector<int> ziffern_;
};
