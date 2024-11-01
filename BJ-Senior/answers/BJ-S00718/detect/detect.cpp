#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5+5;
bool File;
int T;
int n,m,L;
double V;
struct car {
	int d,v,a,c = 0;
}a[N];
vector<int> p[N];
int x,c = 0;
int main() {
	File = freopen("detect.in","r",stdin);
	File = freopen("detect.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		for (int i = 0;i < n;i++) {
			cin >> a[i].d >> a[i].v >> a[i].a;
		}
		for (int i = 0;i < m;i++) {
			cin >> x;
			for (int j = 0;j < n;j++) {
				double y = a[j].v * a[j].v + (2 * (a[j].a) * (a[j].d - x));
				//cout << i << '	' << j << '	' << (2 * (a[j].a) * (x - a[j].d)) << ' ' << y << '?' << V * V << '	' << x;
				//cout << "i" << i << "j" << j << " V0:" << a[j].v << "	a:" << a[j].a << "	S:" << a[j].d - x << "	y:" << y;
				if (y > V * V) {
					//cout << "	OOL";
					p[i].push_back(j);
					if (a[j].c == 0) {
						c++;
						//cout << "	ONE";
					}
					a[j].c++;
				}
				//cout << endl;
			}
		}
		cout << c << ' ';
		c = 0;
		for (int i = 0;i < m;i++) {
			//cout << endl;
			//cout << i << endl;
			bool t = 1;
			for (int j = 0;j < p[i].size();j++) {
				//cout << p[i][j] << ' ' << a[p[i][j]].c << endl;
				if (a[p[i][j]].c == 1) {
					t = 0;
				}
			}
			if (t) {
				//cout << "DEL";
				c++;
				for (int j = 0;j < p[i].size();j++) {
					a[p[i][j]].c--;
				}
			}
			//cout << endl;
		}
		//cout << endl;
		cout << c << endl;
	}
	return 0;
}/*
1 
5 1 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
15
*/