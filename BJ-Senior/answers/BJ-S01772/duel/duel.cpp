#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int live[1000000];
int hited[1000000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        live[i]=1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int j=1;
        for(;j<n-i;j++){
            if(hited[i+j]==0&&a[i+j]>a[i]){
                live[i]=0;
                hited[i+j]=1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(live[i]){
            cnt++;
        }
    }
    cout<<cnt;
}