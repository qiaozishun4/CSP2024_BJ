#include<bits/stdc++.h>
using namespace std;
inline void file(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
}
int main(){
	file();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<14;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else{
			cout<<3<<endl;
		}
	}
	return 0;
}