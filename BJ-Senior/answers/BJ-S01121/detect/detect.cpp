#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d,v,a,p;
queue<int> q;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V,cnt=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d,&v,&a);
            if(v>V){
                q.push(d);
                cnt++;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p);
        }
        while(!q.empty()){
            if(q.front()>p) cnt--;
            q.pop();
        }
        if(cnt==0) m++;
        cout<<cnt<<' '<<m-1<<endl;
    }
    return 0;
}
