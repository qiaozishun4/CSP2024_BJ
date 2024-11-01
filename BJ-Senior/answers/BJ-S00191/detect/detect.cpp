

#include<bits/stdc++.h>

using namespace std;

struct node{
    int d,v,a;
};
int T,n,m,l,V;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>V;
        int ans=0;
        node lst[100005];
        int jc[100005];
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>lst[i].d>>lst[i].v>>lst[i].a;
        }
        for(int i=0;i<m;i++){
            cin>>jc[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sqrt(lst[i].v*lst[i].v+2*lst[i].a*jc[j])>V){
                    ans++;
                    if(lst[i].a<0){
                        s.insert(i);
                    }
                    break;

                }
            }
        }


        cout<<ans<<' '<<m-1-s.size()<<endl;
    }
    return 0;
}
