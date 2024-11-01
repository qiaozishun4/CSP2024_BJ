#include <bits/stdc++.h>
using namespace std;
int a[100050],b[100050][2],q[100050];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int xs=1;xs<=n;xs++){
        scanf("%d",&a[xs]);
    }
    sort(a+1,a+1+n);
    int num=0;
    for(int xs=1;xs<=n;xs++){
        if(a[xs]>b[num][0]){
            num++;
            b[num][0]=a[xs];
        }
        b[num][1]++;
    }
    for(int xs=1;xs<=num;xs++){
        q[xs]=q[xs-1]+b[xs-1][1];
        //cout<<q[xs]<<" ";
    }
    int ans=0;
    for(int xs=1;xs<=num;xs++){
        ans+=min(q[xs]-ans,b[xs][1]);
    }
    cout<<n-ans;
    return 0;
}
