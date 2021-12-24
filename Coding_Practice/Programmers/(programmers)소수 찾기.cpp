/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42839
완전 탐색을 통해 해결할 수 있는 문제다.

문제를 해결하기 위해선 크게 두 단계로 나뉜다.

첫 번째는 numbers중에 어떠한 숫자들을 이용하여 수를 만들 것인지.
두 번째는 수를 만들 숫자들의 순서를 어떻게 할 것인지다.

아래코드는 위의 순서대로 수를 만들고 해당 수가 소수라면 answer을 1씩 높여주었다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int answer = 0;
unordered_set<int> answer_set;

void picknumbers(string& numbers, int picked[7], int index);    //수를 만드는데 사용할 숫자를 선택
void makenum(vector<int>& candidates, int location[7], int index);  //사용할 숫자들로 만들 수 있는 모든 수를 만듦
int my_pow(int n);  //각 자릿수에 곱해야할 pow값 계산
bool isPrime(int num);  //소수인지 판별

int solution(string numbers) {
    int picked[7];

    for (int a = 0; a < numbers.size(); a++) picked[a] = 0;
    picknumbers(numbers, picked, 0);

    return answer;
}

void picknumbers(string& numbers, int picked[7], int index) {
    if (index == numbers.size()) {  //모든 숫자들에 대해 사용할지 사용안할지 정한 경우
        vector<int> candidates;
        int location[7];
        //candidates에 사용할 숫자를 넣어준다
        for (int a = 0; a < index; a++) {
            if (picked[a] == 1)  candidates.push_back(numbers[a] - '0');
        }
        //location은 각 숫자가 완성된 수의 몇 번째 자리에 놓일 것인지를 저장(0이면 1의 자리, 1이면 10의자리 ...)
        for (int a = 0; a < candidates.size(); a++)  location[a] = -1;
        makenum(candidates, location, 0);
    }
    else {  //index에 해당하는 숫자를 쓰는 경우와 쓰지 않는 경우로 나누어 탐색
        picknumbers(numbers, picked, index + 1);
        picked[index] = 1;
        picknumbers(numbers, picked, index + 1);
        picked[index] = 0;
    }
    return;
}

void makenum(vector<int>& candidates, int location[7], int index) {
    if (index == candidates.size()) {   //각 숫자의 자리를 정한 경우
        int num = 0;
        for (int a = 0; a < index; a++) {   //자리에 맞게 10의 n승을 곱해준다
            num += candidates[a] * my_pow(location[a]);
        }
        if (num > 1 && isPrime(num) && answer_set.find(num) == answer_set.end()) {  //num이 소수의 조건을 만족하며 중복되지 않은 경우 answer++
            answer_set.insert(num);
            answer++;
        }
    }
    else {  //완성된 수의 index번째 자리를 어느 숫자가 차지할지 정함
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