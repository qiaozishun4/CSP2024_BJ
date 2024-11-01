#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("duel.in");
ofstream cout("duel.out");

const int N = 1e5+5;
int r[N];
int m[N];
int n;

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> r[i];
	}
	sort(r, r+n);
	int nowr = r[0];
	int c = 0;
	for(int i=0; i<n; i++) {
		if(r[i] != nowr) {
			nowr = r[i];
			c++;
		}
		m[c]++;
	}
	c++;
	int s = m[0];
	for(int i=1; i<c; i++) {
		s = max(0, s-m[i]);
		s += m[i];
	}
	cout << s << endl;
	return 0;
}
