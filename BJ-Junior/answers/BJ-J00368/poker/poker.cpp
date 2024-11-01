#include<bits/stdc++.h>
using namespace std;
int n;
bool d[50],c[50],h[50],s[50];//方片，草花，红桃，黑桃
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	char a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='D'){
			if(b>='2'&&b<='9') d[b-'0']=true;
			else if(b=='A') d[1]=true;
			else if(b=='T') d[10]=true;
			else if(b=='J') d[11]=true;
			else if(b=='Q') d[12]=true;
			else if(b=='K') d[13]=true;
		}
		else if(a=='C'){
			if(b>='2'&&b<='9') c[b-'0']=true;
			else if(b=='A') c[1]=true;
			else if(b=='T') c[10]=true;
			else if(b=='J') c[11]=true;
			else if(b=='Q') c[12]=true;
			else if(b=='K') c[13]=true;
		}
		else if(a=='H'){
			if(b>='2'&&b<='9') h[b-'0']=true;
			else if(b=='A') h[1]=true;
			else if(b=='T') h[10]=true;
			else if(b=='J') h[11]=true;
			else if(b=='Q') h[12]=true;
			else if(b=='K') h[13]=true;
		}
		else if(a=='S'){
			if(b>='2'&&b<='9') s[b-'0']=true;
			else if(b=='A') s[1]=true;
			else if(b=='T') s[10]=true;
			else if(b=='J') s[11]=true;
			else if(b=='Q') s[12]=true;
			else if(b=='K') s[13]=true;
		}
	}
	int ans=0;
	for(int i=1;i<=13;i++){
		if(d[i]==false) ans++;
		if(c[i]==false) ans++;
		if(h[i]==false) ans++;
		if(s[i]==false) ans++;
	}
	cout<<ans;
	return 0;
}