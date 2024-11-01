#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[100001],flag[100001]={1};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //cout<<a[i]<<" ";
    }
    for(int i=0;i<n;i++){
        if(flag[i]==1){
            for(int j=0;j<n;j++){
                if(a[j]<a[i]&&flag[j]!=-1){
                    flag[j]=-1;
                    break;
            }
        }
        flag[i]=0;
    }
}
    int sum=0;
    for(int i=0;i<n;i++){
        if(flag[i]==0){
            sum+=1;
        }
    }
    cout<<sum<<endl;
    return 0;
}
