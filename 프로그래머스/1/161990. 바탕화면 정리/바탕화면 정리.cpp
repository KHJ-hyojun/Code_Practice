#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int max_x = -1, max_y = -1;
    int min_x = 51, min_y = 51;
    
    for (int i = 0 ; i < wallpaper.size(); i++)
    {
        for (int j = 0 ; j < wallpaper[0].size() ; j++)
        {
            if (wallpaper[i][j] == '#')
            {
                max_x = max(max_x, i);
                max_y = max(max_y, j);
                min_x = min(min_x, i);
                min_y = min(min_y, j);
            }
        }
    }
    return {min_x, min_y, max_x + 1, max_y + 1};
}