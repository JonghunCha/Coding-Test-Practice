/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42839
���� Ž���� ���� �ذ��� �� �ִ� ������.

������ �ذ��ϱ� ���ؼ� ũ�� �� �ܰ�� ������.

ù ��°�� numbers�߿� ��� ���ڵ��� �̿��Ͽ� ���� ���� ������.
�� ��°�� ���� ���� ���ڵ��� ������ ��� �� ��������.

�Ʒ��ڵ�� ���� ������� ���� ����� �ش� ���� �Ҽ���� answer�� 1�� �����־���.
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int answer = 0;
unordered_set<int> answer_set;

void picknumbers(string& numbers, int picked[7], int index);    //���� ����µ� ����� ���ڸ� ����
void makenum(vector<int>& candidates, int location[7], int index);  //����� ���ڵ�� ���� �� �ִ� ��� ���� ����
int my_pow(int n);  //�� �ڸ����� ���ؾ��� pow�� ���
bool isPrime(int num);  //�Ҽ����� �Ǻ�

int solution(string numbers) {
    int picked[7];

    for (int a = 0; a < numbers.size(); a++) picked[a] = 0;
    picknumbers(numbers, picked, 0);

    return answer;
}

void picknumbers(string& numbers, int picked[7], int index) {
    if (index == numbers.size()) {  //��� ���ڵ鿡 ���� ������� �������� ���� ���
        vector<int> candidates;
        int location[7];
        //candidates�� ����� ���ڸ� �־��ش�
        for (int a = 0; a < index; a++) {
            if (picked[a] == 1)  candidates.push_back(numbers[a] - '0');
        }
        //location�� �� ���ڰ� �ϼ��� ���� �� ��° �ڸ��� ���� �������� ����(0�̸� 1�� �ڸ�, 1�̸� 10���ڸ� ...)
        for (int a = 0; a < candidates.size(); a++)  location[a] = -1;
        makenum(candidates, location, 0);
    }
    else {  //index�� �ش��ϴ� ���ڸ� ���� ���� ���� �ʴ� ���� ������ Ž��
        picknumbers(numbers, picked, index + 1);
        picked[index] = 1;
        picknumbers(numbers, picked, index + 1);
        picked[index] = 0;
    }
    return;
}

void makenum(vector<int>& candidates, int location[7], int index) {
    if (index == candidates.size()) {   //�� ������ �ڸ��� ���� ���
        int num = 0;
        for (int a = 0; a < index; a++) {   //�ڸ��� �°� 10�� n���� �����ش�
            num += candidates[a] * my_pow(location[a]);
        }
        if (num > 1 && isPrime(num) && answer_set.find(num) == answer_set.end()) {  //num�� �Ҽ��� ������ �����ϸ� �ߺ����� ���� ��� answer++
            answer_set.insert(num);
            answer++;
        }
    }
    else {  //�ϼ��� ���� index��° �ڸ��� ��� ���ڰ� �������� ����
        for (int a = 0; a < candidates.size(); a++) {
            if (location[a] == -1) {
                location[a] = index;
                makenum(candidates, location, index + 1);
                location[a] = -1;
            }
        }
    }
    return;
}

int my_pow(int n) {
    int ret = 1;
    for (int a = 0; a < n; a++) {
        ret *= 10;
    }
    return ret;
}

bool isPrime(int num) {
    for (int a = 2; a * a <= num; a++) {
        if (num % a == 0)    return false;
    }
    return true;
}