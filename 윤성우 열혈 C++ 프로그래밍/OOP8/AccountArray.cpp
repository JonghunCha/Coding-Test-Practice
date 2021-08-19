/*
AccountArray 클래스의 정의 파일
*/
#include <iostream>
#include "AccountArray.h"
using namespace std;

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int _arrlen)
	:arrlen(_arrlen) {
	arr = new ACCOUNT_PTR[_arrlen];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int index) {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int index) const {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

int BoundCheckAccountPtrArray::GetArrLen() const {
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
	delete []arr;
}