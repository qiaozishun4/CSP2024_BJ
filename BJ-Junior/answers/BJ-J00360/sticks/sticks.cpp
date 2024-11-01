#include <bits/stdc++.h>

using namespace std;
const int MAX=1e5+3;
int num[MAX],n,tot=7;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    memset(num,-1,sizeof(num));
    num[2]=1;
    num[3]=7;
    num[4]=4;
    num[5]=2;
    num[6]=6;
    num[7]=8;
     while(t--)
     {
         cin>>n;
         while(tot<n)
        {
            tot++;
            for(int i=0;i<=9;i++)
            {
                if(num[tot-a[i]]!=-1)
                {
                    if(num[tot]==-1) num[tot]=num[tot-a[i]]*10+i;
                    else num[tot]=min(num[tot],num[tot-a[i]]*10+i);
                }
            }
        }
        cout<<num[n]<<endl;
    }
    return 0;
}
