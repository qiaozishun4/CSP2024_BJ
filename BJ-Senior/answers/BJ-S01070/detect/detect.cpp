#include<bits/stdc++.h>
using namespace std;
int getsum(int l,int r){
    return (l+r)*(r-l+1)/2;
}
struct Car{
    int d,v,a;
};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        vector<Car>cars(n);
        vector<int>ce(m);
        vector<int>chafen(m);
        for(int i=0;i<n;i++){
            cin>>cars[i].d>>cars[i].v>>cars[i].a;
        }
        for(int i=0;i<m;i++)cin>>ce[i];
        int ret=0;
        for(int i=0;i<n;i++){
            if(cars[i].a>0){
                int spd=ceil((V-cars[i].v)/cars[i].a);
                int dis=cars[i].d+getsum(1,spd)*cars[i].a+spd*cars[i].v;
                int xb=lower_bound(ce.begin(),ce.end(),dis)-ce.begin();
                if(xb!=m){
                    ret++;
                    chafen[xb]++;
                }
            }
            else if(cars[i].a<0){
                if(cars[i].v<=V)continue;
                chafen[0]++;
                int spd=ceil((V-cars[i].v)/cars[i].a);
                int dis=cars[i].d+getsum(1,spd)*cars[i].a+spd*cars[i].v;
                int xb=lower_bound(ce.begin(),ce.end(),dis)-ce.begin();
                ret++;
                if(xb!=0){
                    chafen[xb]--;
                }
                else{
                    ret--;
                }
            }
            else{
                if(cars[i].v>V){
                    ret++;
                    chafen[0]++;
                }
            }
        }
        cout<<ret<<" ";
        int ret2=0,lin=0;
        for(int i=0;i<m;i++){
            lin+=chafen[i];
            if(lin==0){
                ret2++;
            }
        }
        cout<<ret2<<endl;
    }
    return 0;
}
//rp++++++++ pian 20-80 pts