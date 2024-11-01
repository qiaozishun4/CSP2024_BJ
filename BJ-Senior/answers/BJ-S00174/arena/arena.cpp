/*
14:30 开考
14:41 切 T1，T1 过水
14:49 T2 会了
15:52 T2 切了，无敌
16:32 想不出 T3，难受
17:41 T3 调不出，崩溃
17:50 要崩了
18:03 扔 T3，滚去写 T4
18:26 旁边有一只狗一直在狂吠，纸张
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define int long long
using namespace std;
int T,n,m,a[100010],ap[100010],c[100010];
string s[100010];
signed main(void) {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> ap[i];
	for (int i=1;i<=m;i++) cin >> c[i];
	int p=ceil(log2(n));
	for (int i=1;i<=p;i++) cin >> s[i];
	for (int i=1;i<=p;i++) s[i]='%'+s[i];
	cin >> T;
	for (;T--;) {
		int x[4];
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for (int i=1;i<=n;i++) a[i]=ap[i]^x[i%4];
		int ans=0;
		for (int i=1;i<=m;i++) {
			queue<int> q;
			for (int j=1;j<=c[i];j++) {
				q.push(a[j]);
			}
			int v=1;
			for (;q.size()>1;) {
				int d=q.size()/2;
				for (int j=1;j<=d;j++) {
					int a1=q.front();
					q.pop();
					int a2=q.front();
					q.pop();
					if (s[v][j]=='1') {
						if (a1>=v) q.push(a1);
						else q.push(a2); 
					} else {
						if (a2>=v) q.push(a2);
						else q.push(a1);
					}
				}
				v++;
			}
			ans^=(i*q.front());
		}
		cout << ans << endl;
	}
	return 0;
}