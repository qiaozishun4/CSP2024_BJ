#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		if(n==1)printf("-1\n");
		else if(n==3)printf("7\n");
		else if(n==4)printf("4\n");
		else if(n==5)printf("2\n");
		else if(n==6)printf("0\n");
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)printf("8");
			printf("\n");
		}
		else if(n%7==1){
			printf("10");
			for(int i=1;i<=(n-8)/7;i++)printf("8");
			printf("\n");
		}
		else if(n%7==2){
			printf("1");
			for(int i=1;i<=(n-2)/7;i++)printf("8");
			printf("\n");
		}
		else if(n%7==3){
			printf("22");
			for(int i=1;i<=(n-10)/7;i++)printf("8");
			printf("\n");
		}
		else if(n%7==4){
			printf("20");
			for(int i=1;i<=(n-11)/7;i++)printf("8");
			printf("\n");
		}
		else if(n%7==5){
			printf("2");
			for(int i=1;i<=(n-5)/7;i++)printf("8");
			printf("\n");
		}
		else if(n%7==6){
			printf("6");
			for(int i=1;i<=(n-6)/7;i++)printf("8");
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}