#include <bits/stdc++.h>
using namespace std;
int pk[5][14];
int init1(char a)
{
    if(a=='D')
    {
        return 1;
    }
    else if(a=='C')
    {
        return 2;
    }
    else if(a=='H')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
int init2(char a)
{
    if(a<='9'&&a>='2')
    {
        return a-'0';
    }
    else if(a=='A')
    {
        return 1;
    }
    else if(a=='T')
    {
        return 10;
    }
    else if(a=='J')
    {
        return 11;
    }
    else if(a=='Q')
    {
        return 12;
    }
    else
    {
        return 13;
    }
}
void poker(char a,char b)
{
    int x=init1(a),y=init2(b);
    pk[x][y]=1;
}
int cnt()
{
    int sum=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(pk[i][j]==0)
            {
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char u,v;
        cin>>u>>v;
        poker(u,v);
    }
    cout<<cnt();
    fcloce(stdin);
    fcloce(stdout);
    return 0;
}
