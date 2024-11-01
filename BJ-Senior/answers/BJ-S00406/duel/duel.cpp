#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int m[n],t[100005]={0};
    for(int i=0;i<100005;i++){
        t[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>m[i];
        t[m[i]]++;
    }
    for(int i=0;i<100005;i++){
        if(t[i]){
            int j=i;
            i++;
            while(i<100005&&!t[i]){
                i++;
            }
            if(t[j]<=t[i]){
                t[j]=0;
            }
            else{
                t[j]-=t[i];
            }
            i--;
        }
    }
    int sum=0;
    for(int i=0;i<100005;i++){
        sum+=t[i];
    }
    cout<<sum;
    return 0;
}

