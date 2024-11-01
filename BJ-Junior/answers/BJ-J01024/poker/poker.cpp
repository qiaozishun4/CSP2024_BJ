#include<bits/stdc++.h>
using namespace std;
int d[105],c[105],h[105],s[105];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //D方片,C草花,H红桃,S黑桃
	int n,i,cnt=0;
	string S;
	cin>>n;
	for(i=1;i<=n;i++)
    {
        cin>>S;
        char C=S[0];
        int w=S[1]-'0';
        if(S[1]=='A')
            w=1;
        if(S[1]=='T')
            w=10;
        if(S[1]=='J')
            w=11;
        if(S[1]=='Q')
            w=12;
        if(S[1]=='K')
            w=13;
        //cout<<w<<endl;
        if(C=='D')
            d[w]++;
        if(C=='C')
            c[w]++;
        if(C=='H')
            h[w]++;
        if(C=='S')
            s[w]++;
    }
    for(i=1;i<=13;i++)
    {
        //cout<<d[i]<<" "<<c[i]<<" "<<h[i]<<" "<<s[i]<<endl;
        cnt+=(d[i]==0)+(c[i]==0)+(h[i]==0)+(s[i]==0);
    }
    cout<<cnt<<endl;
	return 0;
}
