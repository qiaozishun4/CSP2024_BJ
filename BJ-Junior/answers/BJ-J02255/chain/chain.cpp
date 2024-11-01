#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    srand(time(NULL));
    int t;
    cin>>t;
    while(t--)
    {
        int n,num,n2,q;
        cin>>n>>num>>q;
        while(q--)cout<<rand()%2<<"\n";
    }
    return 0;
}
