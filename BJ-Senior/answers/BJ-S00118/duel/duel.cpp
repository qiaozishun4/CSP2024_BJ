#include<iostream>
using namespace std;
int r[100001];
int qsort(int l,int ri){
    int i=l,j=ri,x;
    int mid=r[(i+j)/2];
    do{
        while(r[i]<mid) i++;
        while(r[j]>mid) j--;
        if(i<=j){
            x=r[i];
            r[i]=r[j];
            r[j]=x;
            i++;j--;
        }
    }while(i<=j);
    if(l<j) qsort(l,j);
    if(i<ri) qsort(i,ri);
    return 0;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,i=0,j=1,ans;
    cin>>n;ans=n;
    for(i=0;i<n;i++){
        cin>>r[i];
    }
    qsort(0,n-1);
    i=0;
    while(j<n){
        if(r[j]>r[i]){
            i++;
            ans--;
        }
        j++;
    }
    cout<<ans<<endl;
    return 0;
}
