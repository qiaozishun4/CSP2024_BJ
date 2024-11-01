#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,i,x,y,sum=0;
    cin>>n;
    char s[2];
    bool a[52];
    for(i=0;i<52;i++)
    {
        a[i]=false;
    }
    for(i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')x=0;
        else if(s[0]=='C')x=13;
        else if(s[0]=='H')x=26;
        else if(s[0]=='S')x=39;
        if(s[1]>='2'&&s[1]<='9')y=s[1]-'0';
        if(s[1]=='A')y=1;
        if(s[1]=='T')y=10;
        if(s[1]=='J')y=11;
        if(s[1]=='Q')y=12;
        if(s[1]=='K')y=13;
        a[x+y-1]=true;
    }
    for(i=0;i<52;i++){
        if(!a[i])sum++;
    }
    cout<<sum;
    return 0;
}