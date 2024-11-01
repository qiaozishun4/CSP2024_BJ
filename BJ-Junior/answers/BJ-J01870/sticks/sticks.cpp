#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int num[10]={-1,-1,1,7,4,2,0,8,10,18};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		if(n<=10){
			cout<<num[n];
		}else if(n%7==0){	
			for(int j=1;j<=n/7;j++){
				cout<<8;
			}
			cout<<endl;	
		}else if(n%7==1){
			cout<<1<<0;
			for(int j=1;j<=n/7-1;j++){
				cout<<8;
			}
			cout<<endl;	
		}		
	}	
	return 0;
}	
