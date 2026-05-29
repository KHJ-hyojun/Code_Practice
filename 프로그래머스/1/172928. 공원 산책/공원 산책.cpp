#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int H = park.size();
    int W = park[0].size();
    pair<int,int> start;
    
    for (int i = 0 ; i < H ; i++)
    {
        for (int j = 0 ; j < W ; j++)
        {
            if (park[i][j] == 'S') start = {i,j};
        }
    }
    
    unordered_map<char,pair<int,int>> move = {
        {'N',{-1,0}}, {'S',{1,0}}, {'W',{0,-1}}, {'E',{0,1}}
    };
    
    for (string route : routes)
    {
        char dir = route[0];
        int dist = route[2] - '0';
        
        int gox = start.second;
        int goy = start.first;
        bool can_move = true;
        
        for (int i = 1 ; i <= dist ; i++)
        {
            goy += move[dir].first;
            gox += move[dir].second;
            
            if (gox < 0 || gox >= W || goy < 0 || goy >= H || park[goy][gox] == 'X')
            {
                can_move = false;
                break;
            }
        }
        if (can_move) start = {goy,gox};
    }
    return {start.first, start.second};   
}