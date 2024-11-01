#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[100009];
char is[100009];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    long long l=0,r=0;
    while(l<n){
        if(is[l]==1||is[l]==2){
            l++;
        }
        else if(is[r]==1){
            r++;
        }
        else if(a[l]==a[r]){
            r++;
        }
        else{
            is[l]=2;
            is[r]=1;
            l++;
            r++;
        }
    }
    for(int i=0;i<n;i++){
        if(is[i]==0||is[i]==2){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//3 2 2 1 1
//l r
