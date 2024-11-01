#include <bits/stdc++.h>
using namespace std;

string p[57],x;
int n,a,f;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        f=0;
        for(int i=1;i<=a;i++)
        {
            if(p[i]==x)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            a++;
            p[a]=x;
        }
    }
    cout<<52-a;
    return 0;
}