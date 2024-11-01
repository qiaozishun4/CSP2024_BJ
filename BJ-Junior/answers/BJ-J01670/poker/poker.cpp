#include<bits/stdc++.h>
using namespace std;
int ai[52];
char s[4]={'S','H','D','C'};
char n[13]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a,c=0;
    char x;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        c=0;
        cin>>x;
        for(int j=0;j<4;j++)
        {
            if(x==s[j])
            {
                c+=j*13;
                break;
            }
        }
        cin>>x;
        for(int j=0;j<13;j++)
        {
            if(x==n[j])
            {
                c+=j;
                break;
            }
        }
        ai[c]++;
    }
    c=0;
    for(int i=0;i<52;i++)
    {
        if(ai[i]==0)c++;
    }
    cout<<c;
    return 0;
}
