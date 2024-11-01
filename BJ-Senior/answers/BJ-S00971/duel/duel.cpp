#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int quicksort(int l,int r){
    if(l>=r){
        return 0;
    }
    int key=l,y=r;
    while(l<=r){
        while(l<=r && a[l]<=a[key] && l<y){
            l++;
        }
        while(l<=r && a[r]>a[key] && r>key){
            r--;
        }
        if(l<=r){
            int p=a[l];
            a[l]=a[r];
            a[r]=p;
            l++;
            r--;
        }
    }
    int p=a[key];
    a[key]=a[r];
    a[r]=p;
    quicksort(key,r);
    quicksort(r+1,y);
    return 0;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(1,n);
    int minnum=a[1];
    int point=2;
    int ans=n;
    for(int i=2;i<=n;i++){
        if(a[i]>minnum){
          ans--;
          minnum=a[point++];
        }
    }
    cout<<ans;
    return 0;
}