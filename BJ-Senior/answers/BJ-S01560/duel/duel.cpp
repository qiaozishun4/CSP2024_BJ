#include<bits/stdc++.h>
using namespace std;
int n,r[100005],cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=2;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(r[j]<0)continue;
            if(r[i]>r[j]){
                r[j]=-1;
                break;
            }
        }
    }for(int i=1;i<=n;i++)if(r[i]>0)cnt++;
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
