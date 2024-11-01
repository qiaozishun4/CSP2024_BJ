#include<bits/stdc++.h>
using namespace std;
string st1[60];
int main()
{

    int n;
    int cnt=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>st1[i];
    sort(st1+1,st1+n+1);
    for(int i=1;i<=n;i++)
    {
        if(st1[i]!=st1[i+1])
        {
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}
