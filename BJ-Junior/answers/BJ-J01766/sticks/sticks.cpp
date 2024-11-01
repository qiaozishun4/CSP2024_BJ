#include<bits/stdc++.h>
using namespace std;
int n,T;
int st[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){cout<<-1<<endl;continue;}
		for(int i=0;;i++){
			int ans=0;
			int p=i;
			while(p){
				ans+=st[p%10];
				p/=10;
			}
			if(ans==n){
				cout<<i<<endl;
				break;
			}
		}
	}
}
