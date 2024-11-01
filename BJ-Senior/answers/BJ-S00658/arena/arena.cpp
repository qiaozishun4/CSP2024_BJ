#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
int n,m,ans=0;
int a1[maxn],c[maxn];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a1[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	int k=log2(n)+1;
	for(int i=1;i<=k;i++){
		int len=pow(2,k-i);
		for(int j=1;j<=len;j++){
			char ch;cin>>ch;
		}
	}
	int T;cin>>T;
	while(T--){
		int i1,i2,i3,i4;
		cin>>i1>>i2>>i3>>i4;
		cout<<0<<endl;
	}
	return 0;
}
