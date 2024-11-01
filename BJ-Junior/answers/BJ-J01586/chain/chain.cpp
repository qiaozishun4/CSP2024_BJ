#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
#include<string>
struct node
{
    int r,c;
}rc[1000001];
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        queue<int>A;
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            string x;
            getline(cin,x);

        }
        for(int i=1;i<=q;i++)
        {
            cin>>rc[i].r>>rc[i].c;
            if(rc[i].c>=k&&rc[i].r<rc[i].c)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<1<<endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
