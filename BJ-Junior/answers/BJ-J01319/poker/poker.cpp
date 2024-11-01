#include<bits/stdc++.h>
using namespace std;
map<string,bool> p;
int n;
string s1 = "DCHS",s2 = "A23456789TJQK";
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin>>s;
        p[s] = true;
    }
    int ans = 0;
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 13;j++)
        {
            char s[2];
            s[0] = s1[i];
            s[1] = s2[j];
            if(!p[s])
                ans++;
        }
    }
    cout<<ans;
}
