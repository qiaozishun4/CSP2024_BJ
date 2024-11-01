#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int s[N];
int g[N];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]&&s[j]==0){
                s[i]=1;
                g[j]=1;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(s[1]==0){
            sum++;
        }
    }
    cout<<<sum;
    return 0;
}