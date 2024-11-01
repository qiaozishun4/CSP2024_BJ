#include<bits/stdc++.h>
using namespace std;
int n;
bool a[10][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char q1,q2;
        cin>>q1>>q2;
        if(q1=='D')
        {
            if(q2=='A') a[1][1]=1;
            else if(q2=='T') a[1][10]=1;
            else if(q2=='J') a[1][11]=1;
            else if(q2=='Q') a[1][12]=1;
            else if(q2=='K') a[1][13]=1;
            else a[1][q2-'0']=1;
        }
        else if(q1=='C')
        {
            if(q2=='A') a[2][1]=1;
            else if(q2=='T') a[2][10]=1;
            else if(q2=='J') a[2][11]=1;
            else if(q2=='Q') a[2][12]=1;
            else if(q2=='K') a[2][13]=1;
            else a[2][q2-'0']=1;
        }
        else if(q1=='H')
        {
            if(q2=='A') a[3][1]=1;
            else if(q2=='T') a[3][10]=1;
            else if(q2=='J') a[3][11]=1;
            else if(q2=='Q') a[3][12]=1;
            else if(q2=='K') a[3][13]=1;
            else a[3][q2-'0']=1;
        }
        else if(q1=='S')
        {
            if(q2=='A') a[4][1]=1;
            else if(q2=='T') a[4][10]=1;
            else if(q2=='J') a[4][11]=1;
            else if(q2=='Q') a[4][12]=1;
            else if(q2=='K') a[4][13]=1;
            else a[4][q2-'0']=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==1)
            {
                continue;
            }
            else cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
