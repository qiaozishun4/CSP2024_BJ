#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
int a[256][256];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    ans-=n;
    for(int i=1;i<=n;i++)
    {
        char x,y;
        cin>>x>>y;
        a[x][y]++;
        if(a[x][y]>1)
        {
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
