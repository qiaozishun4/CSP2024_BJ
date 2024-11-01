#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
string s[100];
bool flag[100];
int n;
int tr(char c)
{
    if(c=='A')
    {
        return 1;
    }
    else if(c=='2')
    {
        return 2;
    }
    else if(c=='3')
    {
        return 3;
    }
    else if(c=='4')
    {
        return 4;
    }
    else if(c=='5')
    {
        return 5;
    }
    else if(c=='6')
    {
        return 6;
    }
    else if(c=='7')
    {
        return 7;
    }
    else if(c=='8')
    {
        return 8;
    }
    else if(c=='9')
    {
        return 9;
    }
    else if(c=='T')
    {
        return 10;
    }
    else if(c=='J')
    {
        return 11;
    }
    else if(c=='Q')
    {
        return 12;
    }
    else if(c=='K')
    {
        return 13;
    }
}
int findans()
{
    memset(flag,0,sizeof(flag));
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        int place;
        if(s[i][0]=='D')
        {
            place=tr(s[i][1]);
        }
        else if(s[i][0]=='C')
        {
            place=tr(s[i][1])+13;
        }
        else if(s[i][0]=='H')
        {
            place=tr(s[i][1])+26;
        }
        else
        {
            place=tr(s[i][1])+39;
        }


        if(flag[place]==0)
        {
            cnt++;
            flag[place]=1;
        }
    }
    return cnt;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
    }
    int ans=52-findans();
    cout<<ans;
    return 0;
}
