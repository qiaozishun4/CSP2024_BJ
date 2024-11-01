#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
int T;
int n,m,L,V;
int d[N+5],v[N+5],a[N+5];
int p[N+5];

double get_speed(ll v,ll a,ll dis){
	return max(sqrt(((double)v*(double)v)+2.0*(double)a*(double)dis),0.0);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		int flag=-2;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(flag==-2&&a[i]<0)
				flag=-1;
			if(flag==-2&&a[i]==0)
				flag=0;
			if(flag==-2&&a[i]>0)
				flag=1;
		}
		for(int i=1;i<=m;i++)
			cin>>p[i];
		if(n<=20&&m<=20){
			ll res=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					double speed=get_speed(v[i],a[i],p[j]-d[i]);
					if(speed>(double)V&&d[i]<=p[j]){
						res++;
						break;
					}
				}
			}
			ll maxn=0;
			for(ll k=0;k<=(1<<m)-1;k++){
				ll res2=0;
				for(ll i=1;i<=n;i++){
					for(ll j=1;j<=m;j++){
						if(!(k&(1ll<<(j-1))))
							continue;
						double speed=get_speed(v[i],a[i],p[j]-d[i]);
						if(speed>(double)V&&d[i]<=p[j]){
							res2++;
							break;
						}
					}
				}
				if(res2==res){
					ll cnt=0;
					for(ll j=1;j<=m;j++)
						if(!(k&(1ll<<(j-1ll))))
							cnt++;
					maxn=max(cnt,maxn);
				}
			}
			cout<<res<<" "<<maxn<<"\n";
		}
		else if(!flag){
			ll res=0;
			for(int i=1;i<=n;i++)
				if(v[i]>V&&d[i]<=p[m])
					res++;
			if(res==0)
				cout<<res<<" "<<m<<"\n";
			else
				cout<<res<<" "<<m-1<<"\n";
			continue;
		}
		else if(flag==1){
			ll res=0;
			for(int i=1;i<=n;i++){
				double speed=get_speed(v[i],a[i],p[m]-d[i]);
				if(speed>(double)V&&d[i]<=p[m])
					res++;
			}
			if(res==0)
				cout<<res<<" "<<m<<"\n";
			else
				cout<<res<<" "<<m-1<<"\n";
		}
	}
	return 0;
}
//caijiuduolian