#include <iostream>
#include <algorithm>
using namespace std;
int c[130][130];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin >> n;
    int ans=52;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin >> a >> b;
        if(c[a][b]==0)  ans--;
        c[a][b]=1;
    }
    cout << ans << endl;
    return 0;
}