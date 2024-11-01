#include <iostream>
using namespace std;
int t,n,b[20]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=17)
        {
            cout<<b[n]<<endl;
        }
        else
        {
            int x=n,cnt=0;
            while(x>17)
            {
                x-=7;
                cnt++;
            }
            cout<<b[x];
            for(int i=1;i<=cnt;i++)
            {
                cout<<"8";
            }
            cout<<endl;
        }
    }
    return 0;
}

