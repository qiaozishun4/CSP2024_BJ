#include<bits/stdc++.h>
using namespace std;
int m[20]={6,2,5,5,4,5,6,3,7,6};
int t,a[100],b[100];
int f(int x){
    int ans=0;
    while(x!=0){
        int x1=x%10;
        ans+=m[x1];
        x/10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >>t;
    for(int i=1;i<=t;i++){
        cin >>a[i];
        if(a[i]<2){
            b[i]=-1;
            continue;
        }
        for(int j=1;j;j++){
            if(f(j)==a[i]){
                b[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=t;i++) cout <<b[i] <<endl;
    return 0;
}
