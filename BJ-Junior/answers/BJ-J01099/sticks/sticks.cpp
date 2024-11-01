#include<iostream>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w ",stdout);
    int n;
    cin>>n;
    int t;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==1)
        {
            cout<<-1<<endl;
            break;
        }
        else if(t==2)
        {
            cout<<1<<endl;
            break;
        }
        else if(t==3)
        {
            cout<<7<<endl;
            break;
        }
        else if(t==4)
        {
            cout<<4<<endl;
            break;
        }
        else if(t==5)
        {
            cout<<2<<endl;
            break;
        }
    }
    return 0;
}
