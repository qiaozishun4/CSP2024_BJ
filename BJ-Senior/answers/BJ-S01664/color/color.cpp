#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
int t;
int n;
int ans;
int vis[N];
int r[N][2];

struct node{
    int x,i;
}a[N],b[N];

int funl(int l){
    int maxl = 0,ansl = 0;
    if(vis[l+1] != 0){
        if(r[l][1] != -1){
            return r[l][1];
        }
        for(int i = l+2;i < a[l].i;i++){
            vis[i] = vis[l+1];
            if(a[i].x == a[i-1].x){
                ansl += a[i].x;
            }
        }
        vis[a[l].i] == vis[l];
        if(a[a[l].i-1].i != -1)
            maxl = max(maxl,funl(a[l].i-1));
        for(int i = a[l].i;i < n;i++){
            if(a[i].i != -1){
                maxl = max(maxl,funl(i));
            }
        }
        for(int i = l+2;i <= a[l].i;i++){
            vis[i] = 0;
        }
        r[l][1] = maxl+a[l].x+ansl;
        return r[l][1];
    }else{
        if(r[l][0] != -1){
            return r[l][0];
        }
        vis[l] = 1;
        for(int i = l+1;i < a[l].i;i++){
            vis[i] = 2;
            if(a[i].x == a[i-1].x){
                ansl += a[i].x;
            }
        }
        vis[a[l].i] = 1;
        if((a[l].i-1 != l) && (a[a[l].i-1].i != -1)){
            maxl = max(maxl,funl(a[l].i-1));
        }
        for(int i = a[l].i;i < n;i++){
            if(a[i].i != -1){
                maxl = max(maxl,funl(i));
            }
        }
        for(int i = l;i <= a[l].i;i++){
            vis[i] = 0;
        }
        r[l][0] = maxl+a[l].x+ansl;
        return r[l][0];
    }
}

bool cmp(node x,node y){
    if(x.x == y.x){
        return x.i < y.i;
    }
    return x.x < y.x;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;
        for(int i = 0;i < n;i++){
            r[i][0] = -1;
            r[i][1] = -1;
        }
        for(int i = n-1;i >= 0;i--){
            a[i].i = -1;
            cin>>a[i].x;
            b[i].i = i;
            b[i].x = a[i].x;
        }
        sort(b,b+n,cmp);
        for(int i = 1;i < n;i++){
            if(b[i].x == b[i-1].x){
                a[b[i-1].i].i = b[i].i;
            }
        }
        for(int i = 0;i < n;i++){
            if(a[i].i != -1){
                r[i][0] = funl(i);
                ans = max(ans,r[i][0]);
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}
