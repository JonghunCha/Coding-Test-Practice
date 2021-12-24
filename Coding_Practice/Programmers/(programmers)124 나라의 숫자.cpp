/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12899
진법에 관한 문제다.

결국 124 나라의 수를 표현하는 방법은 3진수와 비슷하다.

따라서 n을 3으로 나눈 나머지와 몫을 이용하여 변환을 할 수 있다.

아래 코드를 보면 이해할 수 있을 것이다.
*/
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "", reverse = "";
    int temp;

    if (n == 1)  return "1";
    n--;
    while (n > 0) {
        //현재 n값을 3으로 나눈 나머지가 가장 124숫자의 가장 오른쪽 값이 된다.
        if (n % 3 == 0)  reverse.push_back('1');    
        else if (n % 3 == 1) reverse.push_back('2');
        else    reverse.push_back('4');
        n /= 3;
        if (n == 1) {
            reverse.push_back('1');
            break;
        }
        n--;
    }
    //while문에서 역순으로 reverse에 문자를 넣었으니 answer에 다시 순서대로 저장
    for (int a = reverse.size() - 1; a >= 0; a--)    answer.push_back(reverse[a]);

    return answer;
}