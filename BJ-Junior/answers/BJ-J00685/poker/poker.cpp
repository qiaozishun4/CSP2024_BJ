#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],ans=0;
char x,y;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x=='D')
        {
            if(y=='A') a[1][1]++;
            else if(y=='T') a[1][10]++;
            else if(y=='J') a[1][11]++;
            else if(y=='Q') a[1][12]++;
            else if(y=='K') a[1][13]++;
            else if(y=='2') a[1][2]++;
            else if(y=='3') a[1][3]++;
            else if(y=='4') a[1][4]++;
            else if(y=='5') a[1][5]++;
            else if(y=='6') a[1][6]++;
            else if(y=='7') a[1][7]++;
            else if(y=='8') a[1][8]++;
            else if(y=='9') a[1][9]++;
        }
        if(x=='C')
        {
            if(y=='A') a[2][1]++;
            else if(y=='T') a[2][10]++;
            else if(y=='J') a[2][11]++;
            else if(y=='Q') a[2][12]++;
            else if(y=='K') a[2][13]++;
            else if(y=='2') a[2][2]++;
            else if(y=='3') a[2][3]++;
            else if(y=='4') a[2][4]++;
            else if(y=='5') a[2][5]++;
            else if(y=='6') a[2][6]++;
            else if(y=='7') a[2][7]++;
            else if(y=='8') a[2][8]++;
            else if(y=='9') a[2][9]++;
        }
        if(x=='H')
        {
            if(y=='A') a[3][1]++;
            else if(y=='T') a[3][10]++;
            else if(y=='J') a[3][11]++;
            else if(y=='Q') a[3][12]++;
            else if(y=='K') a[3][13]++;
            else if(y=='2') a[3][2]++;
            else if(y=='3') a[3][3]++;
            else if(y=='4') a[3][4]++;
            else if(y=='5') a[3][5]++;
            else if(y=='6') a[3][6]++;
            else if(y=='7') a[3][7]++;
            else if(y=='8') a[3][8]++;
            else if(y=='9') a[3][9]++;
        }
        if(x=='S')
        {
            if(y=='A') a[4][1]++;
            else if(y=='T') a[4][10]++;
            else if(y=='J') a[4][11]++;
            else if(y=='Q') a[4][12]++;
            else if(y=='K') a[4][13]++;
            else if(y=='2') a[4][2]++;
            else if(y=='3') a[4][3]++;
            else if(y=='4') a[4][4]++;
            else if(y=='5') a[4][5]++;
            else if(y=='6') a[4][6]++;
            else if(y=='7') a[4][7]++;
            else if(y=='8') a[4][8]++;
            else if(y=='9') a[4][9]++;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
