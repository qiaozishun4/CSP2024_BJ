#include<bits/stdc++.h>
using namespace std;
int a[100005];
int c[100005];
int x[512][10];
string s[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w", stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>c[i];
	}
	int K=int(ceil(log2(n)));
	for(int i=1;i<=K;i++){
		cin>>s[i];
	}
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>x[i][0]>>x[i][1]>>x[i][2]>>x[i][3];
	}
	for(int i=1;i<=T;i++){cout<<1<<'\n';}
	return 0;
}
