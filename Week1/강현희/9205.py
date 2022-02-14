import sys
from collections import deque
num_test= int(sys.stdin.readline())

def find_dist(p1, p2):
    return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])


for i in range(num_test):
    test=[]
    num= int(sys.stdin.readline())+2
    visited=[False]*num
    dist= [[] for i in range(num)]

    for j in range(num):
        x, y = map(int, sys.stdin.readline().split())
        test.append([x,y])

    for i in range(num-1):
        for j in range(i,num):
            if (i!=j and find_dist(test[i],test[j])<=1000):
                dist[i].append(j)
                dist[j].append(i)

    queue=deque([0])
    while queue:
        root= queue.popleft()
        if(root==num-1):
            print("happy")
            break
        
        if(visited[root]==True):
            continue

        visited[root]=True

        for node in dist[root]:
            queue.append(node)
    
    if(root!=num-1):
        print("sad")


""" -- 플로이드 마샬 풀이법
import sys
num_test= int(sys.stdin.readline())
max= float('inf')

def find_dist(p1, p2):
    return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])


for i in range(num_test):
    test=[]
    num= int(sys.stdin.readline())+2
    dist=[[max]*num for _ in range(num)]
    # home= [int(k) for k in sys.stdin.readline().split()]
    
    for j in range(num):
        x, y = map(int, sys.stdin.readline().split())
        test.append([x,y])
    
    # fest= [int(k) for k in sys.stdin.readline().split()]

    for i in range(num):
        for j in range(num):
            if (i!=j and find_dist(test[i],test[j])<=1000):
                dist[i][j]=1
    
    for k in range(num):
        for i in range(num):
            for j in range(num):
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])

    print("happy" if dist[0][num-1]<max else "sad")




"""

    

