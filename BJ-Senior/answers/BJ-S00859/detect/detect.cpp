#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,m,l,V,p[N];
bool vis[N];
struct car{
	int d,v,a;
}c[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for (int o=1;o<=t;o++){
		int num=0,num1=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>l>>V;
		for (int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			
		}
		
		for (int i=1;i<=m;i++){
			cin>>p[i];
			bool flag=false;
			//memset(vis,0,sizeof(vis));
			for (int j=1;j<=n;j++){
				if (c[j].d>p[i])  continue;
				if (vis[j]==true){
					//flag=true;
					continue;					
				}
				if (c[j].a==0 && c[j].v>V)
				{
					num++;
					vis[j]=true;
					flag=true;
					continue;
				}
				double speed=sqrt(c[j].v*c[j].v+2*c[j].a*(p[i]-c[j].d));
				if (speed>V)
				{
					flag=true;
					vis[j]=true;
					num++;
					continue;
				}
			}
			if (flag==false)
				num1++;
		}
		cout<<num<<" "<<num1<<"\n";		
	}
	return 0;
}
