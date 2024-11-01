#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define int long long
using namespace std;
const int N=1e6+5;
int n,t[N],qz[N],ans,eaten;
signed main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);


    cin>>n;
    int x;
    forr(i,1,n) {
        cin>>x;
        t[x]++;
    }

    forr(i,1,N-2) {
        if(t[i]) {
            if(qz[i-1]<=t[i]) {
                eaten += qz[i-1];
                qz[i-1] = 0;

            } else {
                qz[i-1] -= t[i];
                eaten += t[i];
            }
        }
        qz[i] = qz[i-1]+t[i];
    }

    cout<< n-eaten;

    return 0;
}
