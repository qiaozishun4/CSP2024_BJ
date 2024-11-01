#include <bits/stdc++.h>
using namespace std;
int T;
int n, m, L, V;
int d, v, a;
long long int s;
queue< int > q;
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d>>v>>a;
            if(a==0){
                if(v>V)q.push(d);
            }else {
                if(v>V)q.push(d);
                else q.push(d+(V*V-v*v)/(2*a)+1);
            }
        }
        long long int ans2;
        for(int i=1;i<=m;i++){
            cin>>s;
            ans2=max(ans2,s);
        }
        long long int ans1=0;
        while(!q.empty()){
            if(q.front()<=ans2)ans1++;
            q.pop();
        }
        if(ans1)cout<<ans1<<" "<<m-1<<"\n";
        else cout<<ans1<<" "<<m<<"\n";
        T--;
    }
    return 0;
}
