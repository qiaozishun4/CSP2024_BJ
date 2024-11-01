#include<bits/stdc++.h>
using namespace std;
int n,D[20],C[20],H[20],S[20],x,ans;
char s[5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[1]=='A') x=1;
		else if(s[1]=='T') x=10;
		else if(s[1]=='J') x=11;
		else if(s[1]=='Q') x=12;
		else if(s[1]=='K') x=13;
		else x=s[1]-'0';
		if(s[0]=='D') D[x]=1;
		else if(s[0]=='C') C[x]=1;
		else if(s[0]=='H') H[x]=1;
		else if(s[0]=='S') S[x]=1;
	}
	for(int i=1;i<=13;i++){
		if(D[i]==0) ans++;
		if(C[i]==0) ans++;
		if(H[i]==0) ans++;
		if(S[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}