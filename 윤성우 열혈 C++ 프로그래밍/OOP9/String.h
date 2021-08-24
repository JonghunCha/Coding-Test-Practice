/*
StringŬ������ ���� ����
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
	>>, <<����縦 ����Լ��� �����ε��� �Ϸ��� istream�� ostream Ŭ������ �����ؾ� �ϴµ� �̴� �Ұ����ϴ�.
	���� friendŰ���带 ���� �����Լ��� �����ͼ� ����ϵ��� �Ѵ�.
	*/
	friend istream& operator>> (istream& in, String& _String);
	friend ostream& operator<< (ostream& out, const String& _String);
};
#endif