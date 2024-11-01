#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int d,v,a;
}car[1000001];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,L,V,p[1000001]={},cnt=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>car[i].d>>car[i].v>>car[i].a;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(car[i].a==0)
            {
                if(car[i].v>V)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<" "<<1;
        for(int i=1;i<=n;i++)
        {
            if(car[i].a>0)
            {
                int v00=sqrt(car[i].v*car[i].v+2*car[i].a*(L-car[i].d));
                if(v00>V)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<" "<<1;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
