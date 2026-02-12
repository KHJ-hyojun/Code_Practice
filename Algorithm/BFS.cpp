//너비 우선 탐색(BFS, Breadth-First Search)

/*
0. BFS란?
- 모든 경우의 수를 다 훑는 알고리즘 (정답을 찾을 때까지)
너비 우선 탐색은 경로상 어느 정점(node)에서 
다음에 방문할 수 있는 모든 경우의 노드를 전부 방문하고, 
그 다음 단계로 넘어간다.

한 노드에서 방문해야할 다음 노드가 여러 개일때는, 
가장 먼저 입력된 정점부터 방문하기로 한다.

따라서 그 레벨에서 다음 방문한 노드들은 FIFO 자료구조인 Queue로 저장한다.

1. BFS의 응용
깊게 탐색하지 않고 넓게 탐색하는 BFS는 최단경로탐색에 유리하다.

만약 노드별 가중치가 같다면, 몇번째 방문했는지가 바로 거리를 나타낼 수 있다.
그러므로 가장 적은 회차에 목적 노드에 방문한 경로가 최단 경로인 것이다.

2. BFS의 장점과 단점
I. 장점
- 출발노드에서 목표노드까지 최단 길이 경로를 보장한다.

II. 단점
- 경로가 매우 길 경우, 탐색 가지가 급격히 증가함에 따라, 
보다 많은 기억 공간을 필요로 하게 된다.
- 해가 존재하지 않는 경우, 유한 그래프(finite graph)의 경우 
모든 그래프를 탐색한 후에 실패로 끝난다.
- 해가 존재하지 않는 경우, 무한 그래프(infinite graph)의 경우
결코 해를 찾지도 못하고 탐색을 끝내지도 못한다.

*/


// BFS 구현 - c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[9];
vector<int> graph[9];

// BFS 함수 정의
void bfs(int start)
{
    queue<int> q;
    q.push(start); // 첫노드를 queue에 삽입
    visited[start] = true; // 첫 노드를 방문 처리

    // 큐가 빌 때까지 반복
    while(!q.empty())
    {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        cout << x << ' ';

        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0 ; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if(!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(void)
{
    // 노드 1에 연결된 노드 정보 저장
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // 노드 2에 연결된 노드 정보 저장
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3에 연결된 노드 정보 저장
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);

    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(1);
    
}