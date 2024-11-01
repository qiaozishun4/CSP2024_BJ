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
const int N=2e5+10;
int n,a[N];
bitset<N>bs;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		int ans=-1e9;
		for(int k=0;k<(1<<n);++k){
			bs=k;
			int sum=0;
			for(int i=1;i<=n;++i){
				for(int j=i-1;j>=1;--j){
					if(bs[i-1]==bs[j-1]){
						if(a[i-1]==a[j-1])sum+=a[i-1];
						break;
					}
				}
			}
			ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//by 2c_s in luogu