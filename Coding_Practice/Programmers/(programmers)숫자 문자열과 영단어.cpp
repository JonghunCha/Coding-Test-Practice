/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/81301
string processing������.

�ܼ��� ���ڿ��� ó���ϴ� �ɷ��� ���� �����̱⿡ ������ ���� ���� ���٤�.
*/
#include <string>
#include <vector>

using namespace std;

//nums�� �� index�� �ش��ϴ� ���ܾ� ǥ���� �տ��� 2���� ���ڸ� ������ ��(2���� ���ڸ� ���ϸ� � ���� �ǹ��ϴ��� �� �� �ֱ⿡)
//length�� solution�� for������ �� ���ܾ ���� a�� �󸶳� ������� �ϴ����� ����
string nums[10] = { "ze", "on", "tw", "th", "fo", "fi", "si", "se", "ei", "ni" };
int length[10] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };

int vecToint(vector<int>& v);

int solution(string s) {
    vector<int> v;  //s�� �տ������� ���ڷ� ��ȯ�� ���� ������� ����

    for (int a = 0; a < s.size();) {
        if (s[a] >= '0' && s[a] <= '9') {   //���� ���ڷ� ���� ���ڸ� �߰� �Ѵٸ� �ٷ� v�� �ְ� a�� 1��ŭ +
            v.push_back(s[a] - '0');
            a++;
        }
        else {  //���� ���ܾ�� ���� ��� ���� �� ���ڸ� ���Ͽ� � ���ڸ� ��Ÿ������ �˾Ƴ���
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
//vector�� ����� ���ڵ�� �ڸ����� �̿��Ͽ� int������ ���
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