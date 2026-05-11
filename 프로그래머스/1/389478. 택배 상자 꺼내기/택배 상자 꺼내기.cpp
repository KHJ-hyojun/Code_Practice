#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    vector<vector<int>> bucket(w + 1,vector<int>());
    
    int current_box = 1;
    bool left_to_right = true;
    
    while (current_box <= n)
    {
        if (left_to_right)
        {
            for (int i = 1 ; i <= w && current_box <= n; i++)
            {
                bucket[i].push_back(current_box++);
            }
        }
        else
        {
            for (int i = w; i >= 1 && current_box <= n; i--)
            {
                bucket[i].push_back(current_box++);
            }
        }
        left_to_right = !left_to_right;
    }
    
    int target_col = -1;
    int target_row = -1;
    
    for (int i = 1 ; i <= w; i++)
    {
        for (int j = 0 ; j < bucket[i].size() ; j++)
        {
            if (bucket[i][j] == num)
            {
                target_col = i;
                target_row = j;
                break;
            }
        }
        if (target_col != -1) break;
    }
    
    return bucket[target_col].size() - target_row;
}