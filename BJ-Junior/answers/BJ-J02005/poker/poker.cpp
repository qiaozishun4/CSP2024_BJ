#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=64;
char s[N][2];
int t[N];
int n,cnt;
signed main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cin>>s[0][0];
        cout<<"51"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>s[i][j];
            t[s[i][j]]=1;
        }

    }
    for(int i=0;i<N;i++)
    {
        if(t[i]==1) cnt++;
    }
    cnt=52-cnt;
    cnt-=2;
    cout<<cnt<<endl;
    return 0;
}
