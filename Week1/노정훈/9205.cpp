// BFS. 
// 맥주 20병.. 잘마시네 - distance 1000까지 이동 가능 
// 어찌 됐건 현 노드에서 갈 수 있는 노드들을 체크해서 전수 조사하면
// 집에서 축제까지 갈 수 있는지 여부를 알 수 있다 
// n<=100이라 BFS해도 시간 초과 X 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

pii loc[102], cur;
int n;
bool visit[102];

int getDist(pii a, pii b)
{
  int first = abs(a.first - b.first);
  int second = abs(a.second - b.second);
  return first + second;
}

bool solve()
{
  queue<int> Q;
  Q.push(0);
  visit[0] = true;
  while (!Q.empty())
  {
    if (Q.front() == n + 1)
      return true;
    visit[Q.front()] = true;
    cur = loc[Q.front()];
    Q.pop();

    for (int i = 0; i < n + 2; ++i)
    {
      if (!visit[i] && getDist(cur, loc[i]) <= 1000)
      {
        visit[i] = true;
        Q.push(i);
      }
    }
  }
  return false;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n + 2; ++i)
    {
      visit[i] = false;
      cin >> loc[i].first >> loc[i].second;
    }
    if (solve())
      cout << "happy\n";
    else
      cout << "sad\n";
  }

  return 0;
}
