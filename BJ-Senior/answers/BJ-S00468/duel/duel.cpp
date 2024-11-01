#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int number[3]={};
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        number[x]++;
    }
    cout<<max(n-number[2],n-number[1]);
    return 0;
}
