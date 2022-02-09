/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42891
������ ���� �ذ��� �� �ִ� ������.

���� ���� �� ������ �� �Դµ� �ɸ��� �ð��� �ش� ������ ��ȣ�� ������ �Ͽ� ���͸� �����ϰ� �ش� ���͸� ������������ �����Ѵ�.

�׷� ���� �Դµ� ���� ���� �ð��� �ɸ��� ������ �� �Դ´� �� ���� ������ k�� ���Ѵ�.

k���� 0�� �� ���� ���ϰ� �� ���� ������ ��ȯ�ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int solution(vector<int> food_times, long long k) {
    //-1�� ��� ���� ó��
    long long total_food = 0;

    for (int a = 0; a < food_times.size(); a++)  total_food += food_times[a];
    if (total_food <= k) return -1;
    //food_times�� ������ ��ȣ�� ����, ������������ ����
    vector<vector<int>> foods;

    for (int a = 0; a < food_times.size(); a++)  foods.push_back({ food_times[a], a + 1 });
    sort(foods.begin(), foods.end());
    //������ �����ִ��� ��Ÿ���� is_remained�ʱ�ȭ
    bool is_remained[200001];

    for (int a = 1; a <= foods.size(); a++)  is_remained[a] = true;
    //food_times�� ���� ���� ������ �������� k�� ��
    int index = 0, cycle = 0;   //cycle�� ���� �� ������ ������ �� �Ծ����� �ǹ�
    long long curr;

    while (k > 0) { 
        curr = (foods.size() - index) * (foods[index][0] - cycle);  
        if (k >= curr) { 
            cycle = foods[index][0];
            for (int a = index; a < foods.size(); a++) {
                if (foods[a][0] > cycle) {
                    index = a;
                    break;
                }
                else {
                    is_remained[foods[a][1]] = false;
                }
            }
            k -= curr;
        }
        else {
            k = k % (foods.size() - index);
            for (int a = 1; a <= foods.size(); a++) {
                if (is_remained[a] == true) {
                    if (k == 0)  return a;
                    else    k--;
                }
            }
        }
    }
    for (int a = 1; a <= foods.size(); a++) {
        if (is_remained[a] == true)  return a;
    }

    return 0;
}