#include <bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		if (n<2) cout<<-1;
		else if (n<=7)
		{
			if (n==2) cout<<1;
			else if (n==3) cout<<7;
			else if (n==4) cout<<4;
			else if (n==5) cout<<2;
			else if (n==6) cout<<6;
			else if (n==7) cout<<8;
		}
		else if (n==10) cout<<22;
		else if (n>7)
		{
			int p=n/7;
			if (n%7==0) while(p--) cout<<8;
			else if (n%7!=0){
				int d=(p+1)*7-n;
				if (d>=5){
					d-=5;
					cout<<1;
				}
				else if (d>=2){
					d-=2;
					cout<<2;
				}
				else if (d>=1){
					d-=1;
					cout<<6;
				}
				while (p--){
					if (d>0){
						cout<<0;
						d--;
					}
					else cout<<8;
				}
			}
		}
		if (T) cout<<endl;
	}
	return 0;
}

