#include<bits/stdc++.h>
using namespace std;
const int N = 2*(1e5)+5;
int T,n,a[N],TT,ls;
long long ans;
bool DFS(int i,int r,int b,long long aaa){
	//if(TT == 7) cout << i << endl;
	if(i == n+1){
		ans = max(ans,aaa);
		//if(TT == 7)cout << ans << endl;
		if(clock() > (1000000*(1.0*TT/T))) return 0;
		return 1;
	}
	ls = 0;
	if(b == a[i]) ls = b;
	if(DFS(i+1,r,a[i],aaa+ls) == 0) return 0;
	ls = 0;
	if(r == a[i]) ls = r;
	if(DFS(i+1,a[i],b,aaa+ls) == 0) return 0;
	return 1;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T-TT){
		TT++;
		cin >> n;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		DFS(1,0,0,0);
		cout << ans << endl;
	}
	return 0;
}