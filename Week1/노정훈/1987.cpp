#include <iostream>

using namespace std;
int R, C;
int maximum = 1;

char map[20][20];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

bool isValid(int y, int x)
{
  return y >= 0 && y < R && x >= 0 && x < C;
}

void DFS(int status, int depth, int y, int x)
{
  if (depth > maximum)
    maximum = depth;
  for (int i = 0; i < 4; ++i)
  {
    int nextY = y + dy[i], nextX = x + dx[i];

    if (isValid(nextY, nextX))
    {
      char next = map[nextY][nextX] - 'A';
      if (!(status & (1 << next)))
        DFS(status | (1 << next), depth + 1, nextY, nextX);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%d %d ", &R, &C);
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      scanf(" %c", &map[i][j]);
  DFS(1 << (map[0][0] - 'A'), 1, 0, 0);
  cout << maximum;
}