#include <iostream>
using namespace std;
long long n,a[15]={6,2,5,5,4,5,6,3,7,6},T,flag;
long long f(long long x) {
    long long retur=0;
    while(x>0) {
        retur+=a[x%10];
        x/=10;
    }
    return retur;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    for (int i=1;i<=T;i++) {
        cin >> n;
        for (int j=0;j<=1000000;j++) {
            if (f(j)==n) {
                cout << j << endl;
                flag++;
                break;
            }
        }
        if (flag==0) {
            cout << "-1" << endl;
        }
    }
    return 0;
}
