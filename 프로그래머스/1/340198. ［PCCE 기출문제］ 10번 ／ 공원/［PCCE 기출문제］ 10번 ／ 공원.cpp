#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.rbegin(), mats.rend());
    
    for (int k = 0 ; k < mats.size() ; k++)
    {
        int len = mats[k];
        int row = park.size();
        int col = park[0].size();
        for (int i = 0 ; i <= row - len ; i++)
        {
            for (int j = 0 ; j <= col - len ; j++)
            {
                bool pnp = true;
                
                for (int a = i ; a < i + len ; a++)
                {
                    for (int b = j ; b < j + len ; b++)
                    {
                        if (park[a][b] != "-1")
                        {
                            pnp = false;
                            break;
                        }
                    }
                    if (pnp == false) break;
                }
                if (pnp == true) return len;
            }
        }
    }
    return -1;
}