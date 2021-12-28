/*
문제 링크 : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Two Pointers로 해결할 수 있는 문제다.

numbers의 크기가 최대 30000이기에 단순히 for문으로 전체를 탐색하는 방법은 시간초과가 나온다.

이는 two pointers를 이용함으로써 필요없는 탐색을 하지 않음으로써 해결할 수 있다.

먼저 첫 번째 포인터는 numbers의 시작을, 두 번째 포인터는 numbers의 끝을 가르킨다.

그런 다음 두 포인터가 가르키는 요소의 합이 target이 될 때까지 아래를 반복한다.
1. sum < target -> 더 큰 수가 필요하기에 시작에 가까운 포인터를 1 키운다
2. sum > target -> 더 작은 수가 필요하기에 끝에 가까운 포인터를 1 낮춘다
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int left = 0, right = numbers.size() - 1, sum;

        while (1) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                answer.emplace_back(left + 1);
                answer.emplace_back(right + 1);
                break;
            }
            else if (sum < target)   left++;
            else    right--;
        }
        return answer;
    }
};