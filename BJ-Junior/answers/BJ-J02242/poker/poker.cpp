#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p=0,num,d[55],c[55],h[55],s[55];
string str;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>str;
		if(str[1]=='A')num=1;
		else if(str[1]=='T')num=10;
		else if(str[1]=='J')num=11;
		else if(str[1]=='Q')num=12;
		else if(str[1]=='K')num=13;
		else num=str[1]-'0';
		if(str[0]=='D'&&d[num]==0){
			p++;
		}
		else if(str[0]=='C'&&c[num]==0){
			p++;
		}
		else if(str[0]=='H'&&h[num]==0){
			p++;
		}
		else if(str[0]=='S'&&s[num]==0){
			p++;
		}
		if(str[0]=='D')d[num]=1;
		else if(str[0]=='C')c[num]=1;
		else if(str[0]=='H')h[num]=1;
		else if(str[0]=='S')s[num]=1;
	}
	cout<<52-p;
	return 0;
	}
