#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server_cnt = 0;
    vector<int> minus(50, 0);
    
    for (int i = 0 ; i < players.size() ; i++)
    {
        server_cnt -= minus[i];
        int needed = players[i] / m;
        if (needed > server_cnt)
        {
            int add = needed - server_cnt;
            
            answer += add;
            server_cnt += add;
            minus[i+k] += add;
        }
    }
    return answer;
}