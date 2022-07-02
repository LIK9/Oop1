#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string name1, name2, name3; // 이름을 담을 변수 3개를 생성합니다.(띄어쓰기 없이)
	unsigned int plus1, plus2, plus3; // 수입을 담을 변수 3개를 생성합니다.
	int minus1, minus2, minus3; // 지출을 담을 변수 3개를 생성합니다.

	cout << "이름, 수입, 지출: ";
	cin >> name1 >> plus1 >> minus1; // 첫 번째 이름, 수입 지출을 입력받고 있습니다.

	cout << "이름, 수입, 지출: ";
	cin >> name2 >> plus2 >> minus2; // 두 번째 이름, 수입 지출을 입력받고 있습니다.

	cout << "이름, 수입, 지출: ";
	cin >> name3 >> plus3 >> minus3; // 세 번째 이름, 수입 지출을 입력받고 있습니다.
	cout << endl;
	
	cout << setw(10) << left << "이름" << setw(10) << right << "수입" << setw(10) << right << "지출" << endl; // 아래는 입력 받은 이름, 수입, 지출을 조정자를 통해 정렬 방식이 주의하여 출력합니다.
	cout << setw(10) << left << name1 << setw(10) << right << plus1 << setw(10) << right << minus1 << endl;
	cout << setw(10) << left << name2 << setw(10) << right << plus2 << setw(10) << right << minus2 << endl;
	cout << setw(10) << left << name3 << setw(10) << right << plus3 << setw(10) << right << minus3 << endl;
	cout << endl;

	cout << "잔액 = " << plus1 + minus1 << " (" << name1 << ")" << endl; // 첫 번째 잔액을 계산합니다.
	cout << "잔액 = " << plus2 + minus2 << " (" << name2 << ")" << endl; // 두 번째 잔액을 계산합니다.
	cout << "잔액 = " << static_cast<int>(plus3) + minus3 << " (" << name3 << ")" << endl; // 세 번째 잔액을 계산할 때 암묵적 자료형 변환에 의해 unsigned로 변환되어서 언더플로우가 일어납니다.
	cout << endl;																		   // 따라서, 명시적 자료형 변환을 이용해 이를 방지합니다.

	cout << fixed << setprecision(3); // 평균을 소수점 아래 3자리까지 출력하기 위해 부동 소수점 조정자를 사용합니다.
	cout << "평균 잔액 = " << (static_cast<int>(plus1) + minus1 + plus2 + minus2 + static_cast<int>(plus3) + minus3) / 3.0 << endl; // double type으로 명시적 형변환을 하였습니다

	return 0;
}
