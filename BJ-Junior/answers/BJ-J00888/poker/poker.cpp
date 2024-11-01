#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
char c1[4]={'D','C','H','S'},c2[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    int ans=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            string temp="";
            temp+=c1[i];
            temp+=c2[j];
            if(m[temp]!=0) ans++;
        }
    }
    ans=52-ans;
    cout<<ans<<endl;
    return 0;
}
