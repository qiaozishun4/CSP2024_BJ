#include<bits/stdc++.h>
using namespace std;
int r[100005];
int a[100005];
int b=-100005;
long long num=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int c=100005;
    for(int i=0;i<n;i++){
        cin>>r[i];
        a[r[i]]++;
        b=max(r[i],b);
        c=min(r[i],c);
    }
    for(int i=0;i<=b;i++){
        if(a[i]==0||i==c){
            continue;
        }
        if(a[c]>a[i]){
            n-=a[i];
            a[c]-=a[i];
            num+=a[c];

        }else if(a[c]<a[i]){
            n-=a[c];
            a[i]-=a[c];
            if(a[i]>=num){
                num=0;
            }else{
                num-=a[i];
            }
        }else{
            n-=a[c];
        }
        c=i;
    }
    cout<<n;
    return 0;
}
