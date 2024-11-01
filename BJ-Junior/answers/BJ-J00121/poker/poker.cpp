#include<cstdio>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
bool pok[5][14];
string s;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(pok,false,sizeof(pok));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[1]>='2'&&s[1]<='9')
        {
            if(s[0]=='D')
            {
                pok[1][s[1]-'0']=true;
            }
            if(s[0]=='C')
            {
                pok[2][s[1]-'0']=true;
            }
            if(s[0]=='H')
            {
                pok[3][s[1]-'0']=true;
            }
            if(s[0]=='S')
            {
                pok[4][s[1]-'0']=true;
            }
        }
        else if(s[1]=='A')
        {
            if(s[0]=='D')
            {
                pok[1][1]=true;
            }
            if(s[0]=='C')
            {
                pok[2][1]=true;
            }
            if(s[0]=='H')
            {
                pok[3][1]=true;
            }
            if(s[0]=='S')
            {
                pok[4][1]=true;
            }
        }
        else if(s[1]=='T')
        {
            if(s[0]=='D')
            {
                pok[1][10]=true;
            }
            if(s[0]=='C')
            {
                pok[2][10]=true;
            }
            if(s[0]=='H')
            {
                pok[3][10]=true;
            }
            if(s[0]=='S')
            {
                pok[4][10]=true;
            }
        }
        else if(s[1]=='J')
        {
            if(s[0]=='D')
            {
                pok[1][11]=true;
            }
            if(s[0]=='C')
            {
                pok[2][11]=true;
            }
            if(s[0]=='H')
            {
                pok[3][11]=true;
            }
            if(s[0]=='S')
            {
                pok[4][11]=true;
            }
        }
        else if(s[1]=='Q')
        {
            if(s[0]=='D')
            {
                pok[1][12]=true;
            }
            if(s[0]=='C')
            {
                pok[2][12]=true;
            }
            if(s[0]=='H')
            {
                pok[3][12]=true;
            }
            if(s[0]=='S')
            {
                pok[4][12]=true;
            }
        }
        else if(s[1]=='K')
        {
            if(s[0]=='D')
            {
                pok[1][13]=true;
            }
            if(s[0]=='C')
            {
                pok[2][13]=true;
            }
            if(s[0]=='H')
            {
                pok[3][13]=true;
            }
            if(s[0]=='S')
            {
                pok[4][13]=true;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(pok[i][j]==false)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
