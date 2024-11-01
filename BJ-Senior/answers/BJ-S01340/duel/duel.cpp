#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int x=0,y=0;
    for(int i=1;i<=n;++i){
        if(a[i]>a[i-1]){
            x+=y;
            y=0;
        }
        ++y;
        x=max(0,x-1);
    }
    printf("%d\n",x+y);
    return 0;
}