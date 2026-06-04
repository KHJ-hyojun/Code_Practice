#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> dp(info.size() + 1, vector<int>(m, 10000));
    dp[0][0] = 0;
    
    for (int i = 0 ; i < info.size() ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (dp[i][j] != 10000) {
                // A가 훔침
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + info[i][0]);
                // B가 훔침
                if (j + info[i][1] < m){
                    dp[i+1][j+info[i][1]] = min(dp[i+1][j+info[i][1]], dp[i][j]);
                }
            }
        }
    }
    int result = 10000;
    for (int i = 0 ; i < dp[info.size()].size() ; i++)
    {
        result = min(result, dp[info.size()][i]);
    }
    if (result >= n) return -1;
    else return result;
}