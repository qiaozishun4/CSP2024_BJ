#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[55]={},n,ans=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        char c,b;
        cin>>c>>b;
        if(c=='D')
        {
            if(b<='9')
            {
                a[b-'0']++;
            }
            else
            {
                if(b=='A')
                {
                    a[1]++;
                }
                if(b=='T')
                {
                    a[10]++;
                }
                if(b=='J')
                {
                    a[11]++;
                }
                if(b=='Q')
                {
                    a[12]++;
                }
                if(b=='K')
                {
                    a[13]++;
                }
            }
        }
        if(c=='C')
        {
            if(b<='9')
            {
                a[b-'0'+13]++;
            }
            else
            {
                if(b=='A')
                {
                    a[14]++;
                }
                if(b=='T')
                {
                    a[23]++;
                }
                if(b=='J')
                {
                    a[24]++;
                }
                if(b=='Q')
                {
                    a[25]++;
                }
                if(b=='K')
                {
                    a[26]++;
                }
            }
        }
        if(c=='H')
        {
            if(b<='9')
            {
                a[b-'0'+26]++;
            }
            else
            {
                if(b=='A')
                {
                    a[27]++;
                }
                if(b=='T')
                {
                    a[36]++;
                }
                if(b=='J')
                {
                    a[37]++;
                }
                if(b=='Q')
                {
                    a[38]++;
                }
                if(b=='K')
                {
                    a[39]++;
                }
            }
        }
        if(c=='S')
        {
            if(b<='9')
            {
                a[b-'0'+39]++;
            }
            else
            {
                if(b=='A')
                {
                    a[40]++;
                }
                if(b=='T')
                {
                    a[49]++;
                }
                if(b=='J')
                {
                    a[50]++;
                }
                if(b=='Q')
                {
                    a[51]++;
                }
                if(b=='K')
                {
                    a[52]++;
                }
            }
        }
    }
    for(int i=1; i<=52; i++)
    {
        if(a[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
