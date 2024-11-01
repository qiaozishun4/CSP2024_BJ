#include<bits/stdc++.h>
using namespace std;
int n,ans;char a,b;
map<char,int> mp;
bool h[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	mp['D']=1;mp['C']=2;mp['H']=3;mp['S']=4;
	for(int i=2;i<=9;i++) mp[i+'0']=i;
	mp['A']=1;mp['T']=10;mp['J']=11;mp['Q']=12;mp['K']=13;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		h[mp[a]][mp[b]]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			ans+=h[i][j]==0;
		}
	}
	cout<<ans<<"\n";
	return 0;//zpyzpy
}
