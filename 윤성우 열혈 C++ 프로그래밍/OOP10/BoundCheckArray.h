/*
클래스 템플릿 BoundCheckArray를 선언 및 정의한 파일
*/
#ifndef __BOUNDCHECKARRAY_H__
#define __BOUNDCHECKARRAY_H__

template <class T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
public:
	BoundCheckArray(int _arrlen = 100);
	T& operator[](int index);
	T operator[](int index) const;
	int GetArrlen() const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int _arrlen)
	:arrlen(_arrlen)
{
	arr = new T[_arrlen];
}

template <class T>
T& BoundCheckArray<T>::operator[](int index) {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

template <class T>
T BoundCheckArray<T>::operator[](int index) const {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}

template <class T>
int BoundCheckArray<T>::GetArrlen() const {
	return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete []arr;
}
#endif