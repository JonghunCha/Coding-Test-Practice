/*
문제 링크 : https://leetcode.com/problems/zigzag-conversion/
각 row별로 vector를 만든 뒤 위치에 따라 vector에 문자를 넣고 마지막에 row순으로 합쳐주면 된다.
*/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> v[1000];
        int curr_row = 1, dir = 0;
        string ret;

        if (numRows == 1)    return s;

        for (int a = 0; a < s.size(); a++) {
            v[curr_row].push_back(s[a]);
            if (dir == 0 && curr_row < numRows) {
                curr_row++;
            }
            else if (dir == 0 && curr_row == numRows) {
                curr_row--;
                dir = 1;
            }
            else if (dir == 1 && curr_row > 1) {
                curr_row--;
            }
            else {
                curr_row++;
                dir = 0;
            }
        }

        for (int a = 1; a <= numRows; a++) {
            for (int b = 0; b < v[a].size(); b++) {
                ret.push_back(v[a][b]);
            }
        }

        return ret;
    }
};