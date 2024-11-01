#include<bits/stdc++.h>
using namespace std;
int o[100005]={0};
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>o[i];
    }
    sort(o+1,o+n+1);
    int l=1,r=1,cnt=0;
    while(r<=n){
        if(o[l]==o[r]){
            r++;
        }
        else if(o[r]==-97638){
            r++;
        }
        else if(o[l]==-97638){
            l++;
        }
        else{
            o[l]=-97638;l++;r++;cnt++;
        }
    }
    cout<<n-cnt;
    fclose(stdin);
    fclose(stdout);
}
