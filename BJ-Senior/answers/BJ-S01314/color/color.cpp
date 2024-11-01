#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,a[1000001]={},b[1000001]={};
        long long cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
        for(int i=1;i<=1000000;i++)
        {
            if(b[i]==2&&a[i%n]!=a[i%n-1]&&a[i%n]!=a[i%n+1])
            {
                cnt+=i;
            }
            if(b[i]>2)
            {
                cnt+=i;
            }
        }
        cout<<cnt<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
