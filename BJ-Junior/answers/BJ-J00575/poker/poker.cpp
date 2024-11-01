#include <bits/stdc++.h>
using namespace std;
string s[55],a[55]={"0"};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        bool f=1;
        for(int j=1;j<=n;j++)
        {
            if(a[j]=="0") break;
            else if(s[i]==a[j]) f=0;
        }
        if(f){a[i]=s[i];ans--;}
    }
    cout<<ans<<endl;
    return 0;
}
