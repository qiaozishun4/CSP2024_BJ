#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long i,g,s,b,q,n;
	for(i=1;i<=1000;i++)
	{
		g=i%10,s=i/10%10,b=i/100%10,q=i/1000%10;
		if(s!=0 && g==0) a[i]+=6;
		if(g==1) a[i]+=2;
		if(g==2) a[i]+=5;
		if(g==3) a[i]+=5;
		if(g==4) a[i]+=4;
		if(g==5) a[i]+=5;
		if(g==6) a[i]+=6;
		if(g==7) a[i]+=3;
		if(g==8) a[i]+=7;
		if(g==9) a[i]+=6;
		if(s==0 && b!=0) a[i]+=6;
		if(s==1) a[i]+=2;
		if(s==2) a[i]+=5;
		if(s==3) a[i]+=5;
		if(s==4) a[i]+=4;
		if(s==5) a[i]+=5;
		if(s==6) a[i]+=6;
		if(s==7) a[i]+=3;
		if(s==8) a[i]+=7;
		if(s==9) a[i]+=6;
		if(b==0 && q!=0) a[i]+=6;
		if(b==1) a[i]+=2;
		if(b==2) a[i]+=5;
		if(b==3) a[i]+=5;
		if(b==4) a[i]+=4;
		if(b==5) a[i]+=5;
		if(b==6) a[i]+=6;
		if(b==7) a[i]+=3;
		if(b==8) a[i]+=7;
		if(b==9) a[i]+=6;
		if(q==1) a[i]+=2;
		if(q==2) a[i]+=5;
		if(q==3) a[i]+=5;
		if(q==4) a[i]+=4;
		if(q==5) a[i]+=5;
		if(q==6) a[i]+=6;
		if(q==7) a[i]+=3;
		if(q==8) a[i]+=7;
		if(q==9) a[i]+=6;
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		int x;
		bool f=0;
		cin>>x;
		for(int j=1;j<=1000;j++)
		{
			if(a[j]==x)
			{
				cout<<j<<endl;
				f=1;
				break;
			}
		}
		if(f==0) cout<<-1<<endl;
	}
	return 0;
}
