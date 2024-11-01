#include<iostream>
using namespace std;

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int timessss;
    cin >> timessss;

    for(int asdf = 0; asdf<timessss; asdf++){

        //START
        int n,m,l,v;
        cin >> n >> m >> l >> v;
        v= v*v;

        int start[n], velo[n], acc[n];
        int detectable[n];
        for(int i=0; i<n;i++){
            cin >> start[i] >> velo[i] >> acc[i];
            detectable[i] = 0;
        }
        int detectors[m];
        int acti[m];
        for(int i=0; i<m; i++){
            cin >> detectors[i];
            acti[i] = 0;
        }
        int amount = 0;

        int detgraph[n][m];
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                detgraph[i][j]=0;
            }
        }


        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(start[i] <= detectors[j]){
                    int veloatpoint = velo[i] * velo[i] + 2 * acc[i] * (detectors[j]-start[i]);
                    if(veloatpoint > v){
                        if(detectable[i] != 1){
                            detectable[i] = 1;
                            amount++;
                        }
                        detgraph[i][j] = 1;
                    }

                }
            }
        }
        cout << amount << " ";

        int det = 0;
        int ans = 0;
        int maxpot = 0;
        int bestdet = 0;
        while(det < amount){
            maxpot = 0;
            bestdet = -1;
            for(int j=0; j<m;j++){
                int pot = 0;
                if(acti[j]==0){
                    for(int i=0; i<n; i++){
                        if(detgraph[i][j] == 1){
                            pot ++;
                        }
                    }
                }
                if(pot > maxpot){
                    maxpot = pot;
                    bestdet = j;
                }
            }

            for(int i=0; i<n;i++){
                if(detgraph[i][bestdet] == 1){
                    for(int j=0; j<m;j++){
                        detgraph[i][j]=0;
                    }
                }
            }
            det += maxpot;
            acti[bestdet] = 1;
            ans++;
        }

        cout << m-ans << "\n";
        //END

    }


    return 0;
}
