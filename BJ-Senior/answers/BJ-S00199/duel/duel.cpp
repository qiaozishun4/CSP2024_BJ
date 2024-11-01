#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5, MAXV = 1e5+5;

int n, r, tot, res;
int vis[MAXV];

struct Mon{
	int val;
	int cnt;
}mon[MAXN];

bool cmp(Mon a, Mon b){
	return a.val < b.val;
}

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &r);
		if (vis[r]) mon[vis[r]].cnt++;		
		else{
			tot++;
			mon[tot].val = r;
			mon[tot].cnt = 1;
			vis[r] = tot;
		}
	}
	/*
	for (int i=1; i<=tot; i++){
		cout << mon[i].val << " " << mon[i].cnt << endl;
	}
	*/
	sort(mon+1, mon+tot+1, cmp);
	res = 0;
	for (int i=1; i<=tot; i++){
		res = max(res-mon[i].cnt, 0)+mon[i].cnt;
		//cout << mon[i].val << " " << mon[i].cnt << " " << res << endl;		
	}
	printf("%d", res);
	return 0;
}

