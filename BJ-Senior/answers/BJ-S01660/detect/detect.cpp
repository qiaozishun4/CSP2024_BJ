#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
using namespace std;
ll read(){
	ll k=0;char c=getchar();bool flag=1;
	while(!isdigit(c)){if(c=='-')flag=0;c=getchar();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	if(flag)return k;else return -k;
}
char readc(){
	char c=getchar();
	while(!isgraph(c))c=getchar();
	return c;
}
string reads(){
	string s="";char c=getchar();
	while(!isgraph(c))c=getchar();
	while(isgraph(c)){s+=c;c=getchar();}
	return s;
}
const int N=1e5+10;
int n,m,mi;
long double L,V;
long double p[N];
bool vis[N];
struct node{
	long double d,v,a,pos;
}a[N];
vector<int>ve[N];
unordered_map<int,bool>mp,tmp,ttmp;
void dfs(int p,int cho){
	if(cho>=mi)return ;
	if(p==m+1){
		if(tmp!=mp)return ;
		mi=cho;
		return ;
	}
	dfs(p+1,cho);
	unordered_map<int,bool>ttmp=tmp;
	for(int i:ve[p])tmp[i]=1;
	dfs(p+1,cho+1);
	tmp=ttmp;
	return ;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T=read();
	while(T--){
		n=read(),m=read(),L=read(),V=read();
		mp.clear();
		tmp.clear();
		ttmp.clear();
		mi=1e9;
		for(int i=1;i<=n;++i){
			a[i].d=(long double)read();
			a[i].v=(long double)read();
			a[i].a=(long double)read();
		}
		for(int i=1;i<=m;++i){
			p[i]=read();
			ve[i].clear();
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i].a>0.){
				int pos=m+1;
				for(int j=lb(p+1,p+1+m,a[i].d)-p;j<=m;++j){
					if(sqrtl(a[i].v*a[i].v+a[i].a*(p[j]-a[i].d)*2)>V){
						pos=j;
						break;
					}
				}
				if(pos!=m+1){
					++cnt;
					mp[i]=1;
				}
				for(int j=pos;j<=m;++j)ve[j].pb(i);
			}
			else if(a[i].a==0.){
				if(a[i].v>V){
					int pos=lb(p+1,p+1+m,a[i].d)-p;
					++cnt;
					mp[i]=1;
					for(int j=pos;j<=m;++j)ve[j].pb(i);
				}
			}
			else{
				if(a[i].v<=V)continue;
				int pos=0,st=lb(p+1,p+1+m,a[i].d)-p;
				for(int j=m;j>=st;--j){
					if(sqrtl(a[i].v*a[i].v+a[i].a*(p[j]-a[i].d)*2)>V){
						pos=j;
						break;
					}
				}
				if(pos>=st){
					++cnt;
					mp[i]=1;
				}
				for(int j=st;j<=pos;++j)ve[j].pb(i);
			}
		}
		dfs(1,0);
		printf("%d %d\n",cnt,m-mi);
	}
	return 0;
}
//by 2c_s in luogu