#inclde<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[1000000]={0};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=a[i],sum=a[i];
        for(int i=2;i<=n;i++){
            if(a[i]<cnt&&a[i]!=0){
                cnt=i;
            }
            if(a[i]>=sum&&a[i]!=0){
                sum=i;
            }
        }
        if(a[cnt]<a[sum]){
            n--;
            a[cnt]==0;
        }
    }
    cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
