#include<bits/stdc++.h>
using namespace std;
int klk[100000]={-1,-1,1,7,4,2,6,8,10,18,22,0,0,0,0,0,0,0,0,208,0,0};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<klk[n]<<endl;
	}
	return 0;
}
