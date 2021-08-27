/*
String 클래스의 선언 파일
*/
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* _str);
	String(const String& _String);
	~String();
	String& operator=(const String& _String);
	String operator+(const String& _String);
	String& operator+=(const String& _String);
	bool operator==(const String& _String);
	/*
	>>, <<연산사를 멤버함수로 오버로딩을 하려면 istream과 ostream 클래스를 수정해야 하는데 이는 불가능하다.
	따라서 friend키워드를 통해 전역함수를 가져와서 사용하도록 한다.
	*/
	friend istream& operator>> (istream& in, String& _String);
	friend ostream& operator<< (ostream& out, const String& _String);
};
#endif