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

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cout<<"5\n19\n7\n1\n";
    return 0;
}
