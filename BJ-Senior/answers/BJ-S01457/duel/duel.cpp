#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,mx=0,mxx=0;
    cin>>n;
    int sum=n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
        mx=max(mx,x);
        mxx=max(mxx,a[x]);
    }for(int i=mx;i>=0;i--){
        int m=sum-a[i];
        if(a[i]<=m){
            sum-=a[i];
        }else{
            sum-=m;
            break;
        }
    }cout<<max(sum,mxx)<<endl;
    fclose(stdin);
    fclose(stdout);


return 0;
}
