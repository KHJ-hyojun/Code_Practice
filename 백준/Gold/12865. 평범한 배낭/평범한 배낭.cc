#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k;
int W[101];
int V[101];
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;


	for (int i = 1; i <= n; i++)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int w = 1; w <= k; w++)
		{
			if (W[i] > w)
				dp[i][w] = dp[i - 1][w];
			else
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - W[i]] + V[i]);
		}
	}

	cout << dp[n][k] << "\n";
}