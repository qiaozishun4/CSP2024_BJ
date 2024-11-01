#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,d;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		d=n%7;
		if(n<7){
			if(d==0) printf("-1");
			else if(d==1) printf("-1");
			else if(d==2) printf("1");
			else if(d==3) printf("7");
			else if(d==4) printf("4");
			else if(d==5) printf("2");
			else if(d==6) printf("6");
		}else{
				if(d==0)	for(ll i=1;i<=n/7;i++)	printf("8");
			else if(d==1){
				printf("10");
				for(ll i=1;i<=(n/7)-1;i++) printf("8");
			}else if(d==2){
				printf("1");
				for(ll i=1;i<=n/7;i++)	printf("8");
			}else if(d==3){
				if(n/7<2){
					printf("22");
					for(ll i=1;i<=(n/7)-1;i++) printf("8");
				}else{
					printf("200");
					for(ll i=1;i<=(n/7)-2;i++) printf("8");
				}
			}else if(d==4){
				printf("20");
				for(ll i=1;i<=(n/7)-1;i++) printf("8");
			}else if(d==5){
				printf("2");
				for(ll i=1;i<=n/7;i++)	printf("8");
			}else{
				printf("6");
				for(ll i=1;i<=n/7;i++)	printf("8");
			}
		}
		printf("\n");
	}
	return 0;
}