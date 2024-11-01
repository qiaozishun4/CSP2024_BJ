#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int n;
int box[5][14];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char op,x;
        cin>>op>>x;
        if(op=='D')
        {
            if('2'<=x && x<='9')
            {
                box[1][x-'0']=1;
            }
            if(x=='A')box[1][1]=1;
            if(x=='T')box[1][10]=1;
            if(x=='J')box[1][11]=1;
            if(x=='Q')box[1][12]=1;
            if(x=='K')box[1][13]=1;
        }
        if(op=='C')
        {
            if('2'<=x && x<='9')
            {
                box[2][x-'0']=1;
            }
            if(x=='A')box[2][1]=1;
            if(x=='T')box[2][10]=1;
            if(x=='J')box[2][11]=1;
            if(x=='Q')box[2][12]=1;
            if(x=='K')box[2][13]=1;
        }
        if(op=='H')
        {
            if('2'<=x && x<='9')
            {
                box[3][x-'0']=1;
            }
            if(x=='A')box[3][1]=1;
            if(x=='T')box[3][10]=1;
            if(x=='J')box[3][11]=1;
            if(x=='Q')box[3][12]=1;
            if(x=='K')box[3][13]=1;
        }
        if(op=='S')
        {
            if('2'<=x && x<='9')
            {
                box[4][x-'0']=1;
            }
            if(x=='A')box[4][1]=1;
            if(x=='T')box[4][10]=1;
            if(x=='J')box[4][11]=1;
            if(x=='Q')box[4][12]=1;
            if(x=='K')box[4][13]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(box[i][j]==0)ans++;
        }
    }
    cout<<ans;

    return 0;
}
