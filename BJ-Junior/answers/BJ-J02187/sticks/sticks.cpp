#include<bits/stdc++.h>
using namespace std;
int T,n,tt[]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=13){cout<<tt[n]<<'\n';continue;}
		int t=n/7,a=n-t*7;
		if(!a){for(int i=1;i<=t;i++) cout<<8;cout<<'\n';}
		else if(a==1){cout<<"10";for(int i=1;i<t;i++) cout<<8;cout<<'\n';}
		else if(a==2){cout<<"18";for(int i=1;i<t;i++) cout<<8;cout<<'\n';}
		else if(a==3){cout<<"200";for(int i=1;i<t-1;i++) cout<<8;cout<<'\n';}
		else if(a==4){cout<<"20";for(int i=1;i<t;i++) cout<<8;cout<<'\n';}
		else if(a==5){cout<<"2";for(int i=1;i<=t;i++) cout<<8;cout<<'\n';}
		else{cout<<"6";for(int i=1;i<=t;i++) cout<<8;cout<<'\n';}
	}
	return 0;
}