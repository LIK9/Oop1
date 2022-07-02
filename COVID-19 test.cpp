#include <iostream>
#include <string>

using namespace std;

int main()
{	
	int input; // 입력을 받을 변수입니다.

	for(int i = 0; i < 3; ++i)
	{	
		string name = "noname"; // 이름 변수입니다. 처음엔 default 값으로 noname을 넣어줍니다.
		int birth = 220101; // 생년월일 변수입니다. 처음엔 default 값으로 220101을 넣어줍니다.
		double temperature = 36.5; // 체온 변수입니다. 처음엔 default 값으로 36.5를 넣어줍니다.
		bool symptom = false; // 증상 변수입니다. 처음엔 default 값으로 false를 넣어줍니다.
		string test = "음성"; // 검사지 변수입니다. 처음엔 default 값으로 음성을 넣어줍니다.
		bool suspected1 = false; // 감염의심자 판별 변수입니다. 처음엔 default 값으로 false를 넣어줍니다.
		bool suspected2 = false; // 확진의심자 판별 변수입니다. 처음엔 default 값으로 false를 넣어줍니다.
		bool success = true; // 결과 출력을 위한 flag 입니다.

		while (success)
		{	
			do // 잘못된 값을 입력하는 것을 방자하기 위해 do-while statement를 사용합니다.
			{	
				cout << "1. 신상 정보 입력" << endl;
				cout << "2. 의심 증상이 있는 경우" << endl;
				cout << "3. 코로나 검사를 받은 경우" << endl;
				cout << "4. 결과 출력" << endl;
				cout << "? ";
				cin >> input;
				if ((input < 1) || (input > 4))
					cout << "잘못된 입력입니다." << endl;
				cout << endl;
			} while ((input < 1) || (input > 4)); // 1보다 작거나 4보다 크면 다시 입력합니다. // 질문1

			switch (input)
			{
			case 1:
				cout << "이름과 생년월일을 입력하세요." << endl;
				cout << "? ";
				cin >> name >> birth;
				cout << endl;
				break;

			case 2:
				cout << "체온과 기침 증상 유무(true/false)를 입력하세요." << endl;
				cout << "? ";
				cin >> temperature >> boolalpha >> symptom; // 입력값을 1, 0 뿐만 아니라 true, false도 받기 위해, boolalpha를 사용합니다.
				cout << endl;
				suspected1 = (temperature > 38 && symptom); // 열이 38도 초과하고 기침 증상이 있을 경우 감염의심자입니다.
				break;

			case 3:
				cout << "신속항원검사 양성: 신속, PCR 양성: PCR, 음성: 음성" << endl;
				cout << "? ";
				cin >> test;
				cout << endl;
				suspected2 = (test == "신속") || (test == "PCR"); // 신속항원검사와 PCR 중 하나라도 양성이면 확진자입니다.
				break;

			case 4:
				cout << name << " " << birth << endl;
				success = false; // 한 번 출력을 한 후 flag를 false로 바꿔서 while statement를 탈출합니다.

				if (suspected1 && !suspected2) // 확진이 아니고 감염의심만 되는 경우입니다.
					cout << "감염의심자입니다. 검사를 받으세요." << endl << endl;
				else if (suspected2)  // 확진이라면 감염의심 여부에 관계없이 확진판정 입니다.
					cout << "확진자입니다. 격리하기 바랍니다." << endl << endl;
				else // 둘 다 해당하지 않는 경우입니다.
					cout << "감염되지 않았습니다." << endl << endl;
				
				break;

			}
		}
		

	} 

	return 0;
}
