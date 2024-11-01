#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

vector<int> a;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	//int now = 0;
	for (int i = 1; i < a.size(); i ++ ) {
		/*while ((a[i] <= a[now] || st[now] == 1) && now < i - 1) {
			now ++ ;
		}
		if (a[i] > a[now]) {
			st[now ++ ] = 1;
		} else if (a[i] > a[i - 1] && st[i - 1] == 0) {
			st[i - 1] = 1;
		}*/
		for (int j = i - 1; j >= 0; j -- ) {
			if (a[i] > a[j]) {
				a.erase(a.begin() + j);
				i -- ;
				break;
			}
		}
	}
	cout << a.size() << endl;
	return 0;
}
