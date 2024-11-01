#include<bits/stdc++.h>
using namespace std;
long long T,N;
int tails[8]={0,-1,1,7,4,2,0,8},sticks[10]={6,2,5,5,4,5,6,3,7,6},ans[21]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,204,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld",&N);
		if(N<=20){
			printf("%d\n",ans[N]);
			continue;
		}
		if(N%7==0){
			for(int j=1;j<=N/7;j++) printf("8");
			printf("\n");
			continue;
		}
		if(N%7>1&&N>42){
			if(N%7==6) printf("6");
			else printf("%d",tails[N%7]);
			for(int j=1;j<=N/7;j++) printf("8");
			printf("\n");
			continue;
		}
		if(N%6==0){
			printf("2");
			for(int j=1;j<=N/6-2;j++) printf("0");
			printf("8\n");
			continue;
		}
		if(N%7==1){
			printf("2");
			for(int j=1;j<=N/6-1;j++) printf("0");
			printf("%d",tails[(N+1)%6]);
			printf("\n");
			continue;
		}
		if(N%7>1){
			if(N%7==6) printf("6");
			else printf("%d",tails[N%7]);
			for(int j=1;j<=N/7;j++) printf("8");
			printf("\n");
			continue;
		}
	}
	return 0;
}
