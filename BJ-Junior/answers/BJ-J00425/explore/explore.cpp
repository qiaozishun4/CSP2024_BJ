#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int dxd = {0,1,0,-1};
int dyd = {1,0,-1,0};
int abc(T,x,y,d,k,ans)
{
    int xx=x,yy=y,dd=d,kk=k,aan=ans;
    kk-=1;
    if(kk==0)
    {
        return ans;
    }
    if(xx+dxd[dd]>=0&&xx+dxd[dd]<n[T]&&yy+dyd[dd]>=0&&yy+dyd[dd]<m[T]&&b[T][xx+dxd[dd]][yy+dyd[dd]]==0)
    {
        b[T][xx+dxd[dd]][yy+dyd[dd]]=1;
        aan++;
        aan=abc(T,xx,yy,dd,kk,aan);
    }
    else
    {
        dd=(d+1)%4;
        aan=abc(T,xx,yy,dd,kk,aan);
    }
    b[T][xx+dxd[dd]][yy+dyd[dd]]=0;
    return aan;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdin);
    int a[6][1040][1040],b[6][1040][1040],T,n[10],m[10],k[10],x[10],y[10],d[10],ans[10];
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> n[i] >>m[i] >>k[i];
        cin >> x[i] >> y[i] >>d[i];
        for(int j=0;j<n[i];i++)
        {
            for(int u=0;u<m[i];u++)
            {
                cin >> a[i][j][u];
            }
        }
    }
    for(int i = 0;i<T;i++)
    {
        ans[i]=abc(i,x[i],y[i],d[i],0);
    }
    for(int i=0;i<T;i++)
    {
        cout << ans[i] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
