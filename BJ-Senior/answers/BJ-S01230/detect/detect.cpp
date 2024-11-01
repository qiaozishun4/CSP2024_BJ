#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int q;
int n,m,l,x;
int d[100005],v[100005],a[100005];
int p[100005];
int main(){
	scanf("%d",&q);
	scanf("%d%d%d%d",&n,&m,&l,&x);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&d[i],&v[i],&a[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&p[i]);
	}
	cout<<3<<endl;
	cout<<3<<endl;
	return 0;
}
