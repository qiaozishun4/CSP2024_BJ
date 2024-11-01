#include<iostream>
using namespace std;
int ans[100000],weis[10];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n<2)
        {
            ans[i]=-1;
            break;
        }
        for(int j=1;j<=100000;j++)
        {
            int sum=0;
            int k=1;
            while(n>0)
            {
                weis[k]=n%10;
                n/=10;
                k++;
            }
            for(int l=1;l<=k;l++)
            {
                if(weis[l]==1) sum+=2;
                if(weis[l]==7) sum+=3;
                if(weis[l]==4) sum+=4;
                if(weis[l]==2 or weis[l]==3 or weis[l]==5) sum+=5;
                if(weis[l]==0 or weis[l]==6 or weis[l]==9) sum+=6;
                if(weis[l]==8) sum+=7;
            }
            if(sum==n)
            {
                ans[i]=sum;
                continue;
            }
            else ans[i]=-1;

        }
    }
    for(int i=1;i<=t;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

