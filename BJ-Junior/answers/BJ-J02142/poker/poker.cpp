#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,q=0;
    cin>>n;
    string a[53];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=n-i;i++)
        {
            if(a[i]==a[j])
            {
                q++;
            }
        }

    }
    int s=52-n+q;
    cout<<s;
    return 0;
}
