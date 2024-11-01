#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int i=1,j=1,cnt=0;
    while(j<=n){
        if(a[j]>a[i]){
            i++;
            cnt++;
        }
        j++;
    }
    cout<<n-cnt;
    return 0;
}

//finish time: 14:43
//luogu uid 453759
//BJ-S01147
//qwqawa
//IAKIOI
