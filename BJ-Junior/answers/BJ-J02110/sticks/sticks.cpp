#include<bits/stdc++.h>
using namespace std;
int l[20]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int f=0;
		cin>>n;
		if(n<2&&f==0){
			cout<<-1<<endl;
			f=1;
		}
		if(n%7==0&&f==0){
			while(n>1){
				cout<<8;
				n-=7;
			}
			cout<<endl;
			f=1;
		}
		if((n-1)%7==0&&f==0){
			n-=1;
			while(n>1){
				cout<<8;
				n-=7;
			}
			cout<<1<<endl;
			f=1;
		}
	}
	return 0;
}