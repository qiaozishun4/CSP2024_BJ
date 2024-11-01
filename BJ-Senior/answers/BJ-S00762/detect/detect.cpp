#include <bits/stdc++.h>
using namespace std;
int t,n,m,L,V,cnt,d[100005],v[100005],a[100005],p[100005];
bool vis[1000005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t,++t;
	while(--t){
		map <int,int> det;
		cin>>n>>m>>L>>V,cnt=0;
		for(int i=1;i<=n;++i) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;++i) cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=n;++i){
			if(p[m]-d[i]<0) break;
			if(a[i]>=0){
				for(int j=m;j>=0;--j){
					if(p[j]<d[i]) continue;
					if(sqrt((v[i]*v[i]+2*a[i]*(p[j]-d[i]))*1.0)>V){
						++cnt,++det[j];
					}
				}
			}
			else if(a[i]<0){
				for(int j=m;j>=0;--j){
					if(p[j]<d[i]) continue;
					if((v[i]*v[i]+2*a[i]*(p[j]-d[i]))*1.0<0) continue;
					if(sqrt((v[i]*v[i]+2*a[i]*(p[j]-d[i]))*1.0)>V){
						++cnt,++det[j];
					}
				}
			}
		}
		cout<<cnt<<" "<<1<<"\n";
	}
	return 0;
}

/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
