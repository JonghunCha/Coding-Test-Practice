/*
문제 링크 : https://leetcode.com/problems/jump-game/
Dynamic Programming으로 해결할 수 있는 문제다.

혼자 생각한 아이디어로 구현했을 때 통과는 했지만 시간이 좀 오래 걸려서 다른 사람이 올린 코드를 보았다.

해당 코드를 보니 단순하지만 기발한 생각으로 시간 및 메모리 complexity를 줄일 수 있다는 것을 알게 되었다.

아래에는 두 개의 코드를 모두 올리겠다. 조금만 깊게 생각하면 훨씬 효율적인 코드를 짤 수 있다는 것을 배웠다.
*/

//처음 나의 방법
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)    return true;
        int n = nums.size();
        bool answer[n]; //각 index에서 출발해서 끝 지점에 도달할 수 있는지를 저장

        for (int a = 0; a < n; a++)  answer[a] = false;
        for (int a = n - 2; a >= 0; a--) Get_Answer(nums, a, answer);   //뒤에서부터 끝지점에 도달할 수 있는지 계산

        return answer[0];
    }

    void Get_Answer(vector<int>& nums, int index, bool* answer) {
        if (index + nums[index] >= nums.size() - 1) {   //만약 index지점에서 바로 끝지점에 도달 가능하다면 answer[index]를 true로 지정
            answer[index] = true;
            return;
        }

        for (int a = 1; a <= nums[index]; a++) {    //위에 해당되지 않는 경우 index에서 갈 수 있고 이미 계산된 지역에 true가 있는지 확인
            if (answer[index + a] == true) {
                answer[index] = true;
                return;
            }
        }
    }
};

//다른 사람의 방법
//이 방법에선 뒤에서부터 살피며 끝 지점에 도달 가능한 지역이 있다면 해당 부분을 끝 지역으로 바꾼다.
//이러한 방법을 통해서 위의 방법에서 사용한 bool형 배열을 사용할 필요도 없고, 각 지역에 대해 함수호출을 하지 않고 한번에 해결할 수 있다.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), last = n - 1, i, j;
        for (i = n - 2; i >= 0; i--) {  
            if (i + nums[i] >= last)last = i;
        }
        return last <= 0;
    }
};