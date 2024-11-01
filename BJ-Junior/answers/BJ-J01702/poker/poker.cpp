#include <bits/stdc++.h>
using namespace std;
int search1 [130],search2 [130];
bool poker [5] [14];
void init()
{
    search1['D']=1;
    search1['C']=2;
    search1['H']=3;
    search1['S']=4;
    search2['A']=1;
    search2['2']=2;
    search2['3']=3;
    search2['4']=4;
    search2['5']=5;
    search2['6']=6;
    search2['7']=7;
    search2['8']=8;
    search2['9']=9;
    search2['T']=10;
    search2['J']=11;
    search2['Q']=12;
    search2['K']=13;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    int n;
    cin >>n;
    for (int i = 1;i<=n;i++)
    {
        char p1,p2;
        cin >>p1 >>p2;
        poker[search1[p1]][search2[p2]]=1;
    }
    int ans = 0;
    for (int i = 1;i<=4;i++)
    {
        for (int j = 1;j<=13;j++)
        {
            if (!poker[i] [j])  ans++;
        }
    }
    cout <<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
