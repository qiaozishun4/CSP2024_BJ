#include<bits/stdc++.h>
using namespace std;
#define int long long
int a;
int sum[10]={6,2,5,5,4,5,6,3,7,6};
int stc(int n){
	int s=0;
	while(n>0){
		s+=sum[n%10];
		n/=10;
	}
	return s;
}
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int j=1;j<=T;j++){
		cin>>a;
		if(a==1){cout<<"-1"<<endl;continue;}
		if(a==2){cout<<"1"<<endl;continue;}
		if(a==3){cout<<"7"<<endl;continue;}
		if(a==4){cout<<"4"<<endl;continue;}
		for(int i=1;i<=1000000005;i++){
			int sum=stc(i);
			if(sum==a){ cout<<i<<endl; break;}
		}
		
	}
	return 0;
}
