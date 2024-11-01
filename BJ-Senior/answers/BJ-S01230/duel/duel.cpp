#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,r[100005];
int v[100005];
int ans;
bool cmp(int x,int y){
	return x<y;
}
void dfs(int x,int p){
	if(p>n) return;
	if(r[p]==r[x] || v[p]==1){
		dfs(x,p+1);
		return;
	}
	ans--;
	v[p]=1;
	return;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&r[i]);
		v[i]=0;
	}
	sort(r+1,r+n+1,cmp);
	ans=n;
	for(int i=1;i<=n;++i){
		dfs(i,i+1);
	}
	printf("%d\n",ans);
	return 0;
}
