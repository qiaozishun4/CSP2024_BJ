#include <bits/stdc++.h>
#define N 200010
using namespace std;
int T,n;
int A[N],color[N],C[N];
void solve(int x){
	memset(color,0,sizeof(color));
	memset(C,0,sizeof(C));
	int cnt=0;
	while(x){
		color[++cnt]=(x%2);
		x=(x>>1);
	}
}
int dfs(){
	int anss=0,ans=0;
	for(int i=0;i<=(1<<(n-1));i++){
		ans=0;
		int pos0=-1,pos1=-1;//表示最近的一个位置
		solve(i);
		for(int j=1;j<=n;j++){
			if(color[j]==0&&pos0==-1){
				pos0=j;
				continue;
			}
			if(color[j]==1&&pos1==-1){
				pos1=j;
				continue;
			}
			if(color[j]==1){
				if(A[pos1]==A[j]) ans+=A[j];
				pos1=j;
				continue;
			}
			if(color[j]==0){
				if(A[pos0]==A[j]) ans+=A[j];
				pos0=j;
				continue;
			}
		}
		anss=max(ans,anss);
	}
	return anss;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		memset(A,0,sizeof(A));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>A[i];
		}
		cout<<dfs()<<endl;
	}
	return 0;
}
