#include <bits/stdc++.h>
using namespace std;
int sum;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char a[60][2];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int q=0;
        cin>>a[i][0]>>a[i][1];
        for(int j=1;j<=sum;j++)
        {
            if(a[j][0]==a[i][0]&&a[j][1]==a[i][1])
            {
                q=1;
                break;
            }
        }
        if(q==0) sum++;
    }
    int ans=52-sum;
    cout<<ans;
    return 0;
}
