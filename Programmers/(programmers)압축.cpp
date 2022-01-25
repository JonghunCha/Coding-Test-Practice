/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17684
map을 이용하여 사전을 구축할 수 있는지를 묻는 문제다.

사전을 그때 그때 늘려나가며 문자열 길이가 최대가 되도록 해주는 사전 단어의 인덱스를 추출해 나가면 된다.
*/
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    string str;
    int index;
    //길이가 1인 단어 사전에 넣기
    dic.insert(make_pair("A", 1));
    dic.insert(make_pair("B", 2));
    dic.insert(make_pair("C", 3));
    dic.insert(make_pair("D", 4));
    dic.insert(make_pair("E", 5));
    dic.insert(make_pair("F", 6));
    dic.insert(make_pair("G", 7));
    dic.insert(make_pair("H", 8));
    dic.insert(make_pair("I", 9));
    dic.insert(make_pair("J", 10));
    dic.insert(make_pair("K", 11));
    dic.insert(make_pair("L", 12));
    dic.insert(make_pair("M", 13));
    dic.insert(make_pair("N", 14));
    dic.insert(make_pair("O", 15));
    dic.insert(make_pair("P", 16));
    dic.insert(make_pair("Q", 17));
    dic.insert(make_pair("R", 18));
    dic.insert(make_pair("S", 19));
    dic.insert(make_pair("T", 20));
    dic.insert(make_pair("U", 21));
    dic.insert(make_pair("V", 22));
    dic.insert(make_pair("W", 23));
    dic.insert(make_pair("X", 24));
    dic.insert(make_pair("Y", 25));
    dic.insert(make_pair("Z", 26));
    //msg를 압축함과 동시에 문제의 조건에 따라 사전에 새로운 단어를 추가
    for (int a = 0; a < msg.size();) {
        str.clear();
        str.push_back(msg[a++]);
        while (dic.find(str) != dic.end()) {    //str이 사전에 없는 단어일 때까지 str을 하나씩 늘려준다
            index = dic.find(str)->second;
            str.push_back(msg[a++]);
        }
        answer.push_back(index);    //사전에 존재하는 최대 길이의 str의 인덱스를 answer에 추가
        dic.insert(make_pair(str, dic.size() + 1)); //사전에 존재하지 않는 첫 str을 사전에 추가
        a--;    //사전에 없는 str을 찾기 위해 늘렸던 인덱스를 다시 하나 낮추어 준다
    }

    return answer;
}