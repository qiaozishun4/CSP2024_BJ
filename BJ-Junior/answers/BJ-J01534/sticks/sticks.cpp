#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x=-1;
        for(int i=1;i<=50000;i++)
        {
            int m=0;
            int j=i;
            while(j)
            {
                m+=s[j%10];
                j/=10;
            }
            if(m==n)
            {
                x=i;
                break;
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
