#include <bits/stdc++.h>
using namespace std;
long long num[15]={6,2,5,5,4,5,6,3,7,6};
long long t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=-1;
        if(n==1)
        {
            cout<<"-1"<<endl;
        }
        //next
        else
        {
            for(long long i=1;i<=1000000;i++)
        {
            long long m=0;
            long long p=i;
            while(p!=0)
            {
                m+=num[p%10];
                p/=10;
            }
            if(m==n)
            {

                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
