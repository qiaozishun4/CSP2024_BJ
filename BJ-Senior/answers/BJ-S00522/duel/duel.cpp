#include<bits/stdc++.h>
using namespace std;
int r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>r[i];
    sort(r+1,r+1+n);
    int sum=0,s=0,s2=1;
    for(int i=2;i<=n;i++){
        if(r[i]>r[i-1]){
            s+=s2,s2=0;
            if(s>0){
                s--;
                sum++;
            }
            s2++;
        }
        else if(r[i]==r[i-1]){
            if(s>0){
                s--;
                sum++;
            }
            s2++;
        }
    }
    cout<<n-sum;
    return 0;
}
