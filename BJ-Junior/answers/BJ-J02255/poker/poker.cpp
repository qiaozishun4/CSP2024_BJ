#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string,bool> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    string s;
    cin>>n;
    int ans=52-n;
    while(n--)
    {
        cin>>s;
        if(m[s])ans++;
        m[s]=true;
    }
    cout<<ans;
    return 0;
}
