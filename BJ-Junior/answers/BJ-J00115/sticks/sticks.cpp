#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
long long int f[100010]={0};
long long int b[100010]={0};
long long int niu[20]={6,2,5,5,4,5,6,3,7,6};
long long int ooo(long long int i)
{
	if(b[i]==1)
	{
		return f[i];
	}
	else
	{
		if(i<=1)
		{
			f[i]=(-1);
		}
		else
		{
			long long int str=0;
			long long int ubt=0;
			long long int flag=0;
			for(long long int j1=0;j1<=9;j1++)
			{
				if((i<niu[j1]) || (i==niu[j1] && j1==0))
				{
					continue;
				}
				if(niu[j1]==i && j1!=0)
				{
					///cout<<"i="<<j1<<" niu="<<niu[j1]<<endl;
					ubt=1;
					f[i]=j1;
					break;
				}
				else
				{
					long long int cur=i-niu[j1];
					ooo(cur);
					if(f[cur]>0)
					{
						long long int opt=f[cur]*10+j1;
						//cout<<"cur="<<cur<<" l="<<f[cur]<<" i="<<j1<<" opt="<<opt<<endl;
						if(flag==0)
						{
							flag=1;
							str=opt;
						}
						else
						{
							str=min(str,opt);
						}
					}
				}
			}
			if(ubt==0)
			{
				f[i]=str;
			}
		}
		b[i]=1;
		return f[i];
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long int t=0,n=0;
    cin>>t;
    for(long long int j1=1;j1<=t;j1++)
    {
		cin>>n;
		long long int str=ooo(n);
		cout<<str<<endl;
	}
    return 0;
}


