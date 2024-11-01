#include<bits/stdc++.h>
using namespace std;
int n,x,ma,mi=1e6,ans;
struct node{
    int num,sum;
}a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>ma){
            ma=x;
        }
        if(x<mi){
            mi=x;
        }
        a[x].num++;
        a[x].sum++;
    }
    for(int i=mi+1;i<=ma+2;){
        if(a[mi].sum>=a[i].num){
            a[mi].sum-=a[i].num;
            a[i].num=0;
        }
        else{
            a[i].num-=a[mi].sum;
            a[mi].sum=0;
        }
        if(a[i].sum==0||a[i].num==0){
            i++;
        }
        while(a[mi].sum==0){
            mi++;
        }

    }
    for(int i=0;i<=100003;i++){
        ans+=a[i].sum;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}