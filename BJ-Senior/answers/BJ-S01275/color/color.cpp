#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        unsigned long long n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
            if(b[a[i]]==2)
            {
                cnt+=a[i];
                b[a[i]]=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
