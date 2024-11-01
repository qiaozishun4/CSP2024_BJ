#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long t,n,minn,ans;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n; minn=1e10+5;
		if(n<=7){
			if(n==1){cout<<-1<<"\n"; continue;}
			if(n==2){cout<<1<<"\n"; continue;}
			if(n==3){cout<<7<<"\n"; continue;}
			if(n==4){cout<<4<<"\n"; continue;}
			if(n==5){cout<<2<<"\n"; continue;}
			if(n==6){cout<<6<<"\n"; continue;}
			if(n==7){cout<<8<<"\n"; continue;}
		}else{
			for(long long i=1;i<=pow((n/6),10);i++){
				int nn=i; ans=0;
				while(nn){
					ans+=a[nn%10];
					nn/=10;
				} if(ans==n) minn=min(minn,i);
			}
		} cout<<minn<<"\n";
	} 
	return 0;
}
