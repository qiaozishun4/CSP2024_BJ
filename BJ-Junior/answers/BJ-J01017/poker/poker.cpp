#include <iostream>
#include <cstring>
using namespace std;
int n,x;
string a[105];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    x=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<i;j++)
        {
            if(a[i]==a[j])
            {
                x--;
                break;
            }
        }
    }
    cout<<52-x;
    return 0;
}
