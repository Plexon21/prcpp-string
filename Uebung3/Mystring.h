#pragma once
#include <memory>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>

using namespace std;
class String final {
	size_t m_len;
	size_t m_start;
	shared_ptr<char> m_string;
public:
	String();
	String(const String& s);
	String(const char* c);
	String(String&& s);
	~String();

	// Instanz-Methoden
	char charAt(size_t index) const; // bei falschem Index: wirft exception
	int compareTo(const String& s) const; // C++ untypische Funktion: gibt -1, 0, 1 zur�ck
	String concat(char c) const; // h�ngt c ans Ende und gibt neuen String zur�ck
	String concat(const String& s) const;
	size_t length() const; // gibt die L�nge des Strings zur�ck
						   // Substring des Bereichs [beg, end)
						   // falls beg ? m_len oder end ? beg: gibt leeren String zur�ck
	String substring(size_t beg, size_t end) const;
	// erzeugt 0-terminierten C-String, kopiert Inhalt und gibt Zeigerobjekt zur�ck
	unique_ptr<char[]> toCString() const;
	// Gleichheitsoperator (Inline-Implementation schon gegeben)
	bool operator==(const String& s) const { return compareTo(s) == 0; }
	// Ausgabe-Operator f�r Output-Streams (Inline-Implementation schon gegeben)
	friend ostream& operator<<(ostream& os, const String& s) {
		const size_t end = s.m_start + s.m_len;
		const char* const sc = s.m_string.get();
		for (size_t i = s.m_start; i < end; i++) os << sc[i];
		return os;
	}

	// Klassen-Methode
	static String valueOf(int i); // erzeugt eine String-Repr�sentation von i
};