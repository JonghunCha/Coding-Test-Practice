/*
���� ��ũ : https://leetcode.com/problems/happy-number/
��� ��Ʈ�� �з��ϱ� �ָ��� �����̳�, ���� ���õǾ math�� �־���.

�ٽ��� 1�� ���ö����� �ݺ��ϴٰ� ���� loop�� �����ٸ��� false�� ��ȯ�ϸ� �ȴ�.

loop�� �����ٴ� ���� ������ ���Դ� ���� �ٽ� ���Դٴ� ���̰�, �̸� �Ǵ��ϱ� ������ �ڷᱸ���� unordered_set�� ����ϴ� ���̴�.
*/
class Solution {
public:
    bool isHappy(int n) {
        int num = n, temp;
        unordered_set<int> s;
        //num�� 1�� �ɶ����� �ݺ�
        while (num != 1) {
            temp = 0;
            while (num > 0) {   //num�� �� ���ڸ� �����Ͽ� temp�� �����ش�
                temp += (num % 10) * (num % 10);
                num = num / 10;
            }
            num = temp;
            if (s.find(num) == s.end())  s.insert(num); //s�� num�� ���ٸ� �߰�
            else    return false;   //�̹� ���Դ� ����� false ��ȯ
        }

        return true;
    }
};