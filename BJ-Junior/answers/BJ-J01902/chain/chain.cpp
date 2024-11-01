#include<iostream>
using namespace std;
int main ()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(i%2==0)cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
