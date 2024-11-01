#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t = 0;
    cin>>t;
    while(t--)
    {
        int n = 0;
        cin>>n;
        if(n <= 1)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(n == 2)
        {
            cout<<1<<endl;
        }
        else{
            int k = n / 7;
            for(int i = 1;i <= k;i++)
                cout<<8;
        }
        cout<<endl;
    }
}
