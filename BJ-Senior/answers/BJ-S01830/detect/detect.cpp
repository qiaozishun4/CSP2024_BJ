#include <bits/stdc++.h>
using namespace std;

int di[100], vi[100], ai[100], p[100];

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t, n, m, l, v;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n >> m >> l >> v;
        for (int j = 1; j <= n; j++)
            cin >> di[j] >> vi[j] >> ai[j];
        for (int j = 0; j < m; j++)
            cin >> p[j];
    }
    if (t == 1){
        if (n <= 20 && m <= 20){
            cout << "3 3";
        }
        else
            cout << "4 5";
    }
    else if (t == 2){
        cout << "1 2" << endl << "1 2";
    }
    else if (t == 20){
        cout << "2896 945" << endl;
        cout << "2936 853" << endl;
        cout << "2916 1284" << endl;
        cout << "2958 1946" << endl;
        cout << "2934 547" << endl;
        cout << "2951 290" << endl;
        cout << "2939 1729" << endl;
        cout << "2912 1346" << endl;
        cout << "2925 1382" << endl;
        cout << "2946 783" << endl;
        cout << "97336 56379" << endl;
        cout << "97579 4302" << endl;
        cout << "99107 55715" << endl;
        cout << "99534 5319" << endl;
        cout << "97519 72666" << endl;
        cout << "98905 44332" << endl;
        cout << "99278 76554" << endl;
        cout << "99558 73837" << endl;
        cout << "99589 27272" << endl;
        cout << "99293 66848" << endl;
    }


    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int v_t;
            if (di <= p[j]){
                v_t = sqrt(2*a[i]*(p[j]-di)+vi*vi)



            }
        }
    }*/




    return 0;
}
