#include<bits/stdc++.h>
using namespace std;
int n,ans,ans1;
int a[100000];
int b[100000];
bool cmp(int x,int y){
    if(x>y){
        return 1;
    }
    return 0;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=n-1,r=n;
    while(l!=0){
        if(a[l]>a[r]){
            a[r]=0;
            b[l]=1;
            r--;
            l--;
        }else if(a[l]==a[r]){
            l--;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            ans1++;
        }
    }
    cout<<ans1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
