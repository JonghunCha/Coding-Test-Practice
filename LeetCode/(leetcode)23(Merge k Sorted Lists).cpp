/*
문제 링크 : https://leetcode.com/problems/merge-k-sorted-lists/
모든 val값을 하나의 벡터에 넣고 정렬해준다.

그런 다음 정렬된 순서에 따라 새로운 ListNode들을 만들고 이어주면 된다.
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        ListNode* temp, * ret, * tail;

        //모든 노드들의 val값을 vals벡터에 넣는다
        for (int a = 0; a < lists.size(); a++) {
            temp = lists[a];
            while (temp) {
                vals.push_back(temp->val);
                temp = temp->next;
            }
        }
        //vals벡터 오름차순 정렬
        sort(vals.begin(), vals.end());

        if (vals.size() == 0)    return NULL;   //만약 노드가 0개인 경우 NULL 반환  
        else {  //vals의 모든 val값을 지는 노드를 생성하고 이어준다
            ret = new ListNode(vals[0]);
            tail = ret;
            for (int a = 1; a < vals.size(); a++) {
                temp = new ListNode(vals[a]);
                tail->next = temp;
                tail = temp;
            }
            return ret;
        }
    }
};