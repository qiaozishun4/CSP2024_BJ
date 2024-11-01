#include <bits/stdc++.h>
using namespace std;
int flag[10][100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        string x;
        cin >> x;
        if (x[0]=='D')
        {
            if (x[1]=='A')  flag[1][1]=1;
            if (x[1]>='1' && x[1]<='9')  flag[1][x[1]-'0']=1;
            if (x[1]=='T')  flag[1][10]=1;
            if (x[1]=='J')  flag[1][11]=1;
            if (x[1]=='Q')  flag[1][12]=1;
            if (x[1]=='K')  flag[1][13]=1;
        }
        if (x[0]=='C')
        {
            if (x[1]=='A')  flag[2][1]=1;
            if (x[1]>='1' && x[1]<='9')  flag[2][x[1]-'0']=1;
            if (x[1]=='T')  flag[2][10]=1;
            if (x[1]=='J')  flag[2][11]=1;
            if (x[1]=='Q')  flag[2][12]=1;
            if (x[1]=='K')  flag[2][13]=1;
        }
        if (x[0]=='H')
        {
            if (x[1]=='A')  flag[3][1]=1;
            if (x[1]>='1' && x[1]<='9')  flag[3][x[1]-'0']=1;
            if (x[1]=='T')  flag[3][10]=1;
            if (x[1]=='J')  flag[3][11]=1;
            if (x[1]=='Q')  flag[3][12]=1;
            if (x[1]=='K')  flag[3][13]=1;
        }
        if (x[0]=='S')
        {
            if (x[1]=='A')  flag[4][1]=1;
            if (x[1]>='1' && x[1]<='9')  flag[4][x[1]-'0']=1;
            if (x[1]=='T')  flag[4][10]=1;
            if (x[1]=='J')  flag[4][11]=1;
            if (x[1]=='Q')  flag[4][12]=1;
            if (x[1]=='K')  flag[4][13]=1;
        }
    }
    int num=0;
    for (int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if (flag[i][j]==0)  num++;
        }
    }
    cout << num;
    return 0;
}
