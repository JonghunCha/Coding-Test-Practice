/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/81301
string processing문제다.

단순히 문자열을 처리하는 능력을 묻는 문제이기에 설명할 것은 따로 없다ㅏ.
*/
#include <string>
#include <vector>

using namespace std;

//nums는 각 index에 해당하는 영단어 표현의 앞에것 2개의 문자만 가져온 것(2개의 문자만 비교하면 어떤 수를 의미하는지 알 수 있기에)
//length는 solution의 for문에서 각 영단어에 따라 a를 얼마나 더해줘야 하는지를 저장
string nums[10] = { "ze", "on", "tw", "th", "fo", "fi", "si", "se", "ei", "ni" };
int length[10] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };

int vecToint(vector<int>& v);

int solution(string s) {
    vector<int> v;  //s의 앞에서부터 숫자로 변환한 것을 순서대로 저장

    for (int a = 0; a < s.size();) {
        if (s[a] >= '0' && s[a] <= '9') {   //만약 숫자로 적힌 문자를 발견 한다면 바로 v에 넣고 a는 1만큼 +
            v.push_back(s[a] - '0');
            a++;
        }
        else {  //만약 영단어로 적힌 경우 앞의 두 문자를 비교하여 어떤 숫자를 나타내는지 알아낸다
            for (int b = 0; b < 10; b++) {
                if (s.substr(a, 2).compare(nums[b]) == 0) {
                    v.push_back(b);
                    a += length[b];
                    break;
                }
            }
        }
    }

    return vecToint(v);
}
//vector에 저장된 숫자들과 자릿수를 이용하여 int값으로 계산
int vecToint(vector<int>& v) {
    int ret = 0, temp;
    for (int a = 0; a < v.size(); a++) {
        temp = 1;
        for (int b = 1; b < v.size() - a; b++) {
            temp *= 10;
        }
        ret += v[a] * temp;
    }
    return ret;
}