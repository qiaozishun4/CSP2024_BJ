//T1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar((x%10)^48);
}
ll n,a,b,ans;
bool isc[5][40];
char st[44];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        scanf("\n%s",st+1);
        switch(st[1]){
            case 'D':a=1;break;
            case 'C':a=2;break;
            case 'H':a=3;break;
            case 'S':a=4;break;
        }
        if(st[2]>='0' && st[2]<='9'){
            b=st[2]-'0';
        }else if(st[2]=='T')b=10;
        else if(st[2]=='J')b=11;
        else if(st[2]=='Q')b=12;
        else if(st[2]=='K')b=13;
        else if(st[2]=='A')b=1;
        isc[a][b]=true;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!isc[i][j]){
                ans++;
            }
        }
    }
    print(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
