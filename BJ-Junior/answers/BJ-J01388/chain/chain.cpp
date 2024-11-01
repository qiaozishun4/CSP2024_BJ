#include<bits/stdc++.h>
using namespace std;
long long s[100010][200010],st=1,xx,l[100010];
long long n,k,q;
bool f;
void dfs(long long r,long long c){
	if(r==0){
		if(st==c)f=1;
		return;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=l[i];j++){
			for(long long w=1;w<k;w++){
				if(i!=xx&&s[i][j]==st){
					xx=i;
					st=s[i][j+w];
					dfs(r-1,c);
					st=s[i][j];
					if(f)return;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>n>>k>>q;
	for(long long i=1;i<=n;i++){
		cin>>l[i];
		for(long long j=1;j<=l[i];j++){
			cin>>s[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		f=0;
		st=1;
		xx=0;
		long long r,c;
		cin>>r>>c;
		dfs(r,c);
		if(f)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
