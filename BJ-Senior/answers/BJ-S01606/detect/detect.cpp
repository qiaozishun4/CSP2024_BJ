#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
int n1[100005][3], m1[100005];
int b1[100005];//work or not&only or no
bool b2[100005];
bool cmp(int a1,int a2)
{
    return a1<a2;
}
int main()
{
	freopen("detect3.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int s=1;s<=t;s++)
    {
		memset(b2,0,sizeof(b2));
		int n,m,l;
		double v;
		cin>>n>>m>>l>>v;
		for(int i1=1;i1<=n;i1++)
		{
			int d,v,a;
			scanf("%d %d %d",&d,&v,&a);
			n1[i1][0]=d;n1[i1][1]=v;n1[i1][2]=a;
		}
		for(int i1=1;i1<=m;i1++)
		{
			int p;
			scanf("%d",&p);
			m1[i1]=p;
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(n1[i][0]>n1[j][0])
				{
					int a1=n1[i][0];
					int a2=n1[i][1];
					int a3=n1[i][2];
					n1[i][0]=n1[j][0];
					n1[i][1]=n1[j][1];
					n1[i][2]=n1[j][2];
					n1[j][0]=a1;
					n1[j][1]=a2;
					n1[j][2]=a3;
				}
			}
			cout<<n1[i][0]<<" "<<n1[i][1]<<" "<<n1[i][2]<<endl;
		}
		*/
		sort(m1+1,m1+m+1,cmp);
		int ans1=0;
		for(int n0=1;n0<=n;n0++)
		
		{
			for(int m0=1;m0<=m;m0++)
			{
				if(m1[m0]<n1[n0][0])
					continue;
				if((float(pow(n1[n0][1],2))+float((2*n1[n0][2]*(m1[m0]-n1[n0][0]))))<=0)
					break;
				double sp;
				sp=sqrt(float(pow(n1[n0][1],2))+float((2*n1[n0][2]*(m1[m0]-n1[n0][0]))));
				if(sp>v)
				{
					if(!b2[n0])
					{
						ans1++;b2[n0]=1;
					}
				}
			}
		}
		int ans2=0;
		for(int i1=1;i1<=m;i1++)
		{
			if(!b2[i1])
				ans2++;
		}
		cout<<ans1<<" "<<m-ans2<<'\n';
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}

