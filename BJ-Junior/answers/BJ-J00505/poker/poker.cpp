#include<bits/stdc++.h>
using namespace std;
int n,a[13][4],ans=52;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",strout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int b,c;
        if(s[0]=='D')
        {
            b=1;
        }
        else if(s[0]=='C')
        {
            b=2;
        }
        else if(s[0]=='H')
        {
            b=3;
        }
        else if(s[0]=='S')
        {
            b=4;
        }
        if(s[1]=='A')
        {
            c=1;
        }
        else if(s[1]=='2')
        {
            c=2;
        }
        else if(s[1]=='3')
        {
            c=3;
        }
        else if(s[1]=='4')
        {
            c=4;
        }
        else if(s[1]=='5')
        {
            c=5;
        }
        else if(s[1]=='6')
        {
            c=6;
        }
        else if(s[1]=='7')
        {
            c=7;
        }
        else if(s[1]=='8')
        {
            c=8;
        }
        else if(s[1]=='9')
        {
            c=9;
        }
        else if(s[1]=='T')
        {
            c=10;
        }
        else if(s[1]=='J')
        {
            c=11;
        }
        else if(s[1]=='Q')
        {
            c=12;
        }
        else if(s[1]=='K')
        {
            c=13;
        }
        if(a[c][b]==0)
        {
            ans--;
        }
        a[c][b]=1;
    }
    cout<<ans;
    return 0;
}
