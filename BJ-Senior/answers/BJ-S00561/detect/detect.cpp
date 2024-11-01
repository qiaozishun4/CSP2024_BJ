#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
struct node{
    int l,r;
}c[maxn];
int car[maxn][3];//d,v,a
int a[maxn];
bool cmp(node x,node y){
    return x.r>y.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n,m,l,v,cnt = 0,rel = 0;
        cin>>n>>m>>l>>v;
        for(int i = 1;i<=n;i++) cin>>car[i][0]>>car[i][1]>>car[i][2];
        for(int i = 1;i<=m;i++) cin>>a[i];
        for(int i = 1;i<=n;i++){
            bool flag = 0;
            for(int j = 1;j<=m;j++){
                if(car[i][0]<=a[j]){
                    float speed = sqrt(car[i][1]*car[i][1]+2*(a[j]-car[i][0])*car[i][2]);
                    //cout<<speed<<" ";
                    if(speed>v*1.0){
                        if(!flag){
                            flag = 1;
                            cnt++;
                            c[i].l = j;
                        }
                        c[i].r = j;
                    }
                }
            }
            cout<<endl;
        }
        sort(c+1,c+m+1,cmp);
        for(int i = 1;i<=m;i++){
            int k = c[i].l;
            while(k>=c[i].l && k<= c[i].r) i++;
            rel++;
        }
        cout<<cnt<<" "<<m-rel<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

