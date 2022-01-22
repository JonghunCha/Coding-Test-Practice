/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17680
�ܼ� LRU ĳ�ø� �����ϴ� ������.

ĳ���� ũ�Ⱑ �ִ� 30�̰�, ������ ������ 10���� �̱⿡, vector�� �����ص� �ð��� ũ�� �������� �ʾҴ�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void to_lower_character(string& str);   //�빮�� ���ĺ��� �ҹ��ڷ� �ٲپ��ִ� �Լ�

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    bool is_hit;
    //cacheSize�� 0�� ��� ó��
    if (cacheSize == 0)  return 5 * cities.size();
    //��ҹ��� ������ ���� �ʱ⿡ �빮�ڸ� �ҹ��ڷ� ��ȯ
    for (int a = 0; a < cities.size(); a++) {
        to_lower_character(cities[a]);
    }
    //LRU�� ����Ͽ� ��� ���� Ž��
    for (int a = 0; a < cities.size(); a++) {
        //���� ���ð� ĳ�ÿ� ����ִ��� Ȯ��
        is_hit = false;
        for (int b = 0; b < cache.size(); b++) {
            if (cache[b] == cities[a]) {  //ĳ�ÿ� ����ִ� ��� �ش� ���ø� ĳ���� �� �ڷ� �̵�
                is_hit = true;
                cache.erase(cache.begin() + b);
                cache.push_back(cities[a]);
                answer++;
                break;
            }
        }
        //ĳ�ÿ��� miss�� �� ���
        if (!is_hit) {
            if (cache.size() < cacheSize) {   //���� ĳ�ð� �� ���� �ʾҴٸ� ĳ���� �� �ڿ� �ִ´�
                cache.push_back(cities[a]);
                answer += 5;
            }
            else {   //ĳ�ð� �� �� ��� victime�� �����ϰ� ���ο� ���ø� ĳ���� �� �ڿ� �ִ´�
                cache.erase(cache.begin());
                cache.push_back(cities[a]);
                answer += 5;
            }
        }
    }

    return answer;
}
//�빮�� ���ĺ��� �ҹ��ڷ� �ٲپ��ִ� �Լ�
void to_lower_character(string& str) {
    for (int a = 0; a < str.size(); a++) {
        if (str[a] >= 'A' && str[a] <= 'Z') {
            str[a] += 32;
        }
    }
}