#include<bits/stdc++.h>
using namespace std;
bool p[152];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<100;i++) { p[i]=false; }
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int a,b;
		if(s[0]=='D') a=0;
		else if(s[0]=='C') a=1;
		else if(s[0]=='H') a=2;
		else if(s[0]=='S') a=3;
		
		if(s[1]=='A') b=0;
		else if(s[1]=='2') b=1;
		else if(s[1]=='3') b=2;
		else if(s[1]=='4') b=3;
		else if(s[1]=='5') b=4;
		else if(s[1]=='6') b=5;
		else if(s[1]=='7') b=6;
		else if(s[1]=='8') b=7;
		else if(s[1]=='9') b=8;
		else if(s[1]=='T') b=9;
		else if(s[1]=='J') b=10;
		else if(s[1]=='Q') b=11;
		else if(s[1]=='K') b=12;
		int ss=a*13+b;
		p[ss]=true;
	}
	int ans=0;
	for(int i=0;i<52;i++){
		if(!p[i]) ans++;
	}
	cout<<ans;
	
	return 0;
	
}
