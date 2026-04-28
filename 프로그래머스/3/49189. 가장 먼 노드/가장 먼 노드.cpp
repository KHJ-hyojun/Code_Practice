#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1,-1);
    
    for (int i = 0 ; i < edge.size() ; i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int>q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty())
    {
        int cx = q.front();
        q.pop();
        
        for (int i = 0 ; i < graph[cx].size(); i++)
        {
            int nx = graph[cx][i];
            if (dist[nx] == -1)
            {
                dist[nx] = dist[cx] + 1;
                q.push(nx);
            }
        }
    }
    
    
    int max_dist = *max_element(dist.begin(), dist.end());
    int answer = 0;
    
    for (int i = 1 ; i <= n ; i++)
    {
        if (dist[i] == max_dist)
            answer++;
    }
    return answer;
}