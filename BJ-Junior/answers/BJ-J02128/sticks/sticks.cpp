#include <iostream>
using namespace std;
//const int l[10]={6,2,5,5,4,5,6,3,7,6};//0,1,2,4,7,8
//6,2,5,4,3,7				//0 0.5 0.4 1 2.3 1.1
string s;
int T,n;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
		cin>>T;
		while(T--)
		{
			cin>>n;
			if(n%7==0)
			{
				while(n!=0)
				{
					n=n/7;
					cout<<8;
				}
			}
			if(n%7==1)
			{
				int x=((n-1)/7)%7,y,z;
				if(x==1) y=4,z=4;
				if(x==2) y=2,z=5;
				if(x==3)
				{
					cout<<4;
					y=0,z=6;
				}
				while(n!=0)
				{
					n/=z;
					cout<<y;
				}
			cout<<endl;
		}
		}
		return 0;
}
