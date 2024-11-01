#include<bits/stdc++.h>
using namespace std;
int u[10]={6,2,5,5,4,5,6,3,7,6};
int dg(int sy,int ws,int sz,bool st){
	if (sy==0 and ws==0){
		return sz;
	}
	int xi=0;
	int wans;
	xi+=st;
	for (;xi<=9;xi++){
		if (sy-u[xi]<0 or (sy-u[xi]==0 and ws>1)){
			continue;
		}
		wans=dg(sy-u[xi],ws-1,sz*10+xi,0);
		if (wans){
			return wans;
		}
	}
	return 0;
}
void q(){
	int n;
	scanf("%d",&n);
	if (n<2){
		printf("-1\n");
		return;
	}
	int i,ans;
	for (i=max(n/7-1,1);1;i++){
		ans=dg(n,i,0,1);
		if (ans){
			break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		q();
	}
	fclose(stdin);
	fclose(stdout);
}
