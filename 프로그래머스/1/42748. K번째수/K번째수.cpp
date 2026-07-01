#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> result;
    for (int i = 0 ; i < commands.size() ; i++)
    {
        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int k = commands[i][2] - 1;
        
        vector<int> sub_arr(array.begin() + start, array.begin() + end);
        
        sort(sub_arr.begin(), sub_arr.end());
        
        result.push_back(sub_arr[k]);
    }
    return result;
}