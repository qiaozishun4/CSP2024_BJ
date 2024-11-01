#include<bits/stdc++.h>
using namespace std;
int a[255][255];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        char x,y;
        cin>>x>>y;
        if(a[x][y]==0)
            ans++;
        a[x][y]++;
    }
    cout<<52-ans<<endl;
    return 0;
}
