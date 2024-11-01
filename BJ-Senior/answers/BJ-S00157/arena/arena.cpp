#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n,m;
ll oria[100111];
ll c[100111];
ll a[100111];
bool d[800011];
struct o{
    ll num;
    ll v;
};
o tree[800011];
ll layer;
ll tmpx[4];
ll biglog[100111];
void inline ori(){
    memset(tree,0,sizeof(tree));
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
}
void inline seta(){
    for(int i=1;i<=n;i++){
        a[i]=(oria[i]^tmpx[i%4]);
    }
    for(int i=1;i<=n;i++){
        tree[(1<<layer)+i-1]={i,a[i]};
    }
}
void inline pushup(int h){
    if(h==0) return;
    //cout << h << endl;
    for(int j=0;j<=(1<<h)-1;j+=2){
        int num=(1<<h)+j, lun=layer-h+1;
        if(d[num/2]==false){
            if(tree[num].v>=lun){
                tree[num/2]=tree[num];
            } else {
                tree[num/2]=tree[num+1];
            }
        } else {
            if(tree[num+1].v>=lun){
                tree[num/2]=tree[num+1];
            } else {
                tree[num/2]=tree[num];
            }
        }
    }
    pushup(h-1);
}
void inline mian(){
    ll ans=0;
    ori();
    seta();
    pushup(layer);
    for(ll i=1;i<=m;i++){
        ans^=(i*tree[(1<<layer)/(1<<biglog[c[i]])].num);
    }
    cout << ans << endl;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	//cout << "qwq" << endl;//
    cin >> n >> m;
    biglog[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&oria[i]);
        biglog[i]=biglog[i/2]+1;
    }
    //cout << "qwq" << endl;//
    for(int i=0;(1<<i)<=n;i++){
        biglog[(1<<i)]--;
    }
    //cout << "qwq" << endl;//
    for(int i=1;i<=m;i++){
        //cout << "qwq" << endl;//
        scanf("%lld",&c[i]);
        //c[i]=2;//
    }
    //cout << "qwq" << endl;//
    layer=biglog[n];
    //cout << "qwq" << endl;//
    string s;
    for(int i=layer-1;i>=0;i--){
        cin >> s;
        int len=s.length();
        for(int j=0;j<len;j++){
            if(s[j]=='1'){
                d[(1<<i)+j]=true;
            }
        }
    }
    //cout << "qwq" << endl;//
    cin >> T;
    for(int i=1;i<=T;i++){
        for(int j=0;j<=3;j++){
            scanf("%lld",&tmpx[j]);
        }
        mian();
    }

    //cout << biglog[3] << ' ' << biglog[64] << endl;
	return 0;
}
