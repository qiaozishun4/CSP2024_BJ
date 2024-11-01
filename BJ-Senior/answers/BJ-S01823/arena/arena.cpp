#include <bits/stdc++.h>
using namespace std;
char t[1<<20];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    memcpy(t,"TEST",4);
    char*s=t+8;
    char*e=t+(1<<20);
    while(s!=e)memcpy(s,t,s-t),s+=int(s-t);
    for(;;)fwrite(t,1<<20,1,stdout);
    return 0;
}