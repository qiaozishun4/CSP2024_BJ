#include<bits/stdc++.h>
using namespace std;
char pai[106],_hua[53];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int ans[5][14]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>_hua[i]>>pai[i];
        if(_hua[i]=='D')
        {
            if(pai[i]=='A')
            {
                ans[1][1]++;
            }
            else if(pai[i]=='T')
            {
                 ans[1][10]++;
            }
            else if(pai[i]=='J')
            {
                 ans[1][11]++;
            }
            else if(pai[i]=='Q')
            {
                 ans[1][12]++;
            }
            else if(pai[i]=='K')
            {
                 ans[1][13]++;
            }
            else if(pai[i]=='2')
            {
                ans[1][2]++;
            }
            else if(pai[i]=='3')
            {
                ans[1][3]++;
            }
            else if(pai[i]=='4')
            {
                ans[1][4]++;
            }
            else if(pai[i]=='5')
            {
                ans[1][5]++;
            }
            else if(pai[i]=='6')
            {
                ans[1][6]++;
            }
            else if(pai[i]=='7')
            {
                ans[1][7]++;
            }
            else if(pai[i]=='8')
            {
                ans[1][8]++;
            }
            else if(pai[i]=='9')
            {
                ans[1][9]++;
            }
        }
        if(_hua[i]=='C')
        {
            if(pai[i]=='A')
            {
                ans[2][1]++;
            }
            else if(pai[i]=='T')
            {
                 ans[2][10]++;
            }
            else if(pai[i]=='J')
            {
                 ans[2][11]++;
            }
            else if(pai[i]=='Q')
            {
                 ans[2][12]++;
            }
            else if(pai[i]=='K')
            {
                 ans[2][13]++;
            }
            else if(pai[i]=='2')
            {
                ans[2][2]++;
            }
            else if(pai[i]=='3')
            {
                ans[2][3]++;
            }
            else if(pai[i]=='4')
            {
                ans[2][4]++;
            }
            else if(pai[i]=='5')
            {
                ans[2][5]++;
            }
            else if(pai[i]=='6')
            {
                ans[2][6]++;
            }
            else if(pai[i]=='7')
            {
                ans[2][7]++;
            }
            else if(pai[i]=='8')
            {
                ans[2][8]++;
            }
            else if(pai[i]=='9')
            {
                ans[2][9]++;
            }
        }
        if(_hua[i]=='H')
        {
            if(pai[i]=='A')
            {
                ans[3][1]++;
            }
            else if(pai[i]=='T')
            {
                 ans[3][10]++;
            }
            else if(pai[i]=='J')
            {
                 ans[3][11]++;
            }
            else if(pai[i]=='Q')
            {
                 ans[3][12]++;
            }
            else if(pai[i]=='K')
            {
                 ans[3][13]++;
            }
            else if(pai[i]=='2')
            {
                ans[3][2]++;
            }
            else if(pai[i]=='3')
            {
                ans[3][3]++;
            }
            else if(pai[i]=='4')
            {
                ans[3][4]++;
            }
            else if(pai[i]=='5')
            {
                ans[3][5]++;
            }
            else if(pai[i]=='6')
            {
                ans[3][6]++;
            }
            else if(pai[i]=='7')
            {
                ans[3][7]++;
            }
            else if(pai[i]=='8')
            {
                ans[3][8]++;
            }
            else if(pai[i]=='9')
            {
                ans[3][9]++;
            }
        }
        if(_hua[i]=='S')
        {
            if(pai[i]=='A')
            {
                ans[4][1]++;
            }
            else if(pai[i]=='T')
            {
                 ans[4][10]++;
            }
            else if(pai[i]=='J')
            {
                 ans[4][11]++;
            }
            else if(pai[i]=='Q')
            {
                 ans[4][12]++;
            }
            else if(pai[i]=='K')
            {
                 ans[4][13]++;
            }
            else if(pai[i]=='2')
            {
                 ans[4][2]++;
            }
            else if(pai[i]=='3')
            {
                 ans[4][3]++;
            }
            else if(pai[i]=='4')
            {
                 ans[4][4]++;
            }
            else if(pai[i]=='5')
            {
                 ans[4][5]++;
            }
            else if(pai[i]=='6')
            {
                 ans[4][6]++;
            }
            else if(pai[i]=='7')
            {
                ans[4][7]++;
            }
            else if(pai[i]=='8')
            {
                ans[4][8]++;
            }
            else if(pai[i]=='9')
            {
                 ans[4][9]++;
            }
        }
    }
    int _sum=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(ans[i][j]==0)
            {
                _sum++;
            }
        }
    }
    cout<<_sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
