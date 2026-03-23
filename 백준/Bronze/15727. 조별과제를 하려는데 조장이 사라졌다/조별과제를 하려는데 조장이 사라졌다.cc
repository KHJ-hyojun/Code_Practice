#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int result = 0;

	while (n > 5)
	{
		result++;
		n -= 5;
	}

	cout << result + 1;
}