#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,M=1e6+5,inf=2147483647;
int T,n,m;
struct car{
	double d,v,a,xl,xr;
	int pl,pr;
} c[N];
double eps=0.0001,L,V,p[M];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	// cout<<"TOK";
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(int j=1;j<=m;j++){
				if(c[i].d>p[j]) continue;
				if(sqrt(c[i].v*c[i].v+2.0*c[i].a*(p[j]-c[i].d))>V){
					flag=true;
				}
			}
			if(flag) cnt++;
		}
		cout<<cnt<<" ";
		if(cnt==0) cout<<m;
		else cout<<m-1;
		cout<<endl;
	}

	return 0;
}
/*
1
3 5 100 10
5 6 1
0 1 15
0 1 20
1 3 5 7 9
*/
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15

*/