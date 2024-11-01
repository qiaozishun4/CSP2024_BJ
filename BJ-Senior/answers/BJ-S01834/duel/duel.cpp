#include<bits/stdc++.h>
using namespace std;
int n,d=0,le=0,sa=0;
int r[200001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            if(r[j]>r[j+1]){
                swap(r[j],r[j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(r[i]==r[i-1]){
            sa++;
        }else{
            if(sa>le){
                d+=sa-le;
                le+=sa-le;
            }
            sa=0;
        }
    }
    cout<<d+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
