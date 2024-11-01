#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int T;
int n;
int a[N];
int d[N],p[N];
int red[N],blue[N];//red
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        d[1] = p[1] = 0;
        red[1] = a[1],blue[1] = a[1];
        for(int i = 2;i<=n;i++){
            if(a[i]==a[i-1]&&a[i]==red[i-1]){
                d[i] = max(d[i-1]+a[i-1],p[i-1]+red[i-1]);
                blue[i] = blue[i-1];
            }else if(a[i]==a[i-1]){
                d[i] = max(d[i-1]+a[i-1],d[i]);
                blue[i] = blue[i-1];
            }else if(a[i]==red[i-1]){
                d[i] = max(d[i],p[i-1]+red[i-1]);
                blue[i] = blue[i-1];
            }else{
                d[i] = 0;
                blue[i] = a[i-1];
            }
            if(a[i]==a[i-1]&&a[i]==blue[i-1]){
                p[i] = max(p[i-1]+a[i-1],d[i-1]+blue[i-1]);
                red[i] = red[i-1];
            }else if(a[i]==a[i-1]){
                p[i] = max(p[i-1]+a[i-1],p[i]);
                red[i] = red[i-1];
            }else if(a[i]==red[i-1]){
                p[i] = max(p[i],d[i-1]+blue[i-1]);
                red[i] = red[i-1];
            }else{
                d[i] = 0;
                red[i] = a[i-1];
            }
        }
        cout<<max(d[n],p[n])<<endl;
    }

    return  0;
}
