#include <bits/stdc++.h>

using namespace std;
long long n;
long long a[1000005];
long long s;
long long mass;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >>n;
    for(long long i = 1;i <=n;i++) cin >>a[i];
    sort(a+1,a+1+n);
    long long f = a[1];
    for(long long i = 1;i <= n;i++){
        if(f == a[i]) s++;
        else{
            mass = max(mass,s);
            s = 1;
            f = a[i];

        }
        //cout << a[i] << ' ';
    }
    mass = max(mass,s);
    cout << mass;
    return 0;
}
