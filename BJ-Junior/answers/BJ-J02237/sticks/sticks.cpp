#include<bits/stdc++.h>
using namespace std;

const int ans[15]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
const int pre[7]={108,188,200,208,288,688,888};

int t;
int n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=14){
			cout<<ans[n]<<'\n';
		}
		else{
			cout<<pre[(n-1)%7];
			for(int i=3;i<=(n-1)/7;++i){
				cout<<'8';
			}
			cout<<'\n';
		}
	}
	return 0;
}
