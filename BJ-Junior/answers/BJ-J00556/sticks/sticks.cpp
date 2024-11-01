#include <bits/stdc++.h>
using namespace std;
int st[10]={6,2,5,5,4,5,6,3,7,6};
long long cnt(long long n)
{
    long long sum=0;
    while(n)
    {
        sum+=st[n%10];
        n/=10;
    }
    return sum;
}
long long ck(int n)
{
    int i=1;
    if(n==1)return -1;
    while(i<=99999999999ll)
    {
        if(cnt(i)==n)
        {
            return i;
        }
        i++;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ck(n)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
