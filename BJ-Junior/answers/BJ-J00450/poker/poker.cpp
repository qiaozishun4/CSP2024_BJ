#include <iostream>
#include <algorithm>
using namespace std;
int n,cnt,ans;
string a[54];
int cmp(string a,string b)
{
    int la=a.length();
    int lb=b.length();
    if (la!=lb) return 1;
    for (int i=0;i<la;i++)
        if (a[i]!=b[i]) return 1;
    return 0;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for (int i=1;i<n;i++)
            if (cmp(a[i],a[i-1])!=0)
                cnt++;
    ans=52-cnt-1;
    cout<<ans;
    return 0;
}
