#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    bool Poker[4][13];
    int n=0,sum=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            Poker[i][j]=false;
        }
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        //cout<<tmp[0]<<' '<<tmp[1];
        if(tmp[0]=='S')
        {
            if(tmp[1]>='2'&&tmp[1]<='9')
            {
                Poker[0][tmp[1]-'1']=true;
            }
            if(tmp[1]=='A')
            {
                Poker[0][0]=true;
            }
            if(tmp[1]=='T')
            {
                Poker[0][9]=true;
            }
            if(tmp[1]=='J')
            {
                Poker[0][10]=true;
            }
            if(tmp[1]=='Q')
            {
                Poker[0][11]=true;
            }
            if(tmp[1]=='K')
            {
                Poker[0][12]=true;
            }
        }
        if(tmp[0]=='H')
        {
            if(tmp[1]>='2'&&tmp[1]<='9')
            {
                Poker[1][tmp[1]-'1']=true;
            }
            if(tmp[1]=='A')
            {
                Poker[1][0]=true;
            }
            if(tmp[1]=='T')
            {
                Poker[1][9]=true;
            }
            if(tmp[1]=='J')
            {
                Poker[1][10]=true;
            }
            if(tmp[1]=='Q')
            {
                Poker[1][11]=true;
            }
            if(tmp[1]=='K')
            {
                Poker[1][12]=true;
            }
        }
        if(tmp[0]=='C')
        {
            if(tmp[1]>='2'&&tmp[1]<='9')
            {
                Poker[2][tmp[1]-'1']=true;
            }
            if(tmp[1]=='A')
            {
                Poker[2][0]=true;
            }
            if(tmp[1]=='T')
            {
                Poker[2][9]=true;
            }
            if(tmp[1]=='J')
            {
                Poker[2][10]=true;
            }
            if(tmp[1]=='Q')
            {
                Poker[2][11]=true;
            }
            if(tmp[1]=='K')
            {
                Poker[2][12]=true;
            }
        }
        if(tmp[0]=='D')
        {
            if(tmp[1]>='2'&&tmp[1]<='9')
            {
                Poker[3][tmp[1]-'1']=true;
            }
            if(tmp[1]=='A')
            {
                Poker[3][0]=true;
            }
            if(tmp[1]=='T')
            {
                Poker[3][9]=true;
            }
            if(tmp[1]=='J')
            {
                Poker[3][10]=true;
            }
            if(tmp[1]=='Q')
            {
                Poker[3][11]=true;
            }
            if(tmp[1]=='K')
            {
                Poker[3][12]=true;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<=12;j++)
        {
            if(Poker[i][j]==false)
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
