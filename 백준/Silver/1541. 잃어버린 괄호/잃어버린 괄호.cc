#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	bool isMinus = false;
	string mid = "";
	int Fresult = 0;


	for (int _ = 0; _ < input.size(); _++)
	{
		if (input[_] == '-')
		{
			if (isMinus == true)
			{
				Fresult -= stoi(mid);
				mid = "";
			}
			else
			{
				Fresult += stoi(mid);
				mid = "";
			}

			isMinus = true;

			
		}
		else if (input[_] == '+')
		{
			if (isMinus == true) Fresult -= stoi(mid);
			else Fresult += stoi(mid);
			mid = "";
		}
		else
		{
			mid += input[_];
		}
	}
	if (isMinus == true)
		cout << Fresult - stoi(mid);
	else
		cout << Fresult + stoi(mid);
}