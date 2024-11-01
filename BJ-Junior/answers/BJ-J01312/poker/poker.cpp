#include <bits/stdc++.h>
using namespace std;
int n;
string p[52];
int ans=52;


int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=52;j++)
        {
            if(p[j]!=s&&j==52)
            {
                p[j]=s;
                ans--;
            }
            if(p[j]==s)break;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}