/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42891
정렬을 통해 해결할 수 있는 문제다.

가장 먼저 각 음식을 다 먹는데 걸리는 시간과 해당 음식의 번호를 쌍으로 하여 벡터를 구성하고 해당 벡터를 오름차순으로 정렬한다.

그런 다음 먹는데 가장 적은 시간이 걸리는 음식을 다 먹는다 할 때의 시점과 k를 비교한다.

k값이 0이 될 때를 구하고 그 다음 음식을 반환하면 된다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int solution(vector<int> food_times, long long k) {
    //-1인 경우 예외 처리
    long long total_food = 0;

    for (int a = 0; a < food_times.size(); a++)  total_food += food_times[a];
    if (total_food <= k) return -1;
    //food_times와 음식의 번호를 묶고, 오름차순으로 정렬
    vector<vector<int>> foods;

    for (int a = 0; a < food_times.size(); a++)  foods.push_back({ food_times[a], a + 1 });
    sort(foods.begin(), foods.end());
    //음식이 남아있는지 나타내는 is_remained초기화
    bool is_remained[200001];

    for (int a = 1; a <= foods.size(); a++)  is_remained[a] = true;
    //food_times가 가장 작은 음식을 기준으로 k와 비교
    int index = 0, cycle = 0;   //cycle은 현재 몇 가지의 음식을 다 먹었는지 의미
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