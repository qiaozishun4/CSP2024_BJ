#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int p=52;
    string a[n+1];
    if(n==0)
    {
        cout<<52;
    }
    else if(n==1)
    {
        cout<<51;
    }
    else{
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[i]!=a[j])
                {
                    p--;
                    a[j]='o';
                }
            }
        }
        cout<<p;
    }
    return 0;
}
