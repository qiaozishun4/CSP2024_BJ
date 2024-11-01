#include<iostream>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int leftnum[22]={0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        int eight=n/21*3;
        int left=n%21;
        if(left==1)
        {
            eight--;
            cout<<10;
        }
        if(left>1)
        {
            cout<<leftnum[left];
        }
        for(int i=1;i<=eight;i++)cout<<8;
        cout<<endl;
    }
    return 0;
}
