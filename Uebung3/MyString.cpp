#include <memory>
#include <algorithm>
#include "Mystring.h"

using namespace std;

String::String() :m_len(0), m_start(0), m_string(shared_ptr<char>(unique_ptr<char[]>(new char[0]))) {

	cout << "Standard-Constructor: " << *this << endl;
}
String::String(const String& s) {
	m_len = s.m_len;
	m_start = s.m_start;
	m_string = s.m_string;
	cout << "Copy-Constructor: " << s << endl;
}
String::String(const char* s) {
	m_start = 0;
	m_len = strlen(s);
	m_string = unique_ptr<char[]>(new char[m_len]);
	memcpy(m_string.get(), s, m_len);
	cout << "Convert-Constructor: " << s << endl;
}

//move constructor
String::String(String&& s) : m_string(s.m_string), m_start(s.m_start), m_len(s.m_len) {
	cout << "Move-Constructor: " << s << endl;
}
String::~String() {
	cout << "Destroy: " << *this << endl; 
	m_string = nullptr; }

char String::charAt(size_t index) const {
	if (index < m_len) {
		return m_string.get()[index + m_start];
	}
	else {
		throw out_of_range("Failed");
	}
}

int String::compareTo(const String& s) const {
	size_t size = min(m_len, s.m_len);
	for (size_t i = 0; i < size; i++)
	{
		if (tolower(charAt(i)) > tolower(s.charAt(i))) {
			return 1;
		}
		else if (tolower(charAt(i)) < tolower(s.charAt(i))) {
			return -1;
		}
	}
	return 0;
}

String String::concat(char c) const {
	char tmpArr[2] = { c, '\0' };
	return concat(String(tmpArr));
}

String String::concat(const String& s) const {
	//string to return
	String newString;
	newString.m_start = 0;
	//total length of both strings
	newString.m_len = m_len + s.m_len;
	//initialize content
	newString.m_string = unique_ptr<char[]>(new char[newString.m_len]);
	//fill the new String
	memcpy(newString.m_string.get(), m_string.get() + m_start, m_len);
	memcpy(newString.m_string.get() + m_len, s.m_string.get() + s.m_start, s.m_len);
	return newString;
}

size_t String::length() const {
	return m_len;
}

String String::substring(size_t beg, size_t end) const {
	if (beg >= m_len || end <= beg) { return String(); }
	String tmp(*this);
	tmp.m_len = end - beg;
	tmp.m_start += beg;
	return tmp;
}

unique_ptr<char[]> String::toCString() const {
	unique_ptr<char[]> r(new char[m_len + 1]);
	memcpy(r.get(), m_string.get() + m_start, m_len);
	r[m_len] = '\0';
	return move(r);
}

String String::valueOf(int i) {
	char chars[50]; int k = 0;
	if (i == 0) { chars[k] = '0'; ++k; }
	else {
		bool minus = i < 0;
		while (i != 0) {
			chars[k] = ('0' + abs((i % 10)));
			i /= 10;
			++k;
		}
		if (minus) { chars[k] = '-'; ++k; }
	}
	reverse(chars, chars + k);
	return String(chars);
}