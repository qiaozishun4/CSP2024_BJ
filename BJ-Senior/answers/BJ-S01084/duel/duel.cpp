#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
int cnt;
int idx;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin>>n;
    idx=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(a[i]>a[idx]){
            cnt++;
            idx++;
        }else{
            idx++;
        }
    }
    cout<<n-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}