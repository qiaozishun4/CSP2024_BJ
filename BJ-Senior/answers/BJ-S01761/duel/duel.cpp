#include <iostream>
using namespace std;
const int MAX=30;
int a[MAX+1];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0,minn=1000;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1]){
            a[i+1]=0;
            cnt++;
        }
        if(cnt<minn){
            minn=cnt;
        }
    }
    cout<<minn;
    return 0;
}
