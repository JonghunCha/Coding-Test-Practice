/*
���� ��ũ : https://leetcode.com/problems/reverse-bits/
��Ʈ����ŷ���� �ذ��� �� �ִ� ������.

��Ʈ�� ������ ���ؼ� temp��� ������ �ϳ� �ξ���. temp���� �� ���ܸ��� �ű�����ϴ� ��ġ�� ��Ʈ�� �����ϰ� ���� 0���� ����� �־���.

�׷� ���� �ش� ��Ʈ�� �������� �� ��ġ�� ������ ����Ʈ������ ���� �̵��Ͽ���.
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        uint32_t temp;
        //���� �ӵ��� ���� ������ ������ ����� �����Ͽ���.
        for (int a = 0; a < 16; a++) {
            temp = n >> a;
            temp = temp << 31;
            temp = temp >> a;
            answer = answer | temp;
        }
        for (int a = 0; a < 16; a++) {
            temp = n << a;
            temp = temp >> 31;
            temp = temp << a;
            answer = answer | temp;
        }
        return answer;
    }
};