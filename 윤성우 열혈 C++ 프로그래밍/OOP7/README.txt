프로젝트를 진행할 때 모든 소스코드를 하나의 파일에 모두 작성하는 것은 바람직하지 않다.
이는 코드에 대한 가독성을 떨어뜨릴뿐만 아니라 디버깅, 유지보수 등 많은 부분에 좋지 않게 작용한다.
따라서 우리는 기능별 혹은 목적에 따라 여러 파일로 나누어 관리할 필요가 있다.

C++에서는 주로 각각의 클래스마다 선언은 .h 파일에, 정의는 .cpp 파일에 저장을 한다.

OOP7에서는 OOP6까지 작성한 코드를 여러개의 파일에 나눠 저장하려고 한다. 아래는 파일들의 이름과 담고 있는 내용을 의미한다.

Account.h / Account.cpp			: 각각 Account클래스의 선언과 정의
NormalAccount.h				: NormalAccount클래스의 선언과 정의
HighCreditAccount.h			: HighCreditAccount클래스의 선언과 정의
AccountHandler.h / AccountHandler.cpp	: 각각 AccountHandler클래스의 선언과 정의
OOP7_main.cpp				: OOP7의 main함수의 정의
(NormalAccount클래스와 HighCreditAccount클래스의 정의는 길지 않기에 선언과 정의를 따로 분리하지 않았다)