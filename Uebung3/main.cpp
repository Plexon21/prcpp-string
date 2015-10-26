#include "MyString.h" // die hier verwende Klasse heisst String
using namespace std; // wird evtl. erst später verwendet
int main() {
	String s = String("ab").concat("cd").concat("ef");/*
    String abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool b = "D"== abc.substring(3, 4).toCString().get();
	String s1 = abc.substring(2, 8);
	String s2 = s1.substring(1, 4);
	String s3 = s2.substring(4, 5);
	cout << "abc: " << abc << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;*/


    cout << s << endl;
}