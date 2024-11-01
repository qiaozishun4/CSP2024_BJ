#include <bits/stdc++.h>
using namespace std;
const int N=100010;

int n,cnt,s;
bool flag=1;
int r[N],t[N];

int main () {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>r[i];
        t[r[i]]++;
    }

    int s=-1;
    for (int i=1;i<=100010;i++) {
        if (t[i]>=s) s=t[i];
    }

    printf("%d\n",s);

    return 0;
}
