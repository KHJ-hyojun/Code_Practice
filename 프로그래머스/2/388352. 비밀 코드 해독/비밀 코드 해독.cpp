#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> picked;
    
    for (int i = 0 ; i < q.size() ; i++)
    {
        sort(q[i].begin(), q[i].end());
    }
    auto dfs = [&](auto& self, int start_num) -> void {
        if (picked.size() == 5) 
        {
            bool is_vaild = true;
            
            for (int i = 0 ; i < q.size() ; i++)
            {
                int match_cnt = 0;
                for (int x : q[i])
                {
                    for (int y : picked)
                    {
                        if (x == y) match_cnt++;
                    }
                }
                if (match_cnt != ans[i])
                {
                    is_vaild = false;
                    break;
                }
            }
            if (is_vaild) answer++;
            return;
        }
        
        
        for (int i = start_num ; i <= n ; i++)
        {
            picked.push_back(i);
            self(self,i+1);
            picked.pop_back();
        }
    };
    dfs(dfs, 1);
    return answer;
}