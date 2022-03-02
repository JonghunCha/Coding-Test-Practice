/*
문제 링크 : https://swexpertacademy.com/main/main.do
valid_camera_num이란 변수를 두어 같은 위치에 있는 카메라는 하나로 보고 실제로 서로 다른 위치에 있는 카메라의 수를 저장하였다.

만약 valid_camera_num이 수신기의 개수은 K보다 같거나 작다면 각 카메라마다 수신기를 둘 수 있으니 수신 가능 영역은 0이다.

그러나 수신기의 갯수가 valid_camera_num보다 작다면 수신 가능 영역이 0이상이 된다.

만약 수신기의 갯수가 valid_camera_num보다 1개 작다고 가정하자.

그렇다면 하나의 카메라는 다른 카메라에 있는 수신기와 연결이 되어야 하며, 이 경우 카메라 사이의 거리가 가장 짧은 구간의 수신기의 수신 가능 영역을 올리는 것이 전체 수신 가능 영역의 합이 최소가 된다.

즉, 수신기의 갯수가 서로 다른 위치에 존재하는 카메라의 수보다 n개 부족하다면, 각 카메라 사이의 거리가 짧은 순서대로 n개의 구간을 수신 가능 영역으로 만들어 주면 모든 카메라가 수신기와 연결이 된다.

이를 구현한 것이 아래 코드이다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp(vector<int>& cameras, int valid_camera_num, int receive_num, int start);

int main(int argc, char** argv)
{
	int T, N, K, input[10000], distances[10000], valid_camera_num, answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 카메라 위치 오름차순으로 정렬
		scanf("%d %d", &N, &K);
		for (int a = 0; a < N; a++)	scanf("%d", &input[a]);
		sort(input, input + N);
		//서로 다른 위치에 존재하는 카메라의 수를 계산하며 동시에 카메라 간의 간격 계산
		valid_camera_num = 1;
		for (int a = 1; a < N; a++) {
			if (input[a] == input[a - 1])	continue;
			else {
				distances[valid_camera_num - 1] = input[a] - input[a - 1];
				valid_camera_num++;
			}
		}
		//카메라 간의 간격을 오름차순으로 정렬
		sort(distances, distances + valid_camera_num - 1);
		//카메라 간의 간격이 짧은 순으로 (valid_camera_num - K)개의 구간을 수신 가능 영역으로 만든다
		answer = 0;
		for (int a = 0; a < valid_camera_num - K; a++)	answer += distances[a];
		printf("#%d %d\n", test_case, answer);
	}


	return 0;
} 