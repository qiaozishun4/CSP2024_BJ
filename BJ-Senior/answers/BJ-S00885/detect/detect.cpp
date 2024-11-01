#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define LL long long

const int N=1e5+5;
const double eps=1e-7;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];

inline int fnd(double x,int o){
	int l=1,r=m+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(p[mid]+o*eps>x) r=mid;
		else l=mid+1;
	}
	return l;
}


int pre[N];
vector<int> iq[N];
inline void solve(){
	memset(pre,0,sizeof(pre));
    scanf("%d%d%d%d",&n,&m,&L,&V);
    rep(i,1,n) scanf("%d%d%d",&d[i],&v[i],&a[i]);
    rep(i,1,m) scanf("%d",&p[i]);p[m+1]=0x3f3f3f3f;
    rep(i,1,m) iq[i].clear();
    int cnt=0;
    rep(i,1,n){
        if(a[i]>0){
            if(V<v[i]){
                int j=fnd(d[i],1);
                //printf("j=%d\n",j);
                if(j<=m) cnt++;
                iq[m].push_back(j);
            }else{
                double x=(V*V-v[i]*v[i])*1.0/(2*a[i]);
                int j=fnd(d[i]+x,-1);
                //printf("j=%d\n",j);
                if(j<=m) cnt++;
                iq[m].push_back(j);
            }
        }else if(a[i]==0){
        	if(V<v[i]){
        		int j=fnd(d[i],1);
        		//printf("j=%d\n",j);
        		if(j<=m) cnt++;
                iq[m].push_back(j);
            }
        }else{
        	if(V>=v[i]) continue;
        	double x=(V*V-v[i]*v[i])*1.0/(2*a[i]);
            int j=fnd(d[i]+x,1);j--;
            int k=fnd(d[i],1);
            //printf("j=%d k=%d\n",j,k);
            if(k<=j && k<=m) cnt++;
            iq[j].push_back(k);
        }
    }
    rep(i,1,m){
    	pre[i]=pre[i-1];
    	for(auto v:iq[i]){
    		if(v>i) continue;
    		if(pre[i]-pre[v-1]==0) pre[i]++;
    	}
    }
    printf("%d %d\n",cnt,m-pre[m]);
}
int T;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}