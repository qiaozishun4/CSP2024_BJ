#include<bits/stdc++.h>
using namespace std;
int d[20],c[20],h[20],s[20];
string x;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(x[0]=='D')
        {
            if(x[1]=='A')
                d[1]++;
            else if(x[1]>='2'&&x[1]<='9')
                d[x[1]-'0']++;
            else if(x[1]=='T')
                d[10]++;
            else if(x[1]=='J')
                d[11]++;
            else if(x[1]=='Q')
                d[12]++;
            else
                d[13]++;
        }
        else if(x[0]=='C')
        {
            if(x[1]=='A')
                c[1]++;
            else if(x[1]>='2'&&x[1]<='9')
                c[x[1]-'0']++;
            else if(x[1]=='T')
                c[10]++;
            else if(x[1]=='J')
                c[11]++;
            else if(x[1]=='Q')
                c[12]++;
            else
                c[13]++;
        }
        else if(x[0]=='H')
        {
            if(x[1]=='A')
                h[1]++;
            else if(x[1]>='2'&&x[1]<='9')
                h[x[1]-'0']++;
            else if(x[1]=='T')
                h[10]++;
            else if(x[1]=='J')
                h[11]++;
            else if(x[1]=='Q')
                h[12]++;
            else
                h[13]++;
        }
        else
        {
            if(x[1]=='A')
                s[1]++;
            else if(x[1]>='2'&&x[1]<='9')
                s[x[1]-'0']++;
            else if(x[1]=='T')
                s[10]++;
            else if(x[1]=='J')
                s[11]++;
            else if(x[1]=='Q')
                s[12]++;
            else
                s[13]++;
        }
    }
    int sum=0;
    for(int i=1;i<=13;++i)
    {
        if(d[i]==0)
            sum++;
        if(c[i]==0)
            sum++;
        if(h[i]==0)
            sum++;
        if(s[i]==0)
            sum++;
    }
    cout<<sum;
    return 0;
}
