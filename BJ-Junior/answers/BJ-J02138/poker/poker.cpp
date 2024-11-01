#include<bits/stdc++.h>
using namespace std;
short a[52];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    short n;
    scanf("%hd", &n);
    for(char i=0, s[2];i<n;++i) {
        scanf("%s", s);
        a[i] = *((short*)s);
    }
    sort(a, a+n);
    printf("%ld", 52 - (unique(a, a+n) - a));
    fclose(stdin);
    fclose(stdout);
    return 0;
}