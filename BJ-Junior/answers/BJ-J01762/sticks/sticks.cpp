#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int b[N] = {-1,-1,1,7,4,2,6,8,16,18,23,26,38,68,88,108,188,200,208,288,688,888,1088,2000,2008,2088,2888};
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++)
        cout << b[a[i]] << endl;
    return 0;
}
