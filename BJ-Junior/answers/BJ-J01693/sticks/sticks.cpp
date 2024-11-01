#include<bits/stdc++.h>
using namespace std;

int q(int x,int y)
{
	if(x%y==0) return x/y;
	return x/y+1;
}

int w(int x)
{
	if(x==0) return 6;
	if(x==1) return 2;
	if(x==2) return 5;
	if(x==3) return 5;
	if(x==4) return 4;
	if(x==5) return 5;
	if(x==6) return 6;
	if(x==7) return 3;
	if(x==8) return 7;
	if(x==9) return 6;
	else return x;
}

int shuliang(int x)
{
	int maxn=0;
	int ans=0;
	for(int i=10;;i*=10)
	{
		if(x%i==x)
        {
            maxn=i;
            break;
        }
	}
	for(int i=maxn;i>=10;i=i/10)
	{
		ans+=w((x%i)/q(i,10));
	}
	return ans;
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T ;
	for(int i=1;i<=T;i++)
	{
		int n;
		bool flag=false;
		cin >> n ;
		int weishu=q(n,7);
		for(int j=pow(10,weishu-1);j<=pow(10,weishu)&&!flag;j++)
		{
			if(shuliang(j)==n)
			{
				cout << j ;
				flag=true;
			}
		}
		if(!flag) cout << -1 ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
