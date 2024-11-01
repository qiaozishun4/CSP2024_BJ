#include <bits/stdc++.h>
using namespace std;
int h[58],nn[15]={6,2,5,5,4,5,6,3,7,6};
void c(int p)
{
	int ch=10,w,ans=0;
	for(int i=1;;i++)
	{
		if(ch>p) 
		{
			w=i;
			break;
		}
		ch*=10;
	}
	ch=1;
	for(int i=1;i<=w;i++)
	{

		int s=((p/ch)%10);
		ch*=10;
		ans+=nn[s];
	}
	//cout<<ans<<endl;
	h[ans]=min(h[ans],p);
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=1;i<=30;i++) h[i]=0x3f3f3f3f;
    for(int i=1;i<=20000;i++) c(i);
    int T; cin>>T;
    while(T--)
    {
		int n; cin>>n;
		if(n==1) cout<<-1<<endl;
		else if(n<=30) cout<<h[n]<<endl;
		else if(n%7==0){
			for(int i=1;i<=(n/7);i++) cout<<8;
			cout<<endl;
		}
		else 
		{
			int w=n/7+1;
			int s=n-7*w+28;
			cout<<h[s];
			for(int i=1;i<w-3;i++) printf("%d",8);
			cout<<endl;
		}
	}
    return 0;
}
