#include<bits/stdc++.h>
using namespace std;
int tot[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ra,l,r;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ra;
        tot[ra]++;
    }
    for(int i=1;i<=100000;i++){
        if(tot[i]!=0){
            l=i;
            break;
        }
    }
    for(int i=l+1;i<=100000;i++){
        if(tot[i]!=0){
            r=i;
            if(tot[l]<=tot[r]){
                tot[l]=0;
            }
            else if(tot[l]>tot[r]){
                tot[l]-=tot[r];
                tot[r]+=tot[l];
                tot[l]=0;
            }
            l=r;
        }
    }
    cout<<tot[r];
    return 0;
}
