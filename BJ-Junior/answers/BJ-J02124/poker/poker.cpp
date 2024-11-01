#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int d[64],c[64],h[64],s[64];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        char a,b;
        int x;
        getchar();
        scanf("%c%c",&a,&b);
        if(b == 'A') x = 1;
        else if(b == 'T') x = 10;
        else if(b == 'J') x = 11;
        else if(b == 'Q') x = 12;
        else if(b == 'K') x = 13;
        else x = b - 48;
        if(a == 'D') d[x]++;
        else if(a == 'C') c[x]++;
        else if(a == 'H') h[x]++;
        else s[x]++;
    }
    int ans = 0;
    for(int i = 1;i <= 13;i++){
        if(!d[i]) ans++;
        if(!c[i]) ans++;
        if(!h[i]) ans++;
        if(!s[i]) ans++;
    }
    printf("%d",ans);
    return 0;
}
