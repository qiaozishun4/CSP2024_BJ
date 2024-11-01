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

int a[100005],n;
bool b[100005];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    read(n);
    for(int i=1;i<=n;++i){
        read(a[i]);
    }
    sort(a+1,a+n+1);
    int cnt=n,sum=0;
    for(int i=1,j=1;i<=n;++i){
        if(sum==0){
            sum=1;
        }
        else if(a[i]!=a[j]){
            cnt--;
            ++j;
        }
    }
    write(cnt);
    return 0;
}
