#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n,i,j,ans,sum=0;
    bool f;
    string a[53];

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];

        f=true;
        for(j=1;j<i;j++)
            if(a[i]==a[j])
        {
            f=false;
            break;
        }

        if(f==true) sum++;
    }

    ans=52-sum;

    cout <<ans;

    return 0;
}