#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(nullptr));
    int t;
    cin>>t;
    while(t--)
    {
        cout<<rand()%10000<<endl;
    }
    return 0;
}
