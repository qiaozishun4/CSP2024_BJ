#include <bits/stdc++.h>
using namespace std;

int cmp(int x,int y){
    if(x<y)
        return true;
    else
        return false;
}

int main(){
    int n,i,j,a[100005]={0};
    int num;
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    num=n;
    sort(a,a+n,cmp);
    for(i=0,j=1;i<n,j<n;j++){
        if(a[i]<a[j]){
            num--;
            i++;
        }
    }
    cout<<num;
    return 0;
}