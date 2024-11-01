#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int k,p;
long long a[10005][20005];
long long pp(int r,int li,int y){
    if(r == 0){
        if(li == 1){
            return 1;
        }else{
            return 0;
        }
    }
    for(int i = 1;i <=n;i++){
        if(i != y){
            for(int j = 1;j <= a[i][0];j++){
                if(a[i][j] == li){
                    for(int t = 1;t <k;t++){
                        if(j > t){
                            if(pp(r-1,a[i][j-t],i)) return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;

}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n >>k >> p;
        for(int i = 1;i <=n;i++){
            int l;
            cin >> l;
            a[i][0] = l;
            for(int j = 1;j <= l;j++){
                cin >> a[i][j];
            }
        }
        int uf = 0;
        while (p--){
            int rt,lt;
            cin >>rt >>lt;
            if(pp(rt,lt,-1)){
                cout <<1 <<endl;
            }else{
                cout << 0 <<endl;
            }

        }

    }
    return 0;
}
