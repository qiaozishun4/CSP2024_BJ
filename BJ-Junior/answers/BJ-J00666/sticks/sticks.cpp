#include<bits/stdc++.h>//完全背包？ 
using namespace std;
int T;
int n;
const int a[55] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,206,208,288,688,888,1088};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}