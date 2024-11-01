#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int box[N];
int n;
int st[10]={6,2,5,5,4,5,6,3,7,6};
int flag=1;
int num;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        cin >>n;
        if(n==1) cout <<-1<<'\n';
        else if(n%7==1)
        {
            int x=n/7;
            cout <<10;
            for(int i=1;i<x;i++) cout <<8;
            cout <<'\n';
        }
        else
        {
            int x=n/7;
            int m=n%7;
            for(int i=1;i<=9;i++)
            {
                if(st[i]==m)
                {
                    cout <<i;
                    break;
                }
            }
            for(int i=1;i<=x;i++) cout <<8;
            cout <<'\n';
        }
    }
    return 0;
}
