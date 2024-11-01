#include<bits/stdc++.h>
using namespace std;
int minn,g=0;
const int maxn = 100010;
int a[maxn],n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    minn=a[0];
    int t=0;
    for(int i=0;i<n;i++){
        if(a[i]>a[t]){
            t++;
        }else g++;
    }
    cout<<g;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
