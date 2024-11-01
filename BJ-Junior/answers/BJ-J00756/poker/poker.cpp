#include<iostream>
using namespace std;
int to1(char c)
{
    if(c=='D')
    {
        return 1;
    }
    if(c=='C')
    {
        return 2;
    }
    if(c=='H')
    {
        return 3;
    }
    return 4;
}
int to2(char c)
{
    if(c=='A')
    {
        return 1;
    }
    if(c=='T')
    {
        return 10;
    }
    if(c=='J')
    {
        return 11;
    }
    if(c=='Q')
    {
        return 12;
    }
    if(c=='K')
    {
        return 13;
    }
    return c-'0';
}
bool vis[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char a,b;
    int cnt=52,A,B;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        A=to1(a);
        B=to2(b);
        if(!vis[A][B])
        {
            vis[A][B]=1;
            cnt--;
        }
    }
    cout<<cnt;
    return 0;
}