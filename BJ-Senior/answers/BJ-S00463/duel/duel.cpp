#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pii pair<int,int>

const int N=1e5+5,V=1e5+5;
int n,a[N],buc[V],vmax,ans,lst[V],last;
bool vis[V];
vector<int> vec;
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x),buc[x]++;
		if(!vis[x]) vis[x]=true,vec.push_back(x);
	}
	if(vec.size()==1){printf("%d\n",n);return 0;}
	sort(vec.begin(),vec.end());
	last=1;
	for(int i=0;i<vec.size();i++) lst[vec[i]]=buc[vec[i]];
	for(int i=0;i<vec.size()-1;i++){
		if(i==last) last=i+1;
		while(last<vec.size()){
			if(buc[vec[i]]>=lst[vec[last]]) buc[vec[i]]-=lst[vec[last]],last++;
			else{
				lst[vec[last]]-=buc[vec[i]],buc[vec[i]]=0;
				break;
			}
		}
	}
	for(auto i:vec) ans+=buc[i];
	printf("%d\n",ans);
	return 0;
}
/*
	希望是附丽于存在的。有存在，便有希望。有希望，便是光明。
*/