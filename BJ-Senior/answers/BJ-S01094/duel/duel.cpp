#include<bits/stdc++.h>
using namespace std;
int n;
bool attak[100002];
bool die[100002];
int mon[100002];
int find(int x){
    int l=1,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(mon[mid]<=x) l=mid;
        else r=mid-1;
    }
    return l;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mon[i];
    }
    sort(mon+1,mon+n+1);
    for(int i=1;i<=n;i++){
        int t=1;
        if(find(mon[i])>=n){
            break;
        }
        else{
            while(attak[find(mon[i])+t]){
                t++;
            }
            if(find(mon[i])+t>n) break;
            die[i]=1;
            attak[find(mon[i])+t]=1;
        }
    }
    int sum=n;
    for(int i=1;i<=n;i++){
        if(die[i])sum--;
    }
    cout<<sum;
    return 0;
}
