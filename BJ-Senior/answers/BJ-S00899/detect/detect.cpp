#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V;
int d[N],v[N],a[N];
int p[N],tmp[N],tot;
void subtask1(){
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	int cnt=0,ans=m;
	for(int i=1;i<=n;i++){
		int x=lower_bound(p+1,p+m+1,d[i])-p;
		if(x==m+1){
			continue;
		}
		if(a[i]==0){
			if(v[i]>V){
				cnt++;
			}
		}else if(a[i]>0){
			long long res=1ll*v[i]*v[i]+2ll*a[i]*(p[m]-d[i]);
			if(res>1ll*V*V){
				cnt++;
			}
		}else{
			if(1ll*v[i]*v[i]<1ll*(p[x]-d[i])*-2*a[i]){
				continue;
			}
			long long res=1ll*v[i]*v[i]+2ll*a[i]*(p[x]-d[i]);
			if(res>1ll*V*V){
				cnt++;
			}
		}
	}
	cout<<cnt<<' ';
	for(int state=0;state<(1<<m);state++){
		tot=0;
		for(int i=1;i<=m;i++){
			if(state&(1<<(i-1))){
				tmp[++tot]=p[i];
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			int x=lower_bound(tmp+1,tmp+tot+1,d[i])-tmp;
			if(x==tot+1){
				continue;
			}
			if(a[i]==0){
				if(v[i]>V){
					res++;
				}
			}else if(a[i]>0){
				long long ress=1ll*v[i]*v[i]+2ll*a[i]*(tmp[tot]-d[i]);
				if(ress>1ll*V*V){
					res++;
				}
			}else{
				if(1ll*v[i]*v[i]<1ll*(tmp[x]-d[i])*-2*a[i]){
					continue;
				}
				long long ress=1ll*v[i]*v[i]+2ll*a[i]*(tmp[x]-d[i]);
				if(ress>1ll*V*V){
					res++;
				}
			}
		}
		if(res==cnt){
			ans=min(ans,tot);
		}
	}
	cout<<m-ans<<'\n';
}
void subtask2(){
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x=lower_bound(p+1,p+m+1,d[i])-p;
		if(x==m+1){
			continue;
		}
		if(a[i]==0){
			if(v[i]>V){
				cnt++;
			}
		}else if(a[i]>0){
			long long res=1ll*v[i]*v[i]+2ll*a[i]*(p[m]-d[i]);
			if(res>1ll*V*V){
				cnt++;
			}
		}else{
			if(1ll*v[i]*v[i]<1ll*(p[x]-d[i])*-2*a[i]){
				continue;
			}
			long long res=1ll*v[i]*v[i]+2ll*a[i]*(p[x]-d[i]);
			if(res>1ll*V*V){
				cnt++;
			}
		}
	}
	cout<<cnt<<' ';
	if(cnt==0){
		cout<<m<<'\n';
	}else{
		cout<<m-1<<'\n';
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		if(n<=20&&m<=20){
			subtask1();
		}else{
			subtask2();
		}
	}
	return 0;
}
