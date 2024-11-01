#include <iostream>
#include <vector>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
int dp[10005]={};

void()

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        if(n==0)
            cout<<-1<<endl;
        else if(n==2)
            cout<<1<endl;
        else if(n==3)
            cout<<7<endl;
        else if(n==4)
            cout<<4<endl;
        else if(n==5)
            cout<<2<endl;
        else if(n==6)
            cout<<6<endl;
        else if(n==7)
            cout<<8<endl;
        else if(n%7==0){
            for(int i=0;i<n/7;i++)
                cout<<8;
            cout<<endl;
        } else if((n-1)%7==0){
            cout<<26;
            for(int i=0;i<((n-1)/7-1);i++)
                cout<<8;
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}
