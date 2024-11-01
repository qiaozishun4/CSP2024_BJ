#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
struct abc
{
    int a,b,c,d;
}a[70];
char b[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
        {
            for(int j=0;j<13;j++)
            {
                if(s[1]==b[j])
                {
                    a[j+1].a++;
                }
            }
        }
        if(s[0]=='C')
        {
            for(int j=0;j<13;j++)
            {
                if(s[1]==b[j])
                {
                    a[j+1].b++;
                }
            }
        }
        if(s[0]=='H')
        {
            for(int j=0;j<13;j++)
            {
                if(s[1]==b[j])
                {
                    a[j+1].c++;
                }
            }
        }
        if(s[0]=='S')
        {
            for(int j=0;j<13;j++)
            {
                if(s[1]==b[j])
                {
                    a[j+1].d++;
                }
            }
        }
    }
    for(int i=1;i<=13;i++)
    {
        if(a[i].a==-0)
        {
            ans++;
        }
        if(a[i].b==0)
        {
            ans++;
        }
        if(a[i].c==0)
        {
            ans++;
        }
        if(a[i].d==0)
        {
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
