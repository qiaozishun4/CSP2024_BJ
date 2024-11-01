#include<bits/stdc++.h>
using namespace std;
int n,T;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        n=0;
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
        }
        else if(n%7==1)
        {
            cout<<10;
            for(int i=1;i<=(n-1)/7-1;i++) cout<<8;
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
