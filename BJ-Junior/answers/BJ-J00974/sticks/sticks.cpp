#include<bits/stdc++.h>
using namespace std;
int n;
int num[11]={6,2,5,5,4,5,6,3,7,6};
int t;
int getu(int numa)
{
    int ans=0;
    while(numa>0)
    {
        ans+=num[numa%10];
        numa/=10;
    }
    return ans;
}
bool flag;
int main()
{
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
	for(int az=1;az<=t;az++)
	{
		flag=false;
		scanf("%d",&n);
		for(int i=1;i<=100005;i++)
		{
			if(getu(i)==n)
			{
				printf("%d\n",i);
				flag=true;
				break;
			}
		}
		if(!flag)printf("-1\n");
	}
    return 0;
}
