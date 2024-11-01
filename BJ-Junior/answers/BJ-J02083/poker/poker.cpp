#include <iostream>
#include <map>
using namespace std;
int n,ans;
string s;
map<string,int> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        m[s]++;
    }
    ans=52-m.size();
    cout<<ans;
    return 0;
}
