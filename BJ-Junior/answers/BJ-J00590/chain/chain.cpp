#include<bits/stdc++.h>
using namespace std;
int n,k,q;
vector<int>s[100005];
bool num[200005]={};
void slove1(int n,int k,int q){
	for(int i=1;i<=n;++i){
		int l;cin>>l;s[i].resize(l);
		for(int j=0,one=-1000000;j<l;++j){
			cin>>s[i][j];
			if(s[i][j]==1)one=j;
			if(j>0&&j-one<k)num[s[i][j]]=1;
		}
	}while(q--){
		int r,c;
		cin>>r>>c;
		cout<<num[c]<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t;cin>>t;
	while(t--){
		for(int i=0;i<=100004;++i)s[i].clear();
		cin>>n>>k>>q;
		slove1(n,k,q);
		memset(num,0,sizeof(num));
	}
    return 0;
}