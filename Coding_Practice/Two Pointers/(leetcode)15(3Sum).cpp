/*
문제 링크 : https://leetcode.com/problems/3sum/
Two Pointers로 해결할 수 있는 문제다.

처음에 푼 방법이 있었으나, 해당 방법보다 다른 사람의 풀이가 훨씬 깔끔하고 실행속도도 빨라서 다른 분의 아이디어를 기반으로 작성한 코드이다.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int sum, left, right;

        if (nums.size() < 3) return ret;

        sort(nums.begin(), nums.end()); //오름차순으로 정렬

        for (int a = 0; a < nums.size() - 2; a++) {
            //중복된 탐색을 방지하기 위해 이전에 탐색한 nums[a-1]와 이번 루프의 nums[a]가 같다면 그냥 넘어간다.
            if (a > 0 && nums[a] == nums[a - 1])    continue;   
            left = a + 1;   //두 번째 수의 위치
            right = nums.size() - 1;    //세 번째 수의 위치
            while (left < right) {
                sum = nums[a] + nums[left] + nums[right];   //세개의 수를 합한다
                if (sum > 0) right--;   //만약 합이 0보다 크다면 가장 큰 수를 나타내는 right를 한칸 왼쪽으로 당긴다
                else if (sum < 0)    left++;    //위와 반대의 경우
                else {  //합이 0인 세개의 수를 찾은 경우
                    ret.push_back(vector<int>{nums[a], nums[left], nums[right]});   //정답을 저장
                    //마찬가지로 중복된 계산을 방지하기 위해 현재 left 혹은 right가 나타내는 수와 같은 것은 넘김
                    while (left + 1 < right && nums[left] == nums[left + 1])   left++;  
                    while (right - 1 > left && nums[right] == nums[right - 1])   right--;
                    left++;
                    right--;
                }
            }
        }
        return ret;
    }
};