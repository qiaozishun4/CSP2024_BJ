#include <bits/stdc++.h>
using namespace std;

struct Node {int x,y;}c[100005];
int T,n,m,L,V,d[100005],v[100005],a[100005],p[100005],s[1000005],l[100005],r[100005],num,cnt,cur;
int divi(int x,int y) {return (x % y) ? (x / y + 1) : (x / y);}
bool cmp(Node x,Node y) {return x.y < y.y;}

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		for (int i = 1;i <= n;i++) cin >> d[i] >> v[i] >> a[i];
		for (int i = 1;i <= m;i++) cin >> p[i];
		cur = 1;
		for (int i = 1;i <= L + 1;i++)
			if (p[cur] == i - 1) s[i] = s[i - 1] + 1,cur++;
			else s[i] = s[i - 1];
		for (int i = 1;i <= n;i++) l[i] = r[i] = -1;
		for (int i = 1;i <= n;i++)
			if (a[i] >= 0 && v[i] > V) l[i] = d[i],r[i] = L;
			else if (a[i] > 0 && d[i] + (V * V - v[i] * v[i]) / (a[i] * 2) + 1 <= L) l[i] = d[i] + (V * V - v[i] * v[i]) / (a[i] * 2) + 1,r[i] = L;
			else if (a[i] < 0 && v[i] > V) l[i] = d[i],r[i] = min(d[i] + divi(v[i] * v[i] - V * V,-2 * a[i]) - 1,L);
		num = cnt = 0;
		for (int i = 1;i <= n;i++)
			if (l[i] >= 0 && s[r[i] + 1] > s[l[i]]) c[++num] = Node{l[i],r[i]};
		cout << num << " ";
		sort(c + 1,c + num + 1,cmp);
		cur = 1;
		while (cur <= num) {
			int p1;
			for (int i = c[cur].y;i >= c[cur].x;i--)
				if (s[i + 1] > s[i]) {p1 = i;break;}
			cnt++;
			while (cur <= num && c[cur].x <= p1) cur++;
		}
		cout << m - cnt << endl;
	}
	return 0;
}