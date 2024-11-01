#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,ans1,p[100005],sum[1000005],l,r;
double r1,eps=1e-6;
struct CAR{
	double d,a;
	int v;
}car[100005];
bool vis[1000005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		memset(sum,0,sizeof(sum));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];sum[p[i]]++;vis[p[i]]=1;
	    }
	    for(int i=1;i<=L;i++)sum[i]+=sum[i-1];
	    ans1=0;
	    for(int i=0;i<n;i++){
			l=L;
			if(car[i].a==0||car[i].v>V)r=int(car[i].d);
			else{r1=double(V*V-car[i].v*car[i].v);r1/=2*car[i].a;
			r=floor(r1)+1;r+=int(car[i].d);if(r<=L)car[i].v=V+1;}
			if(car[i].v>V){if(sum[L]-sum[r]+vis[r]>0)ans1++;}
		}
		if(ans1!=0)cout<<ans1<<' '<<m-1<<endl;
		else cout<<ans1<<' '<<m<<endl;
    }
	return 0;
}
