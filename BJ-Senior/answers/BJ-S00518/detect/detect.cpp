#include <bits/stdc++.h>
using namespace std;
int n,m,l,v;
double p[100005];
struct node{
	int d,a,p1=0,p2=0;
	double v,ds1,ds2;
} c[100005];
map<int,int> mp;
int main()
{	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int ans1=0,ans2=0,mind=2147483647;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].v>v) ans1++;
			if(c[i].v>v) mind=min(mind,c[i].d);
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=m;i++){
			if(mind>p[i]) ans2++;
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}