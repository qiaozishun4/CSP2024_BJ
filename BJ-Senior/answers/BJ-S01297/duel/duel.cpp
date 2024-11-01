#include<iostream>
#include<algorithm>
using namespace std;
int n,num,a[100005],b[100005],yi;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>2) f=0;
        if(a[i]==1) yi++;
    }
    if(f==1){
        cout<<n-yi<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(b[i]==0){
            int l=1,r=i-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(a[mid]<a[i]) l=mid+1;
                else r=mid-1;
            }
            if(l>1){
                a[l-1]=-1;
                b[l-1]=1;
                b[i]=1;
                for(int j=l-1;j>=2;j--){
                    swap(a[j],a[j-1]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            num++;
        }
    }
    cout<<num;
    return 0;
}
