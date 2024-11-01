#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;
        b[x]++;
    }
    int tmp=100000;
    while(a[tmp]==0){
        tmp--;
    }
    tmp++;
    for(int i=1;i<=tmp;i++){
        while(b[i]>0){
            int flag=0;
            for(int j=i-1;j>0;j--){
                if(a[j]){
                    a[j]--;
                    b[i]--;
                    flag=1;
                    break;
                }
            }
            if(flag==0) break;
        }
    }
    int ans=0;
    for(int i=1;i<=tmp;i++){
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
