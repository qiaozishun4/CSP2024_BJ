#include<iostream>
#include<cstring>
using namespace std;
string s;
int a[210];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='S')
        {
            a[s[1]-'0']++;
        }
        else if(s[0]=='H')
        {
            a[51+s[1]-'0']++;
        }
        else if(s[0]=='C')
        {
            a[102+s[1]-'0']++;
        }
        else
        {
            a[153+s[1]-'0']++;
        }
    }
    int cnt=0;
    for(int i=1;i<=205;i++)
    {
        if(a[i]>=1)
        {
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}
