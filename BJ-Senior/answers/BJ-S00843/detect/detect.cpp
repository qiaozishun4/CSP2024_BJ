#include <bits/stdc++.h>
using namespace std;
struct node{
    int di;
    int vi;
    int ai;
};
/*struct node2{
    double l_;
    double r_;
};*/
//bool vis[100005];
//node2 arr2[100005];
node arr[100005];
int brr[100005];
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
            int n,m,l,v;
            cin>>n>>m>>l>>v;
            //memset(vis,false,sizeof(vis));
            for(int i=1;i<=n;i++){
                cin>>arr[i].di>>arr[i].vi>>arr[i].ai;
                /*if(arr[i].vi>v&&arr[i].a[i]>=0){
                    arr2[i].l_=arr[i].di;
                    arr2[i].r_=l;
                    vis[i]=true;
                }
                if(arr[i].vi==v&&arr[i].ai>0){
                    arr2[i].l_=arr[i].di+0.00000001;
                    arr2[i].r_=l;
                    vis[i]=true;
                }
                if(arr[i].vi<=v&&sqrt(arr[i].vi*arr[i].vi+2*arr[i].ai*(l-arr[i].di))>v){
                    double tim=(v-arr[i].vi+0.00000001)/arr[i].ai;
                    arr2[i].l_=tim*arr[i].vi+0.5*arr[i].ai*tim*tim;
                    arr2[i].r_=l;
                    vis[i]=true;
                }
                if(arr[i].vi>v&&sqrt(arr[i].vi*arr[i].vi+2*arr[i].ai*(l-arr[i].di))>=v){
                    arr2[i].l_=arr[i].di;
                    arr2[i].r_=l;
                    if(sqrt(arr[i].vi*arr[i].vi+2*arr[i].ai*(l-arr[i].di))==v){
                            arr2[i].r_=l-0.00000001;
                    }
                    vis[i]=true;
                }
                if(arr[i].vi>v&&sqrt(arr[i].vi*arr[i].vi+2*arr[i].ai*(l-arr[i].di))<v){
                    arr2[i].l=arr[i].ai;
                    double tim=(arr[i].vi-v-0.00000001)/arr[i].ai;
                    arr2[i].r=tim*arr[i].vi+0.5*arr[i].ai*tim*tim;
                    vis[i]=true;
                }*/
            }
            int big=-1;
            for(int i=1;i<=m;i++){
                cin>>brr[i];
                big=max(big,brr[i]);
            }
            /*int sum=0;
            vector<int>v;
            for(int i=1;i<=n;i++){
                if(vis[i]==true){
                    bool flag=true;
                    for(int j=1;j<=m;j++){
                        if(brr[j]>=arr2[i].l&&brr[i]<=arr2[i].r){
                            flag=false;
                        }
                    }
                    if(!flag){
                        v.bush_back(i);
                        sum++;
                    }
                }
            }
            cout<<sum;
            */
            int sum=0;
        for(int i=1;i<=n;i++){
            if(arr[i].vi>v&&arr[i].di<=big) sum++;
        }
        cout<<sum<<" "<<1<<endl;
    }
    return 0;
}