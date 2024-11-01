#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
struct se{
    int x;
    int f;//0s 1e
    int h;
};
vector<se>vt;
int p[100005];
int sde[100005];
bool cmp(se a,se b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.f<b.f;
}
void cl(){
    cin>>n>>m>>L>>V;
    int cnt1=n,cnt2=0;
    vt.clear();
    for(int i=1;i<=n;i++){
        int d,v,a;
        cin>>d>>v>>a;

        se s,e;
        s.f=0,e.f=1;
        s.h=i,e.h=i;
        if(a==0){
            if(v<=V){
                cnt1--;
                continue;
            }else{
                s.x=d;
                e.x=L;
            }
        }else if(a>0){
            if(v>V){
                s.x=d;
                e.x=L;
            }else{
                int z=V*V-v*v,y=2*a;
                int k=z/y+1;//(z%y==0?z/y+1:z/y);
                if(k>L){
                    cnt1--;
                    continue;
                }else{
                    s.x=d+k;
                    e.x=L;
                }
            }
        }else{//a<0
            if(v<=V){
                cnt1--;
                continue;
            }else{
                int z=V*V-v*v,y=2*a;
                int k=(z%y==0?z/y-1:z/y);
                s.x=d;
                e.x=d+k;
            }
        }
        //cout<<i<<" "<<s.x<<" "<<e.x<<endl;
        sde[i]=s.x;
        vt.push_back(s);
        vt.push_back(e);

    }
    //cout<<cnt1<<endl;

    sort(vt.begin(),vt.end(),cmp);


    for(int i=1;i<=m;i++){
        cin>>p[i];
    }

    bool b[100005]={};
    //for(int i=0;i<vt.size();i++) cout<<vt[i].x<<" ";
    //cout<<endl;
    for(int i=0,j=1,k=0;i<vt.size();i++){
        if(vt[i].f!=1||b[vt[i].h]) continue;
        //e
        while(j<m&&p[j+1]<=vt[i].x) j++;
        if(sde[vt[i].h]<=p[j]&&p[j]<=vt[i].x){
            cnt2++;
            while(k<=i){
                b[vt[k].h]=1;
                k++;
            }
        }else{
            //cout<<i<<" "<<j<<endl;
            cnt1--;
        }
    }

    cout<<cnt1<<" "<<m-cnt2<<endl;

}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cl();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

