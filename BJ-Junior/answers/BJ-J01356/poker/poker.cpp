#include <bits/stdc++.h>

using namespace std;

int n,h,s,ans,i,j;
bool a[5][14];
char c,d;
int main()
{
    ios::sync_with_stdio(false);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c>>d;
        if(c=='D')h=1;
        else if(c=='C')h=2;
        else if(c=='H')h=3;
        else h=4;
        if(d=='A')s=1;
        else if(d=='T')s=10;
        else if(d=='J')s=11;
        else if(d=='Q')s=12;
        else if(d=='K')s=13;
        else s=d-'0';
        a[h][s]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!a[i][j])ans++;
    cout<<ans<<endl;
    return 0;
}
