#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int d[maxn],v[maxn],a[maxn],p[maxn];
int t;
int n,m,L,V;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		bool flag1=true;
		bool flag2=true;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0)flag1=false;
			if(a[i]<=0)flag2=false;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		if(flag1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(d[i]<=p[m]&&v[i]>V)cnt++;
			}
			cout<<cnt<<' '<<(m-1)<<endl;
			continue;
		}
		if(flag2){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(d[i]>p[m])continue;
				else{
					int s=p[m]-d[i];
					double speed=sqrt(v[i]*v[i]*1.0+(2*a[i]*s*1.0));
					double o=V*1.0;
					if(speed>o)cnt++;
				}
			}
			cout<<cnt<<' '<<(m-1)<<endl;
			continue;
		}
	}
	return 0;
}
