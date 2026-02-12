#너비 우선 탐색(BFS, Breadth-First Search)

"""
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

"""
# BFS 구현 - python


from collections import deque

# 인접 리스트 그래프 정의
graph = {
    1: [2, 3, 4],
    2: [1, 5],
    3: [1, 6],
    4: [1],
    5: [2],
    6: [3]
}

# start를 인자로 받아 탐색을 시작하는 bfs 함수
def bfs_queue(start):
    visited = []            # 방문 순서 기록
    q = deque([start])      # 큐 생성
    visited.append(start)

    while q:
        node = q.popleft()

        for adj in graph[node]:
            if adj not in visited:
                visited.append(adj)
                q.append(adj)

    return visited

#실행
print(bfs_queue(1))



