#include<iostream>
#include<algorithm>
using namespace std;
int n;
string s[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1);
    n=unique(s+1,s+n+1)-s-1;
    cout<<52-n;
    return 0;
}
