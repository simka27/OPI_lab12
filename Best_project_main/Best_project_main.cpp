#include <iostream>
#include "..\Beat_project3\Best_project3.h"
#include "..\Beat_project2\Best_project2.h"
#include "..\Best_project\Best_project.h"


using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	cout << "Перед вами лучший проект в истории человечества.в какую игру желаете поиграть?(1-2048 , 2-тетрис , 3-змейка)";
	cin >> k;
	if (k == 1)
	{
		mainzmeyka();
	}
	if (k == 2)
	{
		mainttfe();
	}
	if (k == 3)
	{
		maintetris();
	}
	else
	{
		cout << "вы вышли из программы";
	}
}
