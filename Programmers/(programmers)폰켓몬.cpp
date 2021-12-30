/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1845
중복된 데이터를 어떻게 다룰 것이냐에 대한 쉬운 문제다.

c++ stl의 set을 이용하면 쉽게 해결할 수 있다.
*/
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> my_set;
    //nums에서 아직 my_set에 들어가지 않은 수를 my_set에 넣는다
    for (int a = 0; a < nums.size(); a++) {
        if (my_set.find(nums[a]) == my_set.end())    my_set.insert(nums[a]);
    }
    //my_set의 크기는 서로 다른 종류의 폰켓몬의 수이다.
    //만약 N/2보다 my_set의 크기가 크다면 N/2모두 독립된 폰켓몬을 뽑을 수 있다. 반대의 경우 my_set의 크기 만큼의 종류만 선택할 수 있다.
    if (my_set.size() > (nums.size() / 2))    return (nums.size() / 2);
    else    return my_set.size();

    return answer;
}