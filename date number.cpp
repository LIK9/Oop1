#include <iostream>

using namespace std;

int main()
{
  int month, date, year;
	cout << "year : ";
	cin >> year;
	cout << "month : ";
	cin >> month;
	cout << "date : ";
	cin >> date;

	int jan = 31, feb = 28, mar = 31, apr = 30, may = 31, jun = 30, jul = 31, aug = 31, sep = 30, oct = 31, nov = 31, dec = 30;

	bool leapyear = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
	if (leapyear)
	{	
		cout << "leapyear" << endl;
		feb = 29;
		jul = 30;
	}

	int value = 0;

	switch (month)
	{
	/*case 1: value += date; cout << "January" << endl; break;
	case 2: value += (jan + date);cout << "February" << endl;  break;
	case 3: value += (jan + date + feb); cout << "March" << endl; break;
	case 4: value += (jan + date + feb + mar); cout << "April" << endl; break;
	case 5: value += (jan + date + feb + mar + apr); cout << "May" << endl; break;
	case 6: value += (jan + date + feb + mar + apr + may); cout << "June" << endl; break;
	case 7: value += (jan + date + feb + mar + apr + may + jun); cout << "July" << endl; break;
	case 8: value += (jan + date + feb + mar + apr + may + jun + jul); cout << "August" << endl; break;
	case 9: value += (jan + date + feb + mar + apr + may + jun + jul + aug); cout << "September" << endl; break;
	case 10: value += (jan + date + feb + mar + apr + may + jun + jul + aug + sep); cout << "October" << endl; break;
	case 11: value += (jan + date + feb + mar + apr + may + jun + jul + aug + sep + oct); cout << "Novemebr" << endl; break;
	case 12: value += (jan + date + feb + mar + apr + may + jun + jul + aug + sep + oct + nov); cout << "December" << endl; break;*/
	case 12: value += nov; 
	case 11: value += oct; 
	case 10: value += sep; 
	case 9: value += aug; 
	case 8: value += jul; 
	case 7: value += jun; 
	case 6: value += may; 
	case 5: value += apr; 
	case 4: value += mar;
	case 3: value += feb; 
	case 2: value += jan; 
	}
	value += date;
	cout << value;
  
  return 0;
}

