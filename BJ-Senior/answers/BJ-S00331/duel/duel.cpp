#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],n,cont,maincnt,point,maxn;
int cnt[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    for(int i=0;i<n;i++){
        b[a[i]]++;
    }
    //cout<<b[136]<<b[2417];
    for(int i=0;i<=maxn;i++){

        while(b[i]>0){
            a[cont]=i;
            b[i]--;
            cont++;
        }

    }
    //cout<<b[136]<<b[2417];
    //for(int i=0;i<n;i++){
    //    cout<<a[i]<<" ";
    //}
    for(int i=1;i<n;i++){
        if(a[i]>a[point]){
            point++;
            maincnt++;
        }
    }
    cout<<n-maincnt<<endl;

    return 0;
}
