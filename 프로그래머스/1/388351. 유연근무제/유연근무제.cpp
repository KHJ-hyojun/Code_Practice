#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int result = 0;
    for (int i = 0 ; i < schedules.size() ; i++)
    {
        int limit = schedules[i];
        vector<int> oneweek = timelogs[i];
        
        limit = (limit / 100) * 60 + limit % 100 + 10;
        
        bool pnp = true;
         int day = startday;
        for (int j = 0 ; j < 7 ; j++)
        {
            if (day < 6)
            {
                int time = (oneweek[j] / 100) * 60 + oneweek[j] % 100;
                if (time > limit) 
                {
                    pnp = false;
                    break;
                }
            }
            day++;
            if (day > 7) day = 1;
        }
        if (pnp) result++;
    }
    return result;
}