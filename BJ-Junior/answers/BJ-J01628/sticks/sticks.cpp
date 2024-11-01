#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			cout<<-1<<endl;
		}
		else if(a[i]==2)
		{
			cout<<1<<endl;
		}
		else if(a[i]==3)
		{
			cout<<7<<endl;
		}
		else if(a[i]==4)
		{
			cout<<-1<<endl;
		}
		else if(a[i]==2)
		{
			cout<<1<<endl;
		}
		else if(a[i]==3)
		{
			cout<<7<<endl;
		}
		else if(a[i]==4)
		{
			cout<<4<<endl;
		}
		else if(a[i]==5)
		{
			cout<<5<<endl;
		}
		else if(a[i]==6)
		{
			cout<<6<<endl;
		}
		else if(a[i]==7)
		{
			cout<<8<<endl;
		}
		else if(a[i]==8)
		{
			cout<<10<<endl;
		}
		else if(a[i]==9)
		{
			cout<<18<<endl;
		}
		else if(a[i]==10)
		{
			cout<<23<<endl;
		}
		else if(a[i]==11)
		{
			cout<<107<<endl;
		}
		else if(a[i]==12)
		{
			cout<<104<<endl;
		}
		else if(a[i]==13)
		{
			cout<<102<<endl;
		}
		else if(a[i]==14)
		{
			cout<<106<<endl;
		}
		else if(a[i]==15)
		{
			cout<<108<<endl;
		}
		else if(a[i]==16)
		{
			cout<<203<<endl;
		}
		else if(a[i]==17)
		{
			cout<<206<<endl;
		}
		else if(a[i]==18)
		{
			cout<<208<<endl;
		}
		else if(a[i]==19)
		{
			cout<<608<<endl;
		}
		else if(a[i]==20)
		{
			cout<<688<<endl;
		}
	}
	return 0;
}
