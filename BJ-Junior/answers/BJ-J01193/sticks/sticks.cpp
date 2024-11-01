#include <bits/stdc++.h>
using namespace std;

int n;//1e5
string s[10]={"8","10","18","22","20","28","68"};
char c[10]={'-','-','1','7','4','2','6'};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;//5e1
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
            cout<<-1;
        else if(n<7)
            cout<<c[n];
        else
        {
            cout<<s[n%7];
            for(int i=1;i<=n/7-1;i++)
                cout<<8;
        }
        cout<<endl;
    }

    return 0;
}
