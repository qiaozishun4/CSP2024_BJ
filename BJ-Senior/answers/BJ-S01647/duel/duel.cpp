#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int r[N];
int cnt;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &r[i]);
	}
	sort(r+1,r+1+n);
	int l0 = 1, r0 = 2;
	while(r0 != n+1){
		if(r[l0] == r[r0]){
			r0++;
		} else if(r[r0] > r[l0]){
			cnt++;
			r0++;
			l0++;
		}
	}
	printf("%d", n-cnt);
	return 0;
}

