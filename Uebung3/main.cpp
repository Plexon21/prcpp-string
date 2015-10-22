#include "MyString.h" // die hier verwende Klasse heisst String
using namespace std; // wird evtl. erst später verwendet
int main() {
	String s = String("ab").concat("cd").concat("ef");
	cout << s << endl;
}