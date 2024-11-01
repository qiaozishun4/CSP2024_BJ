#include<bits/stdc++.h>;
using namespace std ;
typedef long long ll;
ll b[10005];
ll n;
struct node{
    ll j,k=1;
}a[10005];
bool cmp(node x,node y){
    return x.j<y.j;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int num=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].j;
        b[a[i].j]++;
    }
    sort(a,a+n,cmp);
    ll k=0;
    for(int i=0;i<n-1;i++){
        if(a[i].j!=a[i+1].j){
            if(b[a[i+1].j]-b[a[i].j]<0 && a[i+1].j>a[i].j && a[i+1].k==1){
                b[a[i].j]-=b[a[i+1].j];
                a[i+1].k=0;
            }
            else if(b[a[i+1].j]-b[a[i].j]>0 && a[i+1].j>a[i].j && a[i+1].k==1){
                b[a[i+1].j]-=b[a[i].j];
                a[i+1].k=0;
            }
            else if(b[a[i+1].j]-b[a[i].j]>0 && a[i+1].j>a[i].j && a[i+1].k==1){
                b[a[i+1].j]-=b[a[i].j];
                a[i].k=0;
            }
            else if(b[a[i+1].j]-b[a[i].j]>0 && a[i+1].j>a[i].j && a[i+1].k==1){
                b[a[i+1].j]-=b[a[i].j];
                a[i].k=0;
            }
        }

    }
    for(int i=0;i<n;i++){
        sum+=b[a[i].j];
    }
    cout<<sum-n;
    return 0;
}
