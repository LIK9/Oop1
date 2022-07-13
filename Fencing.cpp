#include <iostream>
#include <ctime>

using namespace std;

int randomNum(int min, int max)
{
	srand(time(0));
	return (rand() % (max - min  +1) + min);
}

int inputPoint()
{	
	int input;
	cout << "승점을 입력하세요: ";
	cin >> input;
	cout << endl;
	return input;
}

int inputAction()
{
	int input;
	cout << "동작을 선택하세요." << endl;
	cout << "1.막기  2.베기  3.찌르기" << endl;
	cout << "? ";
	cin >> input;
	return input;
}

bool game()
{
	int gamePoint = inputPoint();
	int playerPoint = 0;
	int aiPoint = 0;
	while ((playerPoint < gamePoint) && (aiPoint < gamePoint))
	{
		int playerAction = inputAction();
		int aiAction = randomNum(1, 3);
		switch (playerAction)
		{
		case 1: 
			if (aiAction == 2)
				++aiPoint;
			else if (aiAction == 3)
				++playerPoint;
			break;
		case 2:
			if (aiAction == 1)
				++aiPoint;
			else if (aiAction == 3)
				++playerPoint;
			break;
		case 3:
			if (aiAction == 1)
				++aiPoint;
			else if (aiAction == 2)
				++playerPoint;
			break;
		}
		cout << "나희도 행동: " << playerAction << ", 고유림 행동: " << aiAction << endl;
		cout << "나희도 점수: " << playerPoint << ", 고유림 점수: " << aiPoint << endl;
		cout << endl;
	}
	if (playerPoint == gamePoint)
		return true;
	if (aiPoint == gamePoint)
		return false;
}

int main()
{
	if (game())
		cout << "나희도 금메달!!" << endl;
	else
		cout << "고유림 금메달!!" << endl;

	return 0;
}
