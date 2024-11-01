#include<bits/stdc++.h>
using namespace std;
int f[22]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int a[7]={888,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		if(x<=21)cout<<f[x];
		else{
			printf("%d",a[x%7]);
			for(int i=1;i<=(x+6)/7-3;i++){
				printf("8");
			}
		}
		puts("");
	}
	return 0;
}
