#include <iostream>

using namespace std;
long long A, B, C;

long long Power(long long a, long long b, long long c) {

	if (b == 1) return a % c;

	long long half = Power(a, b / 2, c);

	long long result = (half * half) % c;

	if (b % 2 == 0)
	{
		return result;
	}
	else
	{
		return (result * a) % c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << Power(A, B, C) << "\n";

}