#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,mi=INT_MAX,ma;
int a[N],ans;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mi=min(mi,x);
        ma=max(ma,x);
        a[x]++;
    }

    int nowl=mi,nowr=0;
    for(int i=mi;i<=ma;i++){
        if(a[nowl]==0){
            nowl++;
        }else if(a[nowl]&&a[nowr]==0){
            if(nowr<=nowl){
                nowr=nowl+1;
            }else{
                nowr++;
            }
        }else{
            if(a[nowl]<=a[nowr]){
                ans-=a[nowl];
                a[nowl]=0;
            }else{
                ans-=a[nowr];
                a[nowr]=a[nowl];
                a[nowl]=0;
            }
            nowl=nowr;
            nowr++;
        }
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
