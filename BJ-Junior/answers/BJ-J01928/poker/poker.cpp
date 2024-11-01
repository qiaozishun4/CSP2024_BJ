#include<iostream>
using namespace std;
int m[10][20];
int main(int argc, char**argv)
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	int n;
	char a,b;
	int ans=0;
	cin>>n;
	for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            m[i][j]=0;
        }
    }
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(b=='2'||b=='3'||b=='4'||b=='5'||b=='6'||b=='7'||b=='8'||b=='9')
		{
			if(a=='D')
				m[1][int(b)-48]=1;
			if(a=='C')
				m[2][int(b)-48]=1;
			if(a=='H')
				m[3][int(b)-48]=1;
			if(a=='S')
				m[4][int(b)-48]=1;
		}
		else
		{
			if(b=='A')
			{
				if(a=='D')
					m[1][1]=1;
				if(a=='C')
					m[2][1]=1;
				if(a=='H')
					m[3][1]=1;
				if(a=='S')
					m[4][1]=1;
			}
			if(b=='T')
			{
				if(a=='D')
					m[1][10]=1;
				if(a=='C')
					m[2][10]=1;
				if(a=='H')
					m[3][10]=1;
				if(a=='S')
					m[4][10]=1;
			}
			if(b=='J')
			{
				if(a=='D')
					m[1][11]=1;
				if(a=='C')
					m[2][11]=1;
				if(a=='H')
					m[3][11]=1;
				if(a=='S')
					m[4][11]=1;
			}
			if(b=='Q')
			{
				if(a=='D')
					m[1][12]=1;
				if(a=='C')
					m[2][12]=1;
				if(a=='H')
					m[3][12]=1;
				if(a=='S')
					m[4][12]=1;
			}
			if(b=='K')
			{
				if(a=='D')
					m[1][13]=1;
				if(a=='C')
					m[2][13]=1;
				if(a=='H')
					m[3][13]=1;
				if(a=='S')
					m[4][13]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(m[i][j]==0)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
