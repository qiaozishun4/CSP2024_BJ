#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
int T;
int n,m,L;
long long V;
int d[N],v[N],a[N],p[M];
int h[N],fars;
struct node{
	int l,r;
}xd[N];

void solve1(){
	int cnt1=0;
	for(int i=1;i<=n;i++){
		if(v[i]>V && d[i]<=fars){
			cnt1++;
		}
	}
	if(cnt1>0) cout<<cnt1<<" "<<m-1<<"\n";
	else cout<<cnt1<<" "<<m<<"\n";
	return ;
}
void solve2(){
	int cnt1=0;
	for(int i=1;i<=n;i++){
		if(d[i]>fars) continue;
		long long s=fars-d[i];
		long long vv=((long long)v[i]*v[i])+((long long)2*a[i]*s);
		if(vv>V*V){
			cnt1++;
		}
	}
	if(cnt1>0) cout<<cnt1<<" "<<m-1<<"\n";
	else cout<<cnt1<<" "<<m<<"\n";
	return ;
}
void solve3(){
	return ;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int tot1=0,tot2=0,tot3=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]>0) tot2++;
			else if(a[i]==0) tot1++;
			else if(a[i]<0) tot3++;
		}
		fars=0;
		for(int i=1;i<=m;i++){
			cin>>p[i];
			fars=max(fars,p[i]);
		}
		if(tot1==n){
			solve1();
		}else if(tot2==n){
			solve2();
		}else if(tot3==n){
			solve3();
		}
	}
	return 0;
}
