#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[100005],p[100005]={0};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]]++;
    }
    int cnt=0;
    int last=n;
    int sheng=n;
    for(int i=1;i<=100000;i++){
        if(p[i]){
            if(last-p[i]>=p[i]){
                last-=p[i]*2;
                cnt+=p[i];
                sheng-=p[i];
            }else{
                cnt+=sheng-p[i];
                cout<<n-cnt;return 0;
            }
        }
    }
return 0;
}
