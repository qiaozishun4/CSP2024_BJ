#include <bits/stdc++.h>

using namespace std;
long long T;
long long n;
long long a[2000005],f[2000005][2];
int s;
int mass;
int r[10000005],l[10000005];
int tor,tol;
void u(int o){
    if(o > n){
        mass = max(s,mass);
        return;
    }
    if(r[tor] == a[o]) s += a[o];
    tor++;
    r[tor] = a[o];
    u(o+1);
    tor--;
    if(r[tor] == a[o]) s -= a[o];
    if(l[tol] == a[o]) s += a[o];
    tol++;
    l[tol] = a[o];
    u(o+1);
    tol--;
    if(l[tol] == a[o]) s -= a[o];
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(long long i = 1;i <=n;i++){
            cin >>a[i];

        }
            u(1);
            cout << mass << endl;
    }
    return 0;
}
