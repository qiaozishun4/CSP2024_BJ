#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdin);
    int a[13]={8,0,2,4,7,1},b[13]={7,6,5,4,3,2},aa[13]={8,7,4,2,1,0},bb[13]={7,3,4,5,2,6};
    int T,n[100],nn[100],tong[100][100],tong0[100],awa=0;
    for(int i=0;i<T;i++)
    {
        cin >> n[i];
    }
    for(int i = 0;i<T;i++)
    {
        if(n[i]<2)
        {
            tong0[i]=-1;
        }
        else
        {
            for(int j=0;j<10;j++)
            {
                tong[i][a[j]]+=n[i]/b[j];
                n[i]=n[i]%b[j];
                nn[i]++;
            }
        }
    }
    int ans=0;
    int minn=1001230;
    for(int i =0;i<T;i++)
    {
        int fang = 1;
        minn=87316498;
        ans=-1;
        for(int j = 5;j>=0;j--)
        {
            if(a[j]&&a[j]<minn&&tong[i][a[j]])
            {
                minn=a[j];
            }
        }
        tong[i][minn]--;
        for(int awaa=0;awaa<nn[i];awaa++)
        {
            minn*=10;
        }
        ans+=minn;
        minn=1;
        while(nn[i]>=0)
        {
            for(int j = 5;j>=0;j--)
            {
                for(int u = tong[i][aa[j]];u>0;u--)
                {
                    nn[i]--;
                    for(int i = 0;i<nn[i];i++)
                    {
                        minn*=10;
                    }
                    ans+=minn*aa[j];
                    minn=1;
                }
            }
        }
        cout << ans << endl;
        ans=-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
