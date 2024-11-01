#include <iostream>
using namespace std;
long long n,chong=0;
string str[57];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> str[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (str[i]==str[j]) {
                chong++;
            }
        }
    }
    cout << 52-n+chong;
    return 0;
}
