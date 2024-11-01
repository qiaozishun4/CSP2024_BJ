#include <bits/stdc++.h>

using namespace std;
struct car{
    int d;
    int v;
    int a;
}c[100000];
int ro[100000];
int n,m,l,v;
bool over(int i,int l0){
    if(l0<c[i].d)return 0;
    return (c[i].v*c[i].v+2*c[i].a*(l0-c[i].d))>v*v;
}
void solve0(){
    int ans0=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(over(i,ro[j])){
                ans0++;
                break;
            }
        }
    }

    int ans1=0;
    for(int i=0;i<(1<<m);i++){
        int s=0;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                if((i&(1<<j))&&over(k,ro[j])){
                    s++;
                    break;
                }
            }
        }
        if(s==ans0){
            int mi=0;
            for(int j=0;j<m;j++){
                if(!(i&(1<<j)))mi++;
            }
            ans1=max(ans1,mi);

        }
    }

    cout<<ans0<<' '<<ans1;
}

void solve1(){
    int ans0=0,ro0=0;
    for(int i=0;i<m;i++){
        ro0=max(ro0,ro[i]);
    }

    for(int i=0;i<n;i++){
        if(over(i,ro0))ans0++;
    }

    int ans1;
    if(ans0>0)ans1=m-1;
    else ans1=m;

    cout<<ans0<<' '<<ans1;
}
bool b1(car a,car b){return a.d<b.d;}
int next0[100001][2];
void del(int i){
    if(next0[i][0]!=-1)next0[next0[i][0]][1]=next0[i][1];
    if(next0[i][1]!=-1)next0[next0[i][1]][0]=next0[i][0];
}
void solve2(){
    sort(ro,ro+m);
    sort(c,c+n,b1);

    for(int i=0;i<=n;i++){
        next0[i][0]=i-1;
        next0[i][1]=i+1;
    }
    next0[n][1]=-1;
    int ans0=0;
    for(int i=0;i<n;i++){
        if(c[i].d<=ro[m-1]&&over(i,*lower_bound(ro,ro+m,c[i].d))){
            ans0++;
        }else{
            del(i);
        }
    }


    int ans1=m;
    for(int i=next0[n][0];i!=-1;i=next0[i][0]){
        int x0=*lower_bound(ro,ro+m,c[i].d);
        for(int j=next0[i][0];j!=-1;j=next0[j][0]){
            if(over(j,x0)){
                del(j);
            }else break;
        }
        ans1--;
    }
    cout<<ans0<<' '<<ans1;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){

        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=0;i<m;i++){
            cin>>ro[i];
        }
        if(n<=20&&m<=20)solve0();
        else if(c[0].a>=0)solve1();
        else if(c[0].a<0)solve2();
        cout<<endl;
    }



    fclose(stdin);
    fclose(stdout);
    return 0;
}
