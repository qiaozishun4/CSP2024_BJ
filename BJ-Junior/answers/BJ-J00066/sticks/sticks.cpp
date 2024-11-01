#include <bits/stdc++.h>
using namespace std;
const int N=100005;
string f[N];
int a[10]={6,2,5,5,4,5,6,3,7,6};
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
        if(n==1)
        {
            cout<<-1<<endl;
        }
        for(int i=1;i<=2000000;i++)
        {
            int x=i;
            int sum=0;
            while(x!=0)
            {
                sum=sum+a[x%10];
                x=x/10;
            }
            if(sum==n)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
