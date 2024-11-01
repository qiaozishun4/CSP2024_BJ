#include<bits/stdc++.h>
using namespace std;
int v[100000],ans=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int a=s[0],b=s[1];
        int res=a*100+b;
        if(!v[res])
        {
            ans++;
            v[res]=1;
        }
    }
    cout<<(52-ans);
    return 0;
}
