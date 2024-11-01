#include<bits/stdc++.h>
using namespace std;
int f(char ch)
{
	if(ch=='A') return 1;
	if(ch=='T') return 10;
	if(ch=='J') return 11;
	if(ch=='Q') return 12;
	if(ch=='K') return 13;
	return (int)(ch-'0');
}
int d[20],c[20],h[20],s[20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(c));
	memset(h,0,sizeof(h));
	memset(s,0,sizeof(s));
    int n,cnt=0;
    cin>>n;
    char x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
		    if(x=='D'&&d[f(y)]==0) d[f(y)]=1,cnt++;
        if(x=='C'&&c[f(y)]==0) c[f(y)]=1,cnt++;
        if(x=='H'&&h[f(y)]==0) h[f(y)]=1,cnt++;
        if(x=='S'&&s[f(y)]==0) s[f(y)]=1,cnt++;
    }
	cout<<52-cnt;
	return 0;
}
