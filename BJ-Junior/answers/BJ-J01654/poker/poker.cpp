#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
map <string,int> ma;
vector<int> v;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--)
    {
       cin>>s;
       if(ma[s]==0)
       {
           ma[s]=1;
           v.push_back(1);
       }
    }
    ans=52-v.size();
    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
