#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long last=1,n,mst[100050],flast=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mst[i];
    }
    sort(mst+1,mst+n+1);
    bool d=0;
    for(int i=2;i<=n;i++){
        if(mst[i]==mst[i-1]){
            if(flast>=1&&d){
                d=1;
                flast--;
            }else{
                d=0;
                last++;
            }
        }else{
            d=1;
            flast=last-1;
        }
    }
    cout<<last;
}
