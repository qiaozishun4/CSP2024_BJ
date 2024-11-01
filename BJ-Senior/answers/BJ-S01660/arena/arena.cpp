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
int n,m,aa[N],c[N],a[N],K,T;
vector<int>d[N],ve;
bitset<N>bs;
int change(int x){
	int res=0;
	while((1<<res)<x)++res;
	return res;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)aa[i]=read();
	for(int i=1;i<=m;++i)c[i]=read();
	K=change(n);
	for(int i=1;i<=K;++i){
		for(int j=1;j<=1<<K-i;++j)d[i].pb((int)readc()-'0');
	}
	if(n<=8&&m<=8){
		int T=read();
		unordered_map<int,bool>mp;
		while(T--){
			int x[5];
			for(int i=0;i<4;++i)x[i]=read();
			for(int i=1;i<=n;++i)a[i]=aa[i]^x[i%4];
			int ans=0;
			for(int i=1;i<=m;++i){
				int k=change(c[i]);
				mp.clear();
				for(int times=0;times<1<<(1<<k);++times){
					bs=times;
					for(int pos=0;pos<1<<k;++pos){
						if(pos+1<=c[i])continue;
						if(bs[pos])a[pos+1]=INT_MAX;
						else a[pos+1]=0;
					}
					ve.clear();
					for(int j=1;j<=1<<k;++j)ve.pb(j);
					for(int j=1;j<=k;++j){
						vector<int>now;
						for(int p=1;p<ve.size();p+=2){
							if(d[j][p>>1]){
								if(a[ve[p]]>=j)now.pb(ve[p]);
								else now.pb(ve[p-1]);
							}
							else{
								if(a[ve[p-1]]>=j)now.pb(ve[p-1]);
								else now.pb(ve[p]);
							}
						}
						ve.clear();
						ve=now;
					}
					mp[ve[0]]=1;
				}
				int sum=0;
				for(auto i:mp)sum+=i.fi;
				ans^=sum*i;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	int T=read();
	while(T--){
		int x[5];
		for(int i=0;i<4;++i)x[i]=read();
		for(int i=1;i<=n;++i)a[i]=aa[i]^x[i%4];
		int ans=0;
		for(int i=1;i<=m;++i){
			int k=change(c[i]);
			ve.clear();
			for(int j=1;j<=n;++j)ve.pb(j);
			for(int j=1;j<=k;++j){
				vector<int>now;
				for(int p=1;p<ve.size();p+=2){
					if(d[j][p>>1]){
						if(a[ve[p]]>=j)now.pb(ve[p]);
						else now.pb(ve[p-1]);
					}
					else{
						if(a[ve[p-1]]>=j)now.pb(ve[p-1]);
						else now.pb(ve[p]);
					}
				}
				ve.clear();
				ve=now;
			}
			ans^=ve[0]*i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//by 2c_s in luogu
