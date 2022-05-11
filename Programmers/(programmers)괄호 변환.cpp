/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/60058
���ڿ� ó���� ���� �ܼ� ���� ������.

�������� �־��� ��Ģ�� ���� �Է°��� �ùٸ� ��ȣ ���ڿ��� ��ȯ���ָ� �ȴ�.
*/
#include <string>
#include <vector>

using namespace std;

bool is_correct(string str);
string recursion(string w);

string solution(string p) {
    string answer = "";

    answer = recursion(p);

    return answer;
}
//str�� �ùٸ� ��ȣ ���ڿ��̸� true, �ƴϸ� false��ȯ
bool is_correct(string str) {
    int num1 = 0, num2 = 0;
    for (int a = 0; a < str.size(); a++) {
        if (str[a] == '(')   num1++;
        else    num2++;
        if (num1 < num2) return false;
    }
    return true;
}
//�������� ��ȣ ���ڿ� w�� ��Ģ�� ���� �ùٸ� ��ȣ ���ڿ��� ��ȯ�Ͽ� ��ȯ
string recursion(string w) {
    //�� ���ڿ��� ��� �ٷ� ��ȯ
    if (w.size() == 0)   return w;

    int num1 = 0, num2 = 0;
    string u, v, ret;

    for (int a = 0; a < w.size(); a++) {
        if (w[a] == '(')   num1++;
        else    num2++;
        //���̻� ���� �� ���� �������� ��ȣ ���ڿ� u�� ������ v�� ���
        if (num1 == num2) {
            for (int b = 0; b < num1 + num2; b++)    u.push_back(w[b]);
            for (int b = num1 + num2; b < w.size(); b++) v.push_back(w[b]);

            if (is_correct(u)) {    //u�� �ùٸ� ��ȣ ���ڿ��̶�� v�� ���� ��� ȣ���ϰ� ��ģ ���� ��ȯ
                ret = u + recursion(v);
                return ret;
            }
            else {  //u�� �ùٸ� ��ȣ ���ڿ��� �ƴ� ��� ��Ģ�� ���� ��ȯ�ϰ� ��ȯ
                ret.push_back('(');
                ret += recursion(v);
                ret.push_back(')');
                for (int b = 1; b < u.size() - 1; b++) {
                    if (u[b] == '(') ret.push_back(')');
                    else    ret.push_back('(');
                }

                return ret;
            }

            break;
        }
    }
    return ret;
}