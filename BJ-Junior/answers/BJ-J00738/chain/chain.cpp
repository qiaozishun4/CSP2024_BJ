#include<iostream>
using namespace std;
int main(){
    int T,n,k,q,l,R[],C[],ro,pe,a,W;
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    for (int i = 0 ; i <T ; i ++){
        cin >> n >>k >>q;
        int S[200000][200000] = {};
        for (int j = 0 ; j <n ;j++){
            cin >> l;
            for (int h = 0 ; h <l ;h++){
                cin >> S[j][h];
            }
        }
        for (int j = 0 ; j < q ; j ++){
            cin >> R[j] >>C[j];
        }
        for (int j = 0 ; j <n ; j ++){
                ro = 1 ;
                pe = 0;
                a =1 ;
                int o0;
                int count = 0;
                for (int o = 0 ; o < l ; o ++){
                    for (int p = 0 ; p < S[o].size();p ++){
                    o0 = o;
                        if S[o][p] == ro{
                            for (int s = 2 ; s <= k ; s ++){
                                ro = s;
                                for (int b = 0 ; b <l;b++){
                                    if (b == o) continue;
                                    else(){
                                        for (int d = 0 ; d < S[b].size();p++){
                                            if (S[b][d] == S[o][p+ro]){
                                                o = b;
                                                p = d;
                                                break;
                                                count ++;
                                                W = S[b][d];
                                            }
                                        }
                                    }
                                    if (o0 != o)break;
                                }
                                if (o0 != o)break;
                            }
                            
                        }
                    }
                    if (count == R[j] && W == C[j]){
                        cout << 1;
                    }else{
                    cout <<0;
                    }
                }
            }
        }
    }
    return 0;
}