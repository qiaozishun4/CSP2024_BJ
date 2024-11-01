#include<bits/stdc++.h>
using namespace std;
int a[100005],ji[100005];
bool b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0,minn=0;
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=1;j<=n;j++){
            if(j==i||b[j]==true){
                continue;
            }
            if(a[i]>a[j]){
                b[j]=true;
            }
        }
        for(int j=1;j<=n;j++){
            if(b[j]==true){
                sum++;
            }
        }
        minn=max(sum,minn);
    }
    cout<<minn;
    return 0;
}
