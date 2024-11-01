#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 1e5+5;
int n,m,T,a[N],a_[N],c[N];
string d[20];
int x[5],K;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a_[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	K = ceil(log2(n));
	for(int i=1;i<=K;i++){
		cin>>d[i];
		d[i] = " "+d[i];
	}
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			a[i] = (a_[i] ^ x[i%4]);
		}
	}
	return 0;
}
