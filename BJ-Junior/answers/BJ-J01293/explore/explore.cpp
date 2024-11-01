#include <iostream>
using namespace std;
long long T,n,m,k,x,y,d,res;
string s[1005];
long long a[1005][1005],map[1005][1005];
int dfs(int x,int y,int k,int d){
	if(map[x][y]==0) map[x][y]=1;
	if(a[x][y]==0||a[x][y]==1) {
		dfs(x,y,k-1,(d+1)%4);
		res++;
	}
	if(d==0) {
		dfs(x,y+1,k-1,d);
		res++;
	}
	if(d==1) {
		dfs(x+1,y,k-1,d);
		res++;
	}
	if(d==2){
		 dfs(x,y-1,k-1,d);
		 res++;
	if(d==3){
		dfs(x-1,y,k-1,d);
		res++;
	}
}
int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		cin>>m;
		for(int j=0;j<n;j++){
			cin>>s;
			for(int q=0;q<m;q++){
				if(s[j]=='x')_ a[j][q]=1;
				else a[j][q]=2;
			}
		}
		dfs(x,y,k,d);
		cout<<res<<endl;
		res=0;
	}
	return 0;
}
