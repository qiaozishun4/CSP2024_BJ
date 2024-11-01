#include <bits/stdc++.h>
using namespace std;
const int N=15;
int D[N],C[N],H[N],S[N];
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
        if(s[0]=='D')
        {
            if(s[1]=='A') D[1]++;
            else if(s[1]=='T') D[10]++;
            else if(s[1]=='J') D[11]++;
            else if(s[1]=='Q') D[12]++;
            else if(s[1]=='K') D[13]++;
            else D[s[1]-'0']++;
        }
        if(s[0]=='C')
        {
            if(s[1]=='A') C[1]++;
            else if(s[1]=='T') C[10]++;
            else if(s[1]=='J') C[11]++;
            else if(s[1]=='Q') C[12]++;
            else if(s[1]=='K') C[13]++;
            else C[s[1]-'0']++;
        }
        if(s[0]=='H')
        {
            if(s[1]=='A') H[1]++;
            else if(s[1]=='T') H[10]++;
            else if(s[1]=='J') H[11]++;
            else if(s[1]=='Q') H[12]++;
            else if(s[1]=='K') H[13]++;
            else H[s[1]-'0']++;
        }
        if(s[0]=='S')
        {
            if(s[1]=='A') S[1]++;
            else if(s[1]=='T') S[10]++;
            else if(s[1]=='J') S[11]++;
            else if(s[1]=='Q') S[12]++;
            else if(s[1]=='K') S[13]++;
            else S[s[1]-'0']++;
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        if(!D[i]) ans++;
        if(!C[i]) ans++;
        if(!H[i]) ans++;
        if(!S[i]) ans++;
    }
    cout<<ans;
    return 0;
}
