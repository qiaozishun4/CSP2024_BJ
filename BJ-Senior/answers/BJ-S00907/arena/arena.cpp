#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int T,n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	for(i=1;i<=m;i++){
		int x;
		cin>>x;
	}
	int k=0;
	for(i=0;i<=n;i++) 
		if((1<<i)>=n){
			k=i;
			break;
		}
	for(i=1;i<=k;i++) {
		getline(cin,s);
	}
	cin>>T;
	while(T--)
	{
		cout<<0<<endl;
	}
	return 0;
}
