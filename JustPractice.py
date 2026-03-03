import sys
from collections import deque

queue = deque([v])
visited = deque()

def DFS(node):
    visited[node] = True
    resultd += node + " "

    x = node
    queue.popleft(x)
    queue.append(x)

    while queue:
        for _ in range(queue[x].size()):
            if visited[_] == 0:
                DFS(_)
    
    return resultd
    
def BFS(node):


n, m, v = map(int, input().split())

for i in range(m+1):
    a, b = map(int, input().split())
    queue[a].append(b)
    queue[b].append(a)

print(DFS(v) + "\n")
BFS(v)




