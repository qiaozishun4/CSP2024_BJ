#include <iostream>
using namespace std;
int n,m;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>m;
        while(m>0)
        {
            cout<<8;
            m-=8;
        }
    }
    return 0;
}