#include<bits/stdc++.h>
using namespace std;
int d[200],c[200],h[200],s[200],n,sum;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char a,b;
        int m;
        cin >> a >> b;
        m=(int)b;
        if(a=='D')
        {
            d[m]++;
        }
        else if(a=='C')
        {
            c[m]++;
        }
        else if(a=='H')
        {
            h[m]++;
        }
        else if(a=='S')
        {
            s[m]++;
        }
    }
    for(int i=1;i<=128;i++)
    {
        if(d[i]!=0)
        {
            sum++;
        }
        if(c[i]!=0)
        {
            sum++;
        }
        if(h[i]!=0)
        {
            sum++;
        }
        if(s[i]!=0)
        {
            sum++;
        }
    }
    if(sum>=52)
    {
        cout << 0;
    }
    else
    {
        cout << 52-sum;
    }
    return 0;
}
