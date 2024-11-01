#include <bits/stdc++.h>
using namespace std;
map<int,pair<int,int>> direction;
vector<string> explore;
int t,n,m,k,x,y,d;
bool b[10010][10010];
vector<int> v;
bool is_legal(int x,int y,int op){
    int nx=x+direction[op].first,ny=y+direction[op].second;
    return nx>=1 && nx<=n && ny>=1 && ny<=m && explore[nx][ny]=='.';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    direction[0]=make_pair(0,1);
    direction[1]=make_pair(1,0);
    direction[2]=make_pair(0,-1);
    direction[3]=make_pair(-1,0);
    cin>>t;
    for (int i=1;i<=t;i++){
        explore.clear();
        explore.push_back("0");
        string s;
        memset(b,0,sizeof(b));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for (int i=1;i<=n;i++){
            cin>>s;
            s.insert(s.begin(),'0');
            explore.push_back(s);
        }
        b[x][y]=1;
        int cnt=1;
        for (int j=1;j<=k;j++){
            if (is_legal(x,y,d)){
                x=x+direction[d].first;
                y=y+direction[d].second;
//                cout<<x<<" "<<y<<" "<<d<<endl;
                if (!b[x][y]){
                    b[x][y]=1;
                    cnt++;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
//        cout<<cnt<<endl;
        v.push_back(cnt);
    }
    for (int i=0;i<v.size();i++){
        printf("%d",v[i]);
        if (i!=v.size()-1){
            printf("\n");
        }
    }
   fclose(stdin);
   fclose(stdout);
    return 0;
}