#include<bits/stdc++.h>
using namespace std;
int t,n;
int s[10];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	s[1]=-1;
	s[2]=1;
	s[3]=7;
	s[4]=4;
	s[5]=2;
	s[6]=6;
	while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<"\n";
		}else if(n%7==1&&n!=1){
			cout<<"10";
			n-=8;
			for(int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<"\n";
		}else{
			if(n<7){
				cout<<s[n]<<"\n";
			}else{
				cout<<s[n%7];
				n-=n%7;
				for(int i=1;i<=n/7;i++){
					cout<<"8";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}