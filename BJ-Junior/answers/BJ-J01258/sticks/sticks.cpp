#include <iostream>
using namespace std;
long long n,ans;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    long long a;
    for(int i=1;i<=n;i++){
        cin>>a;
        a/=8;
        for(int i=1;i<=a;i++){
            cout<<"8";
        }
    }
    return 0;
}