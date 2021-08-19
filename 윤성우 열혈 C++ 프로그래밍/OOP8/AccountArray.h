/*
AccountArray 클래스의 선언 파일
*/
#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray {
private:
	ACCOUNT_PTR* arr;
	int arrlen;
public:
	BoundCheckAccountPtrArray(int _arrlen = 100);
	ACCOUNT_PTR& operator[](int index);
	ACCOUNT_PTR operator[](int index) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};
#endif