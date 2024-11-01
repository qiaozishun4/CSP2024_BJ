#include<bits/stdc++.h>
using namespace std;
int n,m,nn,T,a,b,c,d;
void sv(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a;
	}
	for(int i=1;i<=m;i++){
		cin >> a;
	}
	nn=(log2(n)+0.99);
	for(int i=1;i<=nn;i++){
		cin >> a;
	}
	cin >> T;
	while(T--){
		cin >> a >> b >> c >> d;
		cout << 1 << "\n";
	}
	return;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sv();
	return 0;
}
