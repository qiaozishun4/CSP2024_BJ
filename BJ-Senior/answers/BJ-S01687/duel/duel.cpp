#include <iostream>
using namespace std;
int n,i,j,a[100010],t,sum,f[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sum=n;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
   }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[j]>a[i]&&f[j]==false){
                a[i]=-1;
                f[j]=true;
                sum--;
                break;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
