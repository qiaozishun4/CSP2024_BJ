#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,a[505],tmp;
char c[105][10];

map<char,ll> mp;

int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	mp['A']=1;
	mp['T']=10;
	mp['J']=11;
	mp['Q']=12;
	mp['K']=13;
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>c[i][1]>>c[i][2];		
		tmp=0;		
		if(c[i][2]>='2'&&c[i][2]<='9'){
			tmp=c[i][2]-'0';
		}else{
			tmp=mp[c[i][2]];
		}
			
		if(c[i][1]=='D'){
			a[tmp]++;
		}
		if(c[i][1]=='C'){
			a[13+tmp]++;
		}
		if(c[i][1]=='H'){
			a[26+tmp]++;
		}
		if(c[i][1]=='S'){
			a[39+tmp]++;
		}
	}
	
	for(ll i=1;i<=52;i++){
		if(a[i]==0){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
