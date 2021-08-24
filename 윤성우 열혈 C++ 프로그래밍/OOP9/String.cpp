/*
String 클래스의 정의 파일
*/
#include <iostream>
#include "String.h"

String::String() {
	len = 0;
	str = NULL;
}

String::String(const char* _str) {
	len = strlen(_str) + 1;
	str = new char[len];
	strcpy(str, _str);
}

String::String(const String& _String) {
	len = _String.len;
	str = new char[len];
	strcpy(str, _String.str);
}

String::~String() {
	if (str != NULL)	delete []str;
}

String& String::operator=(const String& _String) {
	if (str != NULL)	delete []str;
	len = _String.len;
	str = new char[len];
	strcpy(str, _String.str);
	return *this;
}

String String::operator+(const String& _String) {
	char* retstr = new char[len + _String.len - 1];
	strcpy(retstr, str);
	strcat(retstr, _String.str);
	String ret(retstr);
	delete []retstr;
	return ret;
}

String& String::operator+=(const String& _String) {
	len += (_String.len - 1);
	char* retstr = new char[len];
	strcpy(retstr, str);
	strcat(retstr, _String.str);
	if (str != NULL)	delete []str;
	str = retstr;
	return *this;
}

bool String::operator==(const String& _String) {
	if (strcmp(str, _String.str))	return false;
	return true;
}

istream& operator>>(istream& in, String& _String) {
	char str[100];
	in >> str;
	_String = String(str);
	return in;
}

ostream& operator<<(ostream& out, const String& _String) {
	out << _String.str;
	return out;
}
