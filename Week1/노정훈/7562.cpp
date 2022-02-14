// 나이트가 해당 칸 까지 가기 위한 최소 이동 수
// 이건 그냥 BFS 브루트 포스로 구하면 될 덧 ?
// visit array를 각 칸까지의 최단 거리로 구하면 되용

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int l;
pii start, goal;

int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};

bool isValid(pii loc)
{
  int x = loc.second;
  int y = loc.first;
  return (x >= 0 && x < l) && (y >= 0 && y < l);
}

int solve()
{
  int visit[300][300];
  memset(visit, -1, sizeof(visit));
  queue<pii> q;
  q.push(start);
  visit[start.first][start.second] = 0;
  while (!q.empty())
  {
    pii cur = q.front();
    q.pop();
    for (int i = 0; i < 8; ++i)
    {
      pii next = make_pair(cur.first + dy[i], cur.second + dx[i]);
      if (visit[next.first][next.second] < 0 && isValid(next))
      {
        visit[next.first][next.second] = visit[cur.first][cur.second] + 1;
        if (next == goal)
          break;
        q.push(next);
      }
    }
  }
  return visit[goal.first][goal.second];
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
    cin >> l;
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;
    cout << solve() << endl;
  }

  return 0;
}
