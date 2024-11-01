#include<bits/stdc++.h>
using namespace std;
int n,ans,len;
vector<int> a;
vector<int> b;
int tong[100005];
int qzh[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    ans=0;len=n;
    //cout << len << endl;
    int maxn=-1;
    for (int i=1;i<=n;i++){
        int x;
        cin >> x;
        maxn=max(x,maxn);
        a.push_back(x);
    }
    //cout << maxn << " ";
    sort(a.begin(),a.end());
    int tot=0;
    b.push_back(a[0]);
    for (int i=0;i<n;i++){
        if (a[i]!=b.back()) b.push_back(a[i]);
        tong[a[i]]++;
    }
    for (int i=1;i<=maxn;i++){
        qzh[i]=tong[i]+qzh[i-1];
        //cout << qzh[i] << " ";
    }
    len-=tong[b[0]];
    for (int i=0;i<b.size();i++){
        len=min(n-qzh[b[i]],len);
        if (tong[b[i]] < len){
           len -= tong[b[i]];
           tong[b[i]]=0;
        }
        else{
            tong[b[i]]-=len;
            len=0;
        }
    }
    for (int i=1;i<=maxn;i++){
        ans+=tong[i];
    }
    cout << ans;
    return 0;
}