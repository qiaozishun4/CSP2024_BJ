#include<bits/stdc++.h>
using namespace std;
int n,len,ans,a[100010],b[100010],c[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=100000;i++){
        if(b[i]){
            c[++len]=b[i];
        }
    }
    for(int i=1;i<=len;i++){
        int x=c[i],j=i-1;
        while(j>0){
            if(x-c[j]>0){
                x-=c[j];
                c[j]=0;
            }else if(x-c[j]<0){
                c[j]-=x;
                break;
            }else{
                c[j]=0;
                break;
            }
            j--;
        }
    }
    for(int i=1;i<=len;i++){
        ans+=c[i];
    }
    cout<<ans;
    return 0;
}
