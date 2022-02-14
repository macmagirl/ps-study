#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int testcase = 0;
int n = 0;
pair<int, int> home, rock, curpos;
vector<pair<int, int>> pyeon;
 

void solve() {
	queue<pair<int, int>> q;
	bool check[101] = { }; // 편의점 중복해서 무한루프 안걸리게함
	q.push(home);
	bool escape = false;
	while (true) {
		if (q.empty()) break;
		curpos = q.front();
		q.pop();
		for (int i = 0; i < pyeon.size(); i++) {
			if (abs(curpos.first - rock.first) + abs(curpos.second - rock.second) <= 1000) { // 락 페스티벌 도달 가능
				escape = true;
				cout << "happy" << endl;
				return;
			} else if (abs(curpos.first - pyeon[i].first) + abs(curpos.second - pyeon[i].second) <= 1000 && check[i] == false) { // 편의점 도달 가능
				q.push(pyeon[i]);
				check[i] = true;
			}
		}
	}
	cout << "sad" << endl;
}

int main() {
	cin >> testcase;
	int x = 0;
	int y = 0;
	for (int i = 0; i < testcase; i++) {
		cin >> n;
		cin >> x >> y;
		home = make_pair(x, y);
		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			pyeon.push_back(make_pair(x, y));
		}
		cin >> x >> y;
		rock = make_pair(x, y);
		solve();
		pyeon.clear();
	}
	return 0;
}
