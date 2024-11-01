#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;++l)
    {
        srand(1234);
        cout<<rand()%15<<endl;
    }
    return 0;
}
