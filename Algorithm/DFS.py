# 깊이 우선 탐색(DFS, Depth-First Search)

"""
0. DFS 란?
 한 노드에서 시작하여 한 방향으로 끝까지 깊게 탐색한 뒤
더 이상 방문할 곳이 없으면 되돌아와(backtracking)
다른 경로를 탐색하는 알고리즘

:: 한 경로를 끝까지 탐색 -> 막히면 돌아와서 다른 경로 탐색

- 한 노드에서 방문해야 할 다음 노드가 여러 개일 때는,
1. 하나를 선택하여 계속 깊게 내려간다
2. 더 이상 갈 수 없으면 이전 노드로 복귀

-> LIFO(Last In First Out) 구조 사용

-> 사용 자료구조 : Stack / Recursion(재귀 호출 스택)


1. DFS의 응용
- 그래프 전체를 탐색하거나 모든 경우를 조사할 때 유리
- 최단 거리 탐색에는 적합하지 않음


2. DFS의 장점과 단점
I) 장점
- 메모리 사용량 적음 ( 한 경로만 저장하기 때문 )
- 구현이 매우 간단 ( 재귀 )
- 모든 경우의 수 탐색에 적합 ( 완전탐색 / 백트래킹 문제에 최적 )

II) 단점
- 최단 거리 보장 X ( 깊게 먼저 탐색하기 때문에 더 짧은 경로를 놓칠수도 )
- 한쪽으로 깊게 들어가면 비효율
- 재귀 깊이 제한 위험 ( 노드가 많으면 stack overflow 발생 가능 )

"""
#DFS 구현 ( stack을 이용한 반복적 구현 ) - python
def dfs_iterative(graph, start):
    visited = set() # 방문한 노드를 추적하는 집합
    stack = [start] # 스택에 시작 노드를 넣음

    while stack:
        node = stack.pop() # 스택에서 노드를 꺼냄
        if node not in visited:
            visited.add(node) # 노드를 방문 처리
            

            # 인접한 노드를 스택에 추가
            for neighbor in graph[node]:
                if neighbor not in visited:
                    stack.append(neighbor)



#DFS 구현 ( 재귀를 활용한 구현 ) - python
def dfs_recursive(graph, node, visited):

    # 현재 노드를 방문 처리
    visited.add(node)

    # 인접한 노드들을 재귀적으로 방문
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited)