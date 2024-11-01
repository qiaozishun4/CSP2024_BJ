#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int a[1000005];
    int b[1000005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    b[1]=b[0]=1;
    for(int i=2;i<=n;i++){
        if(a[i]<=a[i-1]){
            b[i]=b[i-1]+1;
        }else{
            b[i]=1;
        }

    }
    int cnt=-1;
    for(int i=1;i<=n;i++){
        cnt=max(cnt,b[i]);
    }
    cout<<cnt<<endl;
    return 0;
}
