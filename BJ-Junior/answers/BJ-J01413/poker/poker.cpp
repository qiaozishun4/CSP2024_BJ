#include<bits/stdc++.h>
using namespace std;
bool arry[100];
int n,tot=52;
string s;
void save(int a)
{
    if(s[1]=='A')
        arry[13*a]=1;
    else if(s[1]=='T')
        arry[13*a+9]=1;
    else if(s[1]=='J')
        arry[13*a+10]=1;
    else if(s[1]=='Q')
        arry[13*a+11]=1;
    else if(s[1]=='K')
        arry[13*a+12]=1;
        for(int i=2;i<=9;i++)
        {
            if(s[1]-'0'==i)
            arry[13*a+i-1]=1;
        }
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(arry,0,sizeof(arry));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='S')
        {
            save(0);
        }
        else if(s[0]=='H')
        {
            save(1);
        }
        else if(s[0]=='D')
        {
            save(2);
        }
        else
        {
            save(3);
        }
    }
    tot=0;
    for(int j=0;j<=51;j++)
    {
           tot+=!arry[j];
    }
    cout<<tot;
    return 0;
}