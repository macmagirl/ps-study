import sys
from collections import deque

num_test= int(sys.stdin.readline())
add_x=[2,1,-2,-1,2,1,-2,-1]
add_y=[1,2,1,2,-1,-2,-1,-2]

for i in range(num_test):
    len=int(sys.stdin.readline())
    sx, sy=map(int,sys.stdin.readline().split())
    ex, ey=map(int,sys.stdin.readline().split())

    if (sx==ex and sy==ey):
        print(0)
        continue

    visited=[[0]*len for i in range(len)]
    
    queue=deque()
    queue.append([sx,sy])
    visited[sx][sy]=1
    while queue:
        x,y =queue.popleft()
        if(x==ex and y==ey):
            print(visited[x][y]-1)
            break

        for i in range(8):
            nx= x+add_x[i]
            ny= y+add_y[i]
            if(0<=nx<len and 0<=ny<len):
                if(visited[nx][ny]==0):
                    queue.append([nx,ny])
                    visited[nx][ny]=visited[x][y]+1
        
