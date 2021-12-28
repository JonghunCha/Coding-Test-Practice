/*
문제 링크 : https://leetcode.com/problems/rotate-array/
leetcode상에서 Two Pointer 문제로 분류되어 있지만 Two Pointer가 핵심이라기보단 공간복잡도를 다루는 문제라 생각한다

문제 자체는 간단하지만 구현 방법에 따라 space complexity가 달라진다.

따라서 2가지 솔루션을 제시하고 서로 비교하도록 하겠다.

1번 방법은 직관적이고 간단하지만 nums의 크기만큼의 메모리 공간을 더 필요로 한다.
만약 nums의 크기가 매우 크다면 공간 효율성이 떨어지게 된다.

2번 방법은 코드 자체는 조금 더 길지만 1번 방에 비해 훨씬 작은 메모리 공간을 필요로 한다.(nums가 충분히 크다는 가정 하에)
1번에서는 nums의 크기만큼 추가 공간을 사용하였지만, 2번 방법에서는 int형 변수 6개만을 추가로 사용한다.

위 두 방법들 외에도 사람들이 올린 여러 방법들이 많다.(문제링크의 Discuss참고)
*/

// 1. nums의 복사본을 만들고 이동을 한다. (Time Complexity : O(N), Space Complexity : O(N))
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy;
        int len = nums.size();
        for (int a = 0; a < len; a++)    copy.emplace_back(nums[a]);
        for (int a = 0; a < len; a++)    nums[(a + k) % len] = copy[a];
    }
};

// 2. 하나의 원소부터 시작해 회전을 하고 그 다음 대상은 회전한 위치에 있던 원소가 되도록한다. (Time Complexity : O(N), Space Complexity : O(1))
// 예를 들어 nums의 크기가 8이고 k가 3이라면 (0번회전->3번회전->6번회전->1번회전->4번회전->7번회전->2번회전->5번회전)순이 된다.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotate_count = 0, len = nums.size(), start_index = 0, curr_index = 0, number = nums[0], temp;
        while (rotate_count < len) {
            do {
                temp = nums[(curr_index + k) % len];
                nums[(curr_index + k) % len] = number;
                number = temp;
                curr_index = (curr_index + k) % len;
                rotate_count++;
            } while (curr_index != start_index);
            //nums의 크기가 4이고 k가 2인 경우(0번회전->2번회전->0번회전) 1번과 3번을 회전 시키지 않은채 0번과 2번만 반복될 수 있다.
            //따라서 curr_index와 start_index가 같은 경우 do while을 멈추고 start_index를 1 늘려 새로운 do while을 돌도록 한다.
            start_index++;
            curr_index = start_index;
            number = nums[curr_index];
        }
    }
};