
#include<cstdio>
#include<iostream>
using namespace std;
int n,sum=0;
char a[5];
bool b[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[0]=='D')
        {
            if(a[1]=='A')
            {
                b[1][1]=true;
            }
            else if(a[1]>='2'&&a[1]<='9')
            {
                b[1][a[1]-'0']=true;
            }
            else if(a[1]=='T')
            {
                b[1][10]=true;
            }
            else if(a[1]=='J')
            {
                b[1][11]=true;
            }
            else if(a[1]=='Q')
            {
                b[1][12]=true;
            }
            else if(a[1]=='K')
            {
                b[1][13]=true;
            }
        }
        else if(a[0]=='C')
        {
            if(a[1]=='A')
            {
                b[2][1]=true;
            }
            else if(a[1]>='2'&&a[1]<='9')
            {
                b[2][a[1]-'0']=true;
            }
            else if(a[1]=='T')
            {
                b[2][10]=true;
            }
            else if(a[1]=='J')
            {
                b[2][11]=true;
            }
            else if(a[1]=='Q')
            {
                b[2][12]=true;
            }
            else if(a[1]=='K')
            {
                b[2][13]=true;
            }
        }
        else if(a[0]=='H')
        {
            if(a[1]=='A')
            {
                b[3][1]=true;
            }
            else if(a[1]>='2'&&a[1]<='9')
            {
                b[3][a[1]-'0']=true;
            }
            else if(a[1]=='T')
            {
                b[3][10]=true;
            }
            else if(a[1]=='J')
            {
                b[3][11]=true;
            }
            else if(a[1]=='Q')
            {
                b[3][12]=true;
            }
            else if(a[1]=='K')
            {
                b[3][13]=true;
            }
        }
        else if(a[0]=='S')
        {
            if(a[1]=='A')
            {
                b[4][1]=true;
            }
            else if(a[1]>='2'&&a[1]<='9')
            {
                b[4][a[1]-'0']=true;
            }
            else if(a[1]=='T')
            {
                b[4][10]=true;
            }
            else if(a[1]=='J')
            {
                b[4][11]=true;
            }
            else if(a[1]=='Q')
            {
                b[4][12]=true;
            }
            else if(a[1]=='K')
            {
                b[4][13]=true;
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(b[i][j])
            {
                sum++;
            }
        }
    }
    cout<<52-sum;
    return 0;
}
