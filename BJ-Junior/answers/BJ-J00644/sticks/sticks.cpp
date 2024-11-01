#include<bits/stdc++.h>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
void dfs(int x,bool h){
	int ws=(x+6)/7;
	for(int i=0;i<=9;++i){
		if(h&&i==0)continue;
		int xx=x-a[i];
		int wsxx=(xx+6)/7;
		if(ws-1==wsxx&&x-a[i]!=1&&x-a[i]>=0){
			printf("%d",i);
			dfs(x-a[i],0);
			break;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if(x==1){
			printf("%d\n",-1);
			continue;
		}
		dfs(x,1);
		printf("\n");
	}
	return 0;
}
