#include<bits/stdc++.h>
using namespace std;
int n;
int b[100010];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	if(n<=1)
	{
        cout<<-1<<endl;
	}
    b[2]=1;
	b[3]=7;
	b[4]=4;
	b[5]=3;
	b[6]=6;
	b[7]=3;
	b[8]=10;
	b[9]=18;
	b[10]=22;
	b[11]=20;
	b[12]=28;
	b[13]=68;
	b[14]=88;
	if(n>=2&&n<=14)
    {
        cout<<b[n]<<endl;
	}
	else
	{
        for(int i=15;i<=n;i++)
        {
            b[i]=b[i-7]*10+8;
            cout<<b[i]<<endl;

        }
	}

	return 0;
}
