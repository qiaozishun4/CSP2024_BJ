#include<bits/stdc++.h>
using namespace std;
int a[100001];
int f(int n)
{
    if(n<=1)
        return -1;
    else
    {
        a[2]=1;
        a[3]=7;
        a[4]=4;
        a[5]=2;
        a[6]=6;
        a[7]=8;
        a[8]=10;
        a[9]=18;
        a[10]=22;
        a[11]=20;
        a[12]=28;                                           //2 3 4 5 5 5 6 6 6 7
                                                            //1 7 4 2 3 5 0 6 9 8
        a[13]=68;
        a[14]=88;
        a[15]=108;
        a[16]=188;
        a[17]=228;
        a[18]=208;
        a[19]=288;
        a[20]=688;
        a[21]=888;
        if(n>21)
        {
            long long k = n,sum=0,tmp=1,cnt=0;
            while(k>21)
            {
                k-=7;
                cnt+=tmp;
                tmp*=10;
            }
            if(n%7!=0)
                a[n]=a[(n%7)+14]*tmp+cnt*8;
            else
            {
                a[n]=a[21]*tmp+cnt*8;
            }
        }
    }
    return a[n];
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    int a[51],ans[51];
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<t;i++)
    {
        ans[i] = f(a[i]);
        cout<<ans[i]<<endl;
    }
    return 0;
}
