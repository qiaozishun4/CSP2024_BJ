#include<bits/stdc++.h>
using namespace std;
int main(){
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
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1)
        {
            if(n==8)
            {
                cout<<10<<endl;
            }
            else
            {
                cout<<10;
                for(int i=1;i<=((n-8)/7);i++)
                {
                    cout<<8;
                }
                cout<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
