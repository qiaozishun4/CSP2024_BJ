#include <bits/stdc++.h>
using namespace std;

int n,a[100005],t[100005],num[100005];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    int id = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        if(t[a[i]] == 1){
            id++;
            num[id] = a[i];
        }
    }
    sort(num+1,num+id+1);
    int ans = n;
    for(int i = 2;i<=id;i++){
        if(t[num[i]]>t[num[i-1]]){
            ans-=t[num[i-1]];
        }
        else{
            ans-=t[num[i]];
        }
    }
    cout<<ans;

    return 0;
}
