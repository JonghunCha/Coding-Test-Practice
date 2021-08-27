OOP10에서는 기존에 사용하던 배열 클래스 BoundCheckAccountPtrArray를 클래스 템플릿으로 정의함으로써 다양한 데이터를 저장할 수 있도록 한다.
이를 위해 변경되는 내용은 아래와 같다.
1. 클래스 템플릿의 이름은 BoundCheckArray로 정한다.
2. 클래스 템플릿은 BoundCheckArray.h에 정의한다
3. 기존의 AccountArray.h와 AccountArray.cpp는 삭제한다.

위의 과정을 통해 수정이 필요한 기존 파일은 AccountHandler.h이다.