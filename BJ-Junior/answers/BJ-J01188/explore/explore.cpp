#include<bits/stdc++.h>
using namespace std;
char ditu[10000][10000];
bool weizhi[10000][10000];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t,n,m,k,x,y,d,ans,v,z,nv,nz;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int ij=0;ij<n;++ij)
			for(int ji=0;ji<m;++ji)
				cin>>ditu[ij][ji];
		nv=x-1;
		nz=y-1;
		for(int l=0;l<k;++l)
		{
			if(nv<n&&nz<m)
			{
			    v=nv;
			    z=nz;
			    weizhi[nv][nz]=true;
				if(d==0)z++;
				else if(d==1)v++;
				else if(d==2)z--;
				else if(d==3)v--;
				if(ditu[v][z]=='x'||v<0||v>=n||z<0||z>=m)
				{
					d=(d+1)%4;
					v=nv;
					z=nz;
					continue;
				}
				nv=v;
				nz=z;
				weizhi[nv][nz]=true;
			}
		}
		for(int l=0;l<n;++l)
			for(int ly=0;ly<m;++ly)
				if(weizhi[l][ly]==true)
                {
                    ans++;
                    weizhi[l][ly]=false;
                }
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
