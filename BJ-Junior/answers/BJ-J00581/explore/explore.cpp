#include<bits/stdc++.h>
using namespace std;

int t;
vector<int> n;
vector<int> m;
vector<int> k;
vector<int> x;
vector<int> y;
vector<int> d;
vector<vector<vector<int>>> Map;
vector<vector<int>>mtd;
vector<int> mt;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >>t;

    for(int i = 0; i<t;i++){
        int temp;
        cin >> temp;
        n.push_back(temp);
        cin >> temp;
        m.push_back(temp);
        cin >> temp;
        k.push_back(temp);
        cin >> temp;
        x.push_back(temp-1);
        cin >> temp;
        y.push_back(temp-1);
        cin >> temp;
        d.push_back(temp);

        char tempc;
        for(int w = 0;w<n[i];w++){
            for(int j = 0;j<m[i];j++){
                cin >>tempc;
                if(tempc=='x'){
                    mt.push_back(2);
                }else{
                    mt.push_back(0);
                }


            }
            mtd.push_back(mt);
            mt.clear();
        }
        Map.push_back(mtd);
        mtd.clear();

    }

    for(int i = 0; i < t; i++){
        int nn = n[i];
        int nm = m[i];
        int nk = k[i];
        int nx = x[i];
        int ny = y[i];
        int nd = d[i];
        while(nk--){
            Map[i][nx][ny] = 1;
            if( (nx+dx[nd]) >=0 && (nx+dx[nd]) < nn && (ny+dy[nd]) >= 0 && (ny+dy[nd]) < nm ){
                if(Map[i][nx+dx[nd]][ny+dy[nd]]!=2){
                    nx+=dx[nd];
                    ny+=dy[nd];

                    Map[i][nx][ny] = 1;
                }else{
                nd=(nd+1)%4;

            }
            }else{
                nd=(nd+1)%4;

            }




        }
    }

    for(int i = 0;i<t;i++){
        int cnt = 0;
        for(int j = 0;j<n[i];j++){
            for(int p = 0;p<m[i];p++){
                if(Map[i][j][p] == 1){
                    cnt++;
                }
            }
        }
        cout <<cnt<<endl;
    }

    return 0;
}
