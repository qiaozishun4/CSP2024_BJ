#include <bits/stdc++.h>
using namespace std;
int n,ans;
map<string,int>mp;
char ch1[10]={'D','C','H','S'};
char ch2[20]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string pok;
        cin>>pok;
        mp[pok]++;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            string pok;
            pok+=ch1[i];
            pok+=ch2[j];
            if(!mp[pok])ans++;
        }
    }
    cout<<ans;
    return 0;
}
