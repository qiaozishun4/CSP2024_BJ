#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

ifstream cin("detect.in");
ofstream cout("detect.out");

const int N = 1e5+5;
const int L = 1e6+5;
struct car {
	int d, v, a;
	int x;
} c[N];
int carin[N];
int p[N];
pair<int, int> tp[N];
vector<int> deed[N];
int deed_num;
int can_del_num;

bool can_del(int x) {
	for(auto t : deed[x]) {
		if(carin[t] <= 1) {
			return false;
		}
	}
	return true;
}

void do_del(int x) {
	for(auto t : deed[x]) {
		carin[t]--;
	}
}

int main() {
	//cout << "DEBUG" << endl;
	int t;
	cin >> t;
	while(t--) {
		int n, m, l, v;
		cin >> n >> m >> l >> v;
		//cout << n << " " << m << " " << l << " " << v << endl;
		
		memset(c, 0, sizeof(c));
		memset(carin, 0, sizeof(carin));
		memset(p, 0, sizeof(p));
		memset(tp, 0, sizeof(tp));
		deed_num = can_del_num = 0;
		for(int i=0; i<=m; i++) {
			deed[i].clear();
		}
		
		for(int i=0; i<n; i++) {
			cin >> c[i].d >> c[i].v >> c[i].a;
			if(c[i].a < 0) {
				c[i].x = int(-(c[i].v*c[i].v*1.0)/(2.0*c[i].a));
			} else {
				c[i].x = L;
			}
			//cout << i << "C: " << c[i].d << " " << c[i].v << " " << c[i].a << " " << c[i].x << endl;
		}
		for(int i=0; i<m; i++) {
			cin >> p[i];
			//cout << i << "P: " << p[i] << endl;
		}
		for(int i=0; i<n; i++) {
			int j = lower_bound(p, p+m, c[i].d)-p;
			if(j==m) {
				continue;
			}
			//cout << i << "S: " << j << " " << p[j] << endl;
			
			if(c[i].a == 0) {
				if(c[i].v <= v) {
					continue;
				}
				while(j < m) {
					//cout << i << " " << j << endl;
					deed[j].push_back(i);
					if(carin[i] == 0) {
						deed_num++;
					}
					carin[i]++;
					j++;
				}
				continue;
			}
			while(j < m && p[j] <= c[i].x+c[i].d) {
				//cout << p[j] << " " << sqrt(2*c[i].a*(p[j]-c[i].d)+c[i].v*c[i].v) << " " << v << endl;
				if(sqrt(2*c[i].a*(p[j]-c[i].d)+c[i].v*c[i].v) > v) {
					//cout << i << " " << j << endl;
					deed[j].push_back(i);
					if(carin[i] == 0) {
						deed_num++;
					}
					carin[i]++;
				}
				j++;
			}
		}
		for(int i=0; i<m; i++) {
			tp[i].first = deed[i].size();
			tp[i].second = i;
		}
		sort(tp, tp+m);
		for(int i=0; i<m; i++) {
			if(can_del(i)) {
				do_del(i);
				can_del_num++;
			}
		}
		cout << deed_num << " " << can_del_num << endl;
	}
	return 0;
}
