#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ft=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int sum=n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[ft]<a[i]){
            sum--;
            ft++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
