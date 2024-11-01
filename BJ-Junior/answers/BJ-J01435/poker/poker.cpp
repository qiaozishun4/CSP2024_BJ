#include<bits/stdc++.h>
using namespace std;
char a[55][2];
bool b[55];
int n,ans=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        cin>>a[i][1];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i][0]=='D')
        {
            if(a[i][1]>='2'&&a[i][1]<='9')
                b[a[i][1]-'0']=true;
            if(a[i][1]=='A')
                b[1]=true;
            if(a[i][1]=='T')
                b[10]=true;
            if(a[i][1]=='J')
                b[11]=true;
            if(a[i][1]=='Q')
                b[12]=true;
            if(a[i][1]=='K')
                b[13]=true;
        }
        if(a[i][0]=='C')
        {
            if(a[i][1]>='2'&&a[i][1]<='9')
                b[13+(a[i][1]-'0')]=true;
            if(a[i][1]=='A')
                b[14]=true;
            if(a[i][1]=='T')
                b[23]=true;
            if(a[i][1]=='J')
                b[24]=true;
            if(a[i][1]=='Q')
                b[25]=true;
            if(a[i][1]=='K')
                b[26]=true;
        }
        if(a[i][0]=='S')
        {
            if(a[i][1]>='2'&&a[i][1]<='9')
                b[26+(a[i][1]-'0')]=true;
            if(a[i][1]=='A')
                b[27]=true;
            if(a[i][1]=='T')
                b[36]=true;
            if(a[i][1]=='J')
                b[37]=true;
            if(a[i][1]=='Q')
                b[38]=true;
            if(a[i][1]=='K')
                b[39]=true;
        }
        if(a[i][0]=='H')
        {
            if(a[i][1]>='2'&&a[i][1]<='9')
                b[39+(a[i][1]-'0')]=true;
            if(a[i][1]=='A')
                b[40]=true;
            if(a[i][1]=='T')
                b[49]=true;
            if(a[i][1]=='J')
                b[50]=true;
            if(a[i][1]=='Q')
                b[51]=true;
            if(a[i][1]=='K')
                b[52]=true;
        }
    }
    for(int i=1;i<=52;i++)
    {
        if(b[i])
        {
            --ans;
        }
    }
    cout<<ans;
}