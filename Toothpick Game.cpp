#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	cout << "\t\tWelcome to the toothpick game!\n";
	int num = 0, computerPick = 0, humanPick = 0, toothpick = 23;
	bool flag = true;
	while (humanPick != 4)
	{
		while (humanPick != 4)
		{
			cout << "\nPlease pick up your toothpick(s), choose between 1 and 3 : ";
			cin >> humanPick;

			if (humanPick > 3 || humanPick < 0 || !humanPick || humanPick>toothpick)
			{
				cout << "\nPlease enter a correct value!\n";
				cout << toothpick << " toothpick(s) remaining\n" << endl;
				humanPick = 0;
				continue;
			}

			toothpick -= humanPick;
			flag = false;

			if (toothpick <= 0)
				break;

			if (toothpick > 4)
			{
				srand(time(0));
				computerPick = static_cast<int>(rand() % 3 + 1);
			}
			else if (toothpick == 1)
				computerPick = 1;
			else if ((toothpick >= 2) || (toothpick <= 4))
				computerPick = toothpick - 1;
			cout << "The computer took " << computerPick << " toothpick(s)" << endl;

			toothpick -= computerPick;
			flag = true;

			if (toothpick <= 0)
				break;

			cout << toothpick << " toothpick(s) remaining" << endl;
		}
		if (flag == true)
			cout << "\n\tYou have Prevailed!";
		else if (flag == false)
			cout << "\n\tComputer has Prevailed!";
		if (toothpick <= 0)
		{
			cout << "\n\nEnter any integer except 4 to Play agin\nEnter 4 to exit\n\n\tEnter your choice : ";
			cin >> humanPick;
			toothpick = 23;

			if (!cin)
				break;
		}
		if (humanPick != 4)
		{
			continue;
		}
	}
	cout << "\n\n\n";
	system("pause");
	return 0;
}
