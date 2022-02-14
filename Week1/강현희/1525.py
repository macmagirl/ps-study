from collections import deque
import sys

add_x=[1,-1,0,0]
add_y=[0,0,1,-1]
ans=123456789
test=""

# get input 
for i in range(3):
    test += sys.stdin.readline().strip().replace(' ','')

test=int(test.replace('0','9'))

# initialize
queue=deque()
visited=dict()
queue.append(test)
visited[test]=1

while queue:
    s= queue.popleft()
    num= visited.get(s)

    if(s==ans):
        print(num-1)
        break
    
    s= str(s)
    w= s.find('9')
    row= w//3
    col= w%3

    for i in range(4):
        nrow= row + add_x[i]
        ncol= col + add_y[i]

        if(0<=nrow<3 and 0<=ncol<3):
            index= nrow*3 + ncol
            temp=list(s)
            temp[index], temp[w] = temp[w], temp[index]
            ns=int(''.join(temp))

            if not visited.get(ns):
                queue.append(ns)
                visited[ns]= num+1

if (int(s)!=ans):
    print(-1)