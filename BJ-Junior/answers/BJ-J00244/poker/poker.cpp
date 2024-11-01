#include <bits/stdc++.h>
using namespace std;
long long m[10][20],n,a,b,ans=52;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D'){
			a=1;
		}else if(s[0]=='C'){
			a=2;
		}else if(s[0]=='H'){
			a=3;
		}else{
			a=4;
		}
		if(s[1]=='T'){
			b=10;
		}else if(s[1]=='J'){
			b=11;
		}else if(s[1]=='Q'){
			b=12;
		}else if(s[1]=='K'){
			b=13;
		}else if(s[1]=='A'){
			b=1;
		}else{
			b=s[1]-'0';
		}
		if(!m[a][b]) ans--;
		m[a][b]=1; 
	}
	cout<<ans;
	return 0;
}
