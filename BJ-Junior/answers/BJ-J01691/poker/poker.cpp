#include<bits/stdc++.h>
using namespace std;
string a[60];
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int m=unique(a,a+n)-a;
    cout<<52-m<<endl;
    return 0;
}