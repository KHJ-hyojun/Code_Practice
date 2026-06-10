#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<pair<int,int>> robot_path[100]; // [robot][time]
    int max_time = 0;
    
    for (int i = 0 ; i < routes.size() ; i++){
        int curr_x = points[routes[i][0] - 1][0];
        int curr_y = points[routes[i][0] - 1][1];
        robot_path[i].push_back({curr_x,curr_y});
        
        for (int j = 0 ; j < routes[i].size() ; j++) {
            int target_x = points[routes[i][j] - 1][0];
            int target_y = points[routes[i][j] - 1][1];
            
            while (curr_x != target_x) {
                if (curr_x < target_x) curr_x++;
                else curr_x--;
                robot_path[i].push_back({curr_x, curr_y});
            }
            while (curr_y != target_y) {
                if (curr_y < target_y) curr_y++;
                else curr_y--;
                robot_path[i].push_back({curr_x, curr_y});
            }
        }
        max_time = max(max_time, (int)robot_path[i].size());
    }
    
    int total_danger = 0;
    for (int t = 0 ; t < max_time ; t++) {
        
        map<pair<int,int>, int> count_map;
        
        for (int i = 0 ; i < routes.size() ; i++) {
            if (t < robot_path[i].size()) {
                count_map[robot_path[i][t]]++;
            }
        }
        
        for (const auto& [pos, count] : count_map) {
            if (count >= 2) total_danger++;
        }
    }
    return total_danger;
}














