#include <iostream>
using namespace std;

int n;
int r[100010];
int ssf[100010];
int sortres[100010][2],ind;
int sumkill,small;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> r[i];
        ssf[r[i]]++;
    }
    for (int i = 1;i <= 100000;i++){
        if (ssf[i]){
            ind++;
            sortres[ind][0] = i;
            sortres[ind][1] = ssf[i];
        }
    }
    small = sortres[1][1];
    for (int i = 2;i <= ind;i++){
        sumkill += min(sortres[i][1],small);
        small -= min(sortres[i][1],small);
        small += sortres[i][1];
    }
    cout << n - sumkill;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
