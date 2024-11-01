#include<bits/stdc++.h>
using namespace std;

inline void read(int &x){
    int n=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    x=n*f;
    return;
}

inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar((x%10)|48);
    return;
}

int n,a[10000],mx;
bool b[10000];

void dfs(int s){
    if(s>n){
        int x=0,cnt=0;
        for(int i=1;i<=n;++i){
            if(b[i]){
                if(a[i]==a[x]){
                    cnt+=a[i];
                }
                x=i;
            }
        }
        x=0;
        for(int i=1;i<=n;++i){
            if(!b[i]){
                if(a[i]==a[x]){
                    cnt+=a[i];
                }
                x=i;
            }
        }
        mx=max(mx,cnt);
        return;
    }
    b[s]=0;
    dfs(s+1);
    b[s]=1;
    dfs(s+1);
    return;
}

void mian(){
    read(n);
    mx=0;
    for(int i=1;i<=n;++i){
        read(a[i]);
    }
    dfs(1);
    write(mx);
    putchar('\n');
    return;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    read(T);
    while(T--){
        mian();
    }
    return 0;
}
