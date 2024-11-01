#include<iostream>
using namespace std;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int a[n+2];//bool p[n+2];
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1)cout<<0;
		else if(n==2){if(a[1]==a[2]) cout<<a[2];else cout<<0;}
		else if(n==3){if(a[1]!=a[2]&&a[2]!=a[3]) cout<<0;else if(a[1]==a[2]&&a[2]!=a[3]) cout<<a[1];else if(a[1]!=a[2]&&a[2]==a[3]) cout<<a[2];else if(a[1]==a[3]&&a[1]!=a[2])cout<<a[1];else if(a[1]==a[2]&&a[2]==a[3]) cout<<2*a[1];}
		else if(n==4){if(a[1]!=a[2]&&a[2]!=a[3]&&a[3]!=a[4]) cout<<0;else if(a[1]==a[2]&&a[2]!=a[3]&&a[3]!=a[4]) cout<<a[1];else if(a[1]!=a[2]&&a[2]==a[3]&&a[3]!=a[4]) cout<<a[2];else if(a[1]==a[3]&&a[2]!=a[3]&&a[3]!=a[4]) cout<<a[1];else if(a[1]==a[4]&&a[2]!=a[4]&&a[3]!=a[4]) cout<<a[1];else if(a[4]==a[2]&&a[2]!=a[3]&&a[3]!=a[4]) cout<<a[2];else if(a[4]!=a[2]&&a[2]!=a[3]&&a[3]==a[4]) cout<<a[3];else if(a[1]==a[2]&&a[2]==a[3]&&a[3]!=a[4]) cout<<a[1]*2;else if(a[1]==a[2]&&a[2]!=a[3]&&a[2]==a[4]) cout<<a[1]*2;else if(a[1]==a[3]&&a[2]!=a[3]&&a[3]==a[4]) cout<<a[1]*2;else if(a[1]!=a[2]&&a[2]==a[3]&&a[2]==a[4]) cout<<a[2]*2;else if(a[1]==a[2]&&a[2]==a[3]&&a[2]==a[4]) cout<<a[1]*3;}
	
		}return 0;
	}
	
