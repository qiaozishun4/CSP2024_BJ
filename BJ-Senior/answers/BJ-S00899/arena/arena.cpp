#include<bits/stdc++.h>
using namespace std;
const int K=21;
const int N=1e5+5;
int n,m,k;
int a_[N],a[N];
int c[N],q[N];
bool d[K][(1<<K)];
int init(int l,int r,int round){
	if(l==r){
		if(l==1) q[r]=l;
		return l;
	}
	int mid=(l+r)/2;
	int x=init(l,mid,round-1);
	int y=init(mid+1,r,round-1);
	int res;
	if(d[round][l/(1<<round)+1]){
		if(a[y]>=round){
			res=y;
		}else{
			res=x;
		}
	}else{
		if(a[x]>=round){
			res=x;
		}else{
			res=y;
		}
	}
	if(l==1){
		q[r]=res;
	}
	return res;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a_[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(k=K;k>=0;k--){
		if((1<<k)<n){
			k++;
			break;
		}
	}
	for(int i=1;i<=k;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='1'){
				d[i][j+1]=1;
			}
		}
	}
	int T;
	cin>>T;
	while(T--){
		int X0,X1,X2,X3;
		cin>>X0>>X1>>X2>>X3;
		for(int i=1;i<=n;i++){
			if(i%4==0) a[i]=(a_[i]^X0);
			if(i%4==1) a[i]=(a_[i]^X1);
			if(i%4==2) a[i]=(a_[i]^X2);
			if(i%4==3) a[i]=(a_[i]^X3);
		}
		init(1,1<<k,k);
		long long ans=0;
		for(int i=1;i<=m;i++){
			ans=(ans^(1ll*i*q[c[i]]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
5 5
0 0 0 0 0
5 4 1 2 3
1001
10
1
4
2 1 0 0
1 2 1 0
0 2 3 1
2 2 0 1
*/
