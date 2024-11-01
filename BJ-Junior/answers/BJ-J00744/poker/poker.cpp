#include <iostream>
#include <cstdio>
using namespace std;
int box[5][15],n,cnt;
string t;
int to_int1(char x)
{
    if (x=='D')return 1;
    if (x=='C')return 2;
    if (x=='H')return 3;
    if (x=='S')return 4;
}
int to_int2(char x)
{
    if (x=='A')return 1;
    if (x=='T')return 10;
    if (x=='J')return 11;
    if (x=='Q')return 12;
    if (x=='K')return 13;
    return x-48;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        box[to_int1(t[0])][to_int2(t[1])]=1;
    }
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=13;j++)
        {
            if (box[i][j]!=1)
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
