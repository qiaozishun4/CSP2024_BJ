#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int T;
int V2;
struct Car
{
	int d,v,a;
}c[100005];
struct Range//需要有测速器开着的区间
{
	int l,r;
}a[100005];
bool useda[100005];
int vcur2;
int cnt1,cnt2;
int p[100005];
/*int bis(int k,int l,int r)
{
	if(l>=r)return l;
	if(k==p[l]) return l;
	if(k==p[r]) return r;
	int mid=(l+r)/2;
	if(k>p[mid])
	{
		return bis(k,mid+1,r);
	}
	else if(k==p[mid])
	{
		return mid;
	}
	else
	{
		return bis(k,l,mid-1);
	}
}*/

bool cmp(Range u,Range v)
{
	return u.l<v.l;
}


int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(useda,0,sizeof(useda));
		scanf("%d%d%d%d",&n,&m,&L,&V);
		V2=V*V;
		cnt1=0;
		cnt2=0;
		vcur2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
		}
		sort(p+1,p+m+1);
		cnt1=0;
		for(int i=1;i<=n;i++)//对于每一个车
		{
			if(c[i].a>=0)
			{
				if(c[i].d<=p[m]) 
				{
					vcur2=(p[m]-c[i].d-1)*2*c[i].a+(c[i].v*c[i].v);
				    if(vcur2>V2)
				    { 
				        cnt1++;
					}
			    }
			}
			else//a<0
			{
				//int nr=bis(c[i].d,1,m);
				int nr=0,fur=0;
				for(int j=1;j<=m;j++)
				{
					if(p[j]>c[i].d)
					{
						nr=j;
						break;
					}
				}
				double xmax=(V2-(c[i].v*c[i].v))/(2*c[i].a);
				int flag1=0;
				for(int j=nr;j<=m;j++)
				{
					if(double(p[j])>=double(c[i].d)+xmax)
					{
						fur=j-1;
						flag1=1;
						break;
					}
				}
				if(flag1==0)fur=m;
				if(nr<=fur)
				{
				    cnt2++;
				    a[cnt2].l=nr;
				    a[cnt2].r=fur;
			    }
			}
		}
		int ans=cnt1+cnt2;
		printf("%d ",ans);
		int tmp=0;
		sort(a+1,a+cnt2+1,cmp);
		for(int i=cnt2;i>=1;i--)
		{
			if(a[i].r==m&&cnt1!=0)
			{
				useda[i]=1;
			}
		}
		for(int i=1;i<=cnt2;i++)
		{
			if(useda[i]==1)continue;
			for(int j=i+1;j<=cnt2;j++)
			{
				if(useda[j]==1)continue;
				if(a[i].r>a[j].l)
				{
					a[i].l=a[j].l;
					useda[j]=1;
				}
			}
		}
		for(int i=1;i<=cnt2;i++)
		{
			if(useda[i]!=1)tmp++;
		}
		if(cnt1!=0)tmp++;
		int sum=m-tmp;
		printf("%d\n",sum);
	}
    return 0;
}
