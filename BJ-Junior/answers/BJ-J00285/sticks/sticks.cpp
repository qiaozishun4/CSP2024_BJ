#include <bits/stdc++.h>

using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int minx=-1;
		if(n<=1) minx=-1;
		else if(n==2) minx=1;
		else if(n==3) minx=7;
		else if(n==4) minx=4;
		else if(n==5) minx=2;
		else if(n==6) minx=6;
		else if(n==7) minx=8;
		else if(n==8) minx=10;
		else if(n==9) minx=18;
		else if(n==10) minx=22;
		else if(n==11) minx=20;
		else if(n==12) minx=28;
		else if(n==13) minx=68;
		else if(n==14) minx=88;
		else if(n==15) minx=108;
		else if(n==16) minx=188;
		else if(n==17) minx=200;
		else if(n==18) minx=208;
		else if(n==19) minx=288;
		else if(n==20) minx=688;
		else{
			int p=n/7;
			for(int i=1;i<=p;i++){
				cout<<8;
			}
			continue;
		}
		cout<<minx<<endl;
	}
	return 0;
}
