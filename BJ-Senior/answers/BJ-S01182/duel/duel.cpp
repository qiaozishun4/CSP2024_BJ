#include<iostream>
using namespace std;
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    int r[n];
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(r[i]>=r[j]){
                int t=r[i];
                r[i]=r[j];
                r[j]=t;
            }
        }
    }
    int m=r[0],cnt=0;
    for(int i=0;i<n;i++){
        if(m==r[i]) cnt++;
        else{
            cout<<n-cnt;
            return 0;
        }

    }

    return 0;
}
