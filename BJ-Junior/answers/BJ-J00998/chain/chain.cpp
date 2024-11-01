#include <bits/stdc++.h>
using namespace std;

struct Node {int x,id;}p[200005];
int T,n,k,q,l[100005],num[2][200005],r1;
vector<int> s[100005],num1[2][100005],fst[100005];
bool flag[105][200005];
bool cmp(Node x,Node y) {return x.x != y.x ? x.x < y.x : x.id < y.id;}

int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k >> q;
		for (int i = 1;i <= n;i++) s[i].clear(),num1[0][i].clear(),num1[1][i].clear();
		for (int i = 1;i <= n;i++) {
			cin >> l[i];
			s[i].push_back(0);
			fst[i].push_back(0);
			num1[0][i].push_back(0);
			num1[1][i].push_back(0);
			for (int j = 1;j <= l[i];j++) {
				cin >> p[j].x;
				s[i].push_back(p[j].x);
				p[j].id = j;
				fst[i].push_back(0);
				num1[0][i].push_back(0);
				num1[1][i].push_back(0);
			}
			sort(p + 1,p + l[i] + 1,cmp);
			for (int j = 1;j <= l[i];j++)
				if (p[j].x == p[j - 1].x) fst[i][p[j].id] = fst[i][p[j - 1].id];
				else fst[i][p[j].id] = p[j].id;
		}
		memset(flag,0,sizeof flag);
		memset(num,0,sizeof num);
		num[0][1] = 1000000;
		for (int r = 1;r <= 100;r++) {
			for (int i = 1;i <= n;i++) {
				r1 = 0;
				for (int j = 1;j <= l[i];j++) {
					if (j <= r1) num[1][s[i][j]]++,flag[r][s[i][j]] = 1,num1[1][i][fst[i][j]]++;
					if (num[0][s[i][j]] - num1[0][i][fst[i][j]] >= 1) r1 = j + k - 1;
				}
			}
			for (int i = 1;i <= 200000;i++) num[0][i] = num[1][i],num[1][i] = 0;
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= l[i];j++) num1[0][i][j] = num1[1][i][j],num1[1][i][j] = 0;
		}
		while (q--) {
			int r,c;
			cin >> r >> c;
			if (flag[r][c]) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}