#include <bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,8,7},ans=9999999,sum=0,sum2=0,t=0,n=0,nn=0,nnn=0;
bool check=true;
void s(int n)
{
	for (int i=0;i<10;i++)
	{
		if ((check) && (i==0))
		{
			continue;
		}
		else if (sum2>n)
        {
            if (t==1)
            {
                t--;
            }
            else
            {
                t/=10;
            }
            sum2-=nn;
            sum-=nnn;
        }
        else if (sum2==n)
        {
            if (sum<ans)
            {
                if (t==1)
                {
                    t--;
                }
                else
                {
                    t/=10;
                }

                ans=sum;
                sum2-=nn;
                sum-=nnn;
            }
            check=true;
        }
		else
		{
		    if (i!=0)
            {
                check=false;
            }
            nn=num[i];
            sum2+=num[i];
            if (t==0)
            {
                t++;
            }
            else
            {
                t*=10;
            }
            nnn=i*t;
            sum+=i*t;
            s(n);
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin >>n;
    for (int i=0;i<n;i++)
    {
		int q;
		cin >>q;
		s(q);
		if (ans==9999999)
		{
			cout <<"-1";
		}
		else
		{
			cout <<ans <<endl;
		}
		ans=9999999;
		sum=0;
		sum2=0;
		t=0;
		n=0;
		nn=0;
		nnn=0;
	}
    return 0;
}
