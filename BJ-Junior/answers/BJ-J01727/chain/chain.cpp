#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N=100010;
vector<int>s[N];
int T,n,kkk,q,l,rrr,c,t;
bool pianfen(){
	if(rrr==1){
		for(int i=0;i<n;i++){
			vector<int>p;
			for(int j=0;j<(int)s[i].size();j++){
				if(s[i][j]==1)p.push_back(j);
				if(s[i][j]==c)
					for(auto it:p)
						if(j-it+1>=2&&j-it+1<=kkk){
							puts("1");
							return true;
						}
			}
		}
		puts("0");
		return true;
	}
	return false;
}
bool dfs(int k,int l,int r,int dep){//第k个人，l～r 接龙了dep次
	if(dep>=rrr){
		for(int i=l+1;i<=r;i++){
			if(s[k][i]==c){
				puts("1");
				return true;
				break;
			}
		}
		return false;
	}
	for(int i=0;i<n;i++){
		if(i==k)continue;
		for(int j=0;j<(int)s[i].size();j++)
			if(s[i][j]==s[k][r])
				for(int cnt=j+1;cnt<(int)s[i].size()&&cnt-j+1<=kkk;cnt++)
					if(dfs(i,j,cnt,dep+1))return true;
	}
	return false;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&kkk,&q);
		for(int i=0;i<=n;i++)s[i].clear();
		for(int i=0;i<n;i++){
			scanf("%d",&l);
			while(l--){
				scanf("%d",&t);
				s[i].push_back(t);
			}
		}
		while(q--){
			scanf("%d%d",&rrr,&c);
			//if(pianfen())continue;
			bool flag=false;
			for(int i=0;i<n;i++){
				flag=false;
				for(int j=0;j<(int)s[i].size()&&!flag;j++)
					if(s[i][j]==1)
						for(int k=j+1;k<(int)s[i].size()&&k-j+1<=kkk;k++)
							if(dfs(i,j,k,1)){flag=true;break;}
				if(flag)break;
			}
			if(!flag)puts("0");
		}
	}
	return 0;
}