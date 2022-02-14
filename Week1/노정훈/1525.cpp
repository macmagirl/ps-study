// 탐색할 경우의 수는 그리 많지 않은데 중복 체크를 어떻게 하냐가 큰 문제일듯?
// 3 * 3 를 어떻게 체크할 것인가요
// 9!의 경우의수 . 에라모르겠다 그냥 36만개짜리 배열 ? < 될듯?
// 인덱싱은 어케할건가요

#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

map<int, int> visit;
queue<int> q;
int cur = 0;

int pow(int a, int b)
{
  int res = 1;
  for (int i = 0; i < b; ++i)
    res *= a;
  return res;
}

int findZero(int status)
{
  int index = 9;
  while (index--)
  {
    int num = status % 10;
    status /= 10;
    if (!num)
      return index;
  }
}

int left(int status)
{
  int pos = findZero(status);
  if (pos == 0 || pos == 3 || pos == 6)
    return 0;
  int target = (status / pow(10, 8 - (pos - 1))) % 10;
  status += target * pow(10, 8 - pos);
  status -= target * pow(10, 8 - (pos - 1));
  return status;
}
int right(int status)
{
  int pos = findZero(status);
  if (pos == 2 || pos == 5 || pos == 8)
    return 0;
  int target = (status / pow(10, 8 - (pos + 1))) % 10;
  status += target * pow(10, 8 - pos);
  status -= target * pow(10, 8 - (pos + 1));
  return status;
}
int up(int status)
{
  int pos = findZero(status);
  if (pos == 0 || pos == 1 || pos == 2)
    return 0;
  int target = (status / pow(10, 8 - (pos - 3))) % 10;
  status += target * pow(10, 8 - pos);
  status -= target * pow(10, 8 - (pos - 3));
  return status;
}
int down(int status)
{
  int pos = findZero(status);
  if (pos == 6 || pos == 7 || pos == 8)
    return 0;
  int target = (status / pow(10, 8 - (pos + 3))) % 10;
  status += target * pow(10, 8 - pos);
  status -= target * pow(10, 8 - (pos + 3));
  return status;
}

int change(int status, int index)
{
  switch (index)
  {
  case 0:
    return left(status);
  case 1:
    return right(status);
  case 2:
    return up(status);
  case 3:
    return down(status);
  }
}

int BFS()
{
  visit.insert(make_pair(cur, 0));
  q.push(cur);

  while (!q.empty())
  {
    int status = q.front();
    if (status == 123456780)
      return visit[123456780];
    q.pop();
    for (int j = 0; j < 4; ++j)
    {
      int next = change(status, j);
      if (next)
      {
        if (next == 123456780)
        {

          return visit[status] + 1;
        }
        if (visit.find(next) == visit.end())
        {
          visit.insert(make_pair(next, visit[status] + 1));
          q.push(next);
        }
      }
    }
  }
  return -1;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 8; i >= 0; --i)
  {
    int temp;
    cin >> temp;
    cur += pow(10, i) * temp;
  }

  cout << BFS();
  return 0;
}
