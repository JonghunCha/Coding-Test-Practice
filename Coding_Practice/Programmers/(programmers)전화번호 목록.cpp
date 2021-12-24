/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42577
���ؿ¶����� 5052(��ȭ��ȣ ���)�� ���� ������. 

��ÿ��� ���ķ� Ǯ������.

�׷��� ���α׷��ӽ������� �ؽ� ������ �Ǿ� �ִ�. 

���� �ؽ��� Ǭ ������ ���ķ� Ǭ ���� �ΰ����� �����ϰڴ�.
*/

//���ķ� Ǭ �ڵ�
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    //������ �ϰ��� a�� �ٸ� ��ȣ�� ���ξ��� �׻� a+1�� ���ξ�߸� �Ѵٴ� ���� �̿��Ͽ���.
    for (int a = 0; a < phone_book.size() - 1; a++) {
        if (phone_book[a].compare(phone_book[a + 1].substr(0, phone_book[a].size())) == 0)    return false;
    }

    return answer;
}

//�ؽ��� Ǭ �ڵ�
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    string temp;
    //�ؽ��� ��� ��ȣ�� ����
    for (int a = 0; a < phone_book.size(); a++) {
        hash_map[phone_book[a]] = 1;
    }
    //��� ��ȣ�� ���� ���ξ� ��ȣ�� �����ϴ��� Ȯ��
    for (int a = 0; a < phone_book.size(); a++) {
        temp = "";
        //phone_book[a]�� �տ������� �ϳ��� �߰��ϸ�, �ش� ��ȣ�� hash�� �����ϴ��� Ȯ���Ѵ�
        for (int b = 0; b < phone_book[a].size() - 1; b++) {
            temp += phone_book[a][b];
            if (hash_map.find(temp) != hash_map.end())   return false;
        }
    }

    return answer;
}