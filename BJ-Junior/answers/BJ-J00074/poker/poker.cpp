#include<bits/stdc++.h>
using namespace std;
char s[100050],s1[100050];
long long n,ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>s1[i];
    }
    ans=52-n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(s[i]==s[j]&&s1[i]==s1[j]&&s[i]!='0'&&s1[i]!='0')
            {
                ans++;
                s[j]='0';
                s1[j]='0';
            }
        }
    }
    cout<<ans;
   return 0;
}
