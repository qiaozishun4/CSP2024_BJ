#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
inline int read(){
    int w = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        w = (w << 3) + (w << 1) +(ch ^ 48);
        ch = getchar();
    }
    return w*f;
}
struct car{
    int d,v,a;
} c[N];
int T,n,m,L,v00,p[N],ans;
int op1,op2,op3;
double insu(int v0,int v,int a){
    return (pow(v0,2) - pow(v,2)) / (2*a);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T = read();
    while(T --){
        ans = 0;
        op1 = 0,op2 = 0,op3 = 0;
        n = read(),m = read(),L = read(),v00 = read();
        for(int i = 1; i <= n; i ++){
            c[i].d = read(),c[i].v = read(),c[i].a = read();
            if(c[i].a == 0) op1 ++;
            else if(c[i].a > 0) op2 ++;
            else op3 ++;
        }
        for(int i = 1; i <= m; i ++) p[i] = read();
        if(op1 == n){ //A
            for(int i = 1; i <= n; i ++){
                if(c[i].v > v00 & c[i].d <= p[m]) ans ++;
            }
            printf("%d ",ans);
            if(ans == 0) printf("%d\n",m);
            else printf("%d\n",m-1);
        }
        else if(op2 == n){ //B
            for(int i = 1; i <= n; i ++){
                if(c[i].v <= v00){
                    double dis = insu(v00,c[i].v,c[i].a);
                    if(dis+c[i].d < p[m]) ans ++;
                }
                else{
                    if(c[i].d <= p[m]) ans ++;
                }
            }
            printf("%d ",ans);
            if(ans == 0) printf("%d\n",m);
            else printf("%d\n",m-1);
        }
    }
    return 0;
}
