#include<bits/stdc++.h>
using namespace std;
const int N=70;
int n,ans=0;
int h[N];
int Type(char x){
	if(x=='D') return 0;
	if(x=='C') return 1;
	if(x=='H') return 2;
	if(x=='S') return 3;
}
int Change(char x){
	if(x>='2' && x<='9') return x-'0';
	if(x=='A') return 1;
	if(x=='T') return 10;
	if(x=='J') return 11;
	if(x=='Q') return 12;
	if(x=='K') return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char op,x;
		cin>>op>>x;
		//cout<<op<<" "<<x<<"\n";
		int y=Type(op);
		int z=Change(x);
		h[y*13+z]++;
		//cout<<y<<" "<<z<<"\n";
	}
	for(int i=1;i<=52;i++){
		if(h[i]==0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

