/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1845
�ߺ��� �����͸� ��� �ٷ� ���̳Ŀ� ���� ���� ������.

c++ stl�� set�� �̿��ϸ� ���� �ذ��� �� �ִ�.
*/
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> my_set;
    //nums���� ���� my_set�� ���� ���� ���� my_set�� �ִ´�
    for (int a = 0; a < nums.size(); a++) {
        if (my_set.find(nums[a]) == my_set.end())    my_set.insert(nums[a]);
    }
    //my_set�� ũ��� ���� �ٸ� ������ ���ϸ��� ���̴�.
    //���� N/2���� my_set�� ũ�Ⱑ ũ�ٸ� N/2��� ������ ���ϸ��� ���� �� �ִ�. �ݴ��� ��� my_set�� ũ�� ��ŭ�� ������ ������ �� �ִ�.
    if (my_set.size() > (nums.size() / 2))    return (nums.size() / 2);
    else    return my_set.size();

    return answer;
}