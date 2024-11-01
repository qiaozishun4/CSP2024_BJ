#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N];
int cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("duel4.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int j=0;
    for(int i=1;i<n;i++){
        if(a[i]>a[j])j++;
    }
    printf("%d",n-j);
    return 0;
}
