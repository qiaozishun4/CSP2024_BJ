#include <bits/stdc++.h>
using namespace std;
long long n[101];
int b[10]={6,2,5,5,4,5,6,3,7,6};
bool st(long long m,long long l)
{
    long long i,j,k,ans=b[m%10];
    for(j=m,i=1;(j/10)>0;i++) j/=10;
    for(j=2,k=100;j<=i;j++,k*=10) ans+=b[(m%k)/(k/10)];
    if(ans==l) return 1;
    else return 0;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    string s;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
        if(n[i]%7==0)
        {
            s='8';
            for(int j=1;j<n[i]/7;j++) s+='8';
            cout<<s<<endl;
        }
        else if(n[i]%7==1&&n[i]!=1)
        {
            s="10";
            for(int j=1;j<(n[i]-1)/7;j++) s+='8';
            cout<<s<<endl;
        }
        else
        {
            int cmp=0;
            long long j=1;
            for(int k=1;k<=n[i]/7;k++) j*=10;
            int tmp=j;
            for(;;j++)
            {
                if(st(j,n[i]))
                {
                    cout<<j<<endl;
                    cmp=1;
                    break;
                }
                if(j>=tmp*100||j>=80000000)
                {
                    cout<<"-1"<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
