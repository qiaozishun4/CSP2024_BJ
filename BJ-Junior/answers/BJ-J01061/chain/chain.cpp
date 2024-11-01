#include<iostream>
#include<queue>
using namespace std;
int t,n,k,p,m[10001],a[200001],r,c;
struct node{
    int x,y,z;
};
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>p;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            m[i]=m[i-1]+x;
            for(int j=m[i-1]+1;j<=m[i];j++){
                cin>>a[j];
            }
        }
        while(p--){
            cin>>r>>c;
            queue<node> q;
            q.push({1,0,0});
            bool f=0;
            while(!q.empty()){
                node x=q.front();
                q.pop();
                if(x.y==r){
                    if(x.x==c){
                        cout<<1<<endl;
                        f=1;
                        break;
                    }
                    continue;
                }
                for(int i=1;i<=n;i++){
                    if(i==x.z){
                        continue;
                    }
                    for(int j=m[i-1]+1;j<=m[i];j++){
                        if(a[j]==x.x){
                            for(int l=j+1;l<=j+k-1&&l<=m[i];l++){
                                q.push({a[l],x.y+1,i});
                            }
                        }
                    }
                }
            }
            if(f==0){
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
