#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
map <string,bool> m;
int main()
{
	freopen ("poker.in","r",stdin);
	freopen ("poker.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        if (!m[s])
        {
            m[s]=1;
            ans--;
        }
    }
    cout<<ans<<endl;
	return 0;
}
