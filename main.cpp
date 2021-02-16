#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;



int main()
{
	char color, wincolor = 'r';
	int bet;
	int money;
	int win = 3;

	vector <string> lastbets;
	
	string lastbet;
	
	srand(time(0));
	
	cout << "*****CASINO*****" << endl;
	cout << "How much money do you have? ";
	cin >> money;
	
	system("cls");
	cout << "---<Your money = " << money << ">---"<< endl;
	while(money > 0)
	{
		
		do{
			cout << "Your color(r,b,g) and bet(0-5000): ";
			cin >> color >> bet;
			cout << endl;
		}while(!((color == 'r' || color == 'b' || color == 'g') && bet < 5000 && money >= bet));
		
		money -= bet;
		
		////////////////////////////////////////////////////////////////////////////
		win = rand() % 36 + 1;
		
		
		switch(win)
		{
			case 0: wincolor = 'g'; break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 9:
			case 11:
			case 13:
			case 15:
			case 17:
			case 19:
			case 21:
			case 23:
			case 25:
			case 27:
			case 29:
			case 31:
			case 33:
			case 35: wincolor = 'r'; break;
			default: wincolor = 'b'; break;
		}
		system("cls");
		
		cout << "---<Your money = " << money << " Last bet: ";
		if((color == 'r' || color == 'b') && wincolor == color)
		{
			cout << "+"<< bet;
			money += bet*2;
		}
		else if(color == 'g' && wincolor == color)
		{
			cout << "+"<< bet*13;
			money += bet*14;
		}
		else
		{
			cout << "-"<< bet;
		}
		cout << ">---" << endl;
		////////////////////////////////////////////////////////////////////////////
		
		
		
		
		
		
		cout << "Last bets: ";
		lastbet = wincolor;
		lastbets.push_back(lastbet); 

		for(int i = 0; i < lastbets.size(); i++)
		{
			cout << lastbets[i] << " ";	
		}
		cout << endl << "--------------------------------" << endl;
	}
	
	system("cls");
	cout << "***You lost all your money***";
	return 0;
}
