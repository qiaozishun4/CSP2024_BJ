#include<bits/stdc++.h>
using namespace std;
int n,a[100005],h[100005],ans=0,x=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        h[a[i]]++;
    }
    for(int i=1;i<=100000;i++){
        if(h[i]!=0){
            if(x==0){
                x+=h[i];
            }else{
                if(x<h[i]){
                    x=h[i];
                }
            }
        }
    }
    cout<<x;
    fclose(stdin);
    fclose(stdout);
}

