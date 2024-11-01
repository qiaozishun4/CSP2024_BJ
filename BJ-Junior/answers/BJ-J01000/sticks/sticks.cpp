#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}else if(n%7==1&&n!=1){
			cout<<10;
			for(int i=1;i<=(n-1)/7-1;i++){
				cout<<8;
			}
		}else{
			cout<<-1;
		}
	}
	return 0;
}
