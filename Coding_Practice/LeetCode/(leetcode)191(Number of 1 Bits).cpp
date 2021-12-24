/*
���� ��ũ : https://leetcode.com/problems/number-of-1-bits/
& �� >> ��Ʈ�����ڸ� �̿��Ͽ� �ذ��� �� �ִ�.

&�����ڴ� ��� ��Ʈ�� and������ �ϴµ�, n&1�� �� ������ ��Ʈ�� �Ѵ� 1�϶��� 1�̵ǰ� �� �ݴ�� 0�̵ȴ�.

�� ���� �̿��Ͽ� �� ������ ��Ʈ�� 1���� �˻��ϰ� �� ������ ���������� 1�� ����Ʈ�ϸ� 32���� ��Ʈ�� �� ���ϸ� �ȴ�.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while (n) {
            if (n & 1 == 1)    answer++;
            n >>= 1;
        }
        return answer;
    }
};