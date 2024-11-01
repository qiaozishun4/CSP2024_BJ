#include <bits/stdc++.h>
using namespace std;

struct Index {
    double sToV;
    int exceed;
    bool yes=0;
};


vector<Index> indexs;
int cams[100000];
vector<bool> opens;


int cam_need(double sToV_, int& cams_, int exceed_, int size_, int back_) {

    if (exceed_ == 1) {
        if (sToV_ > back_/2) {
            for (int h=size_-1; h>=0; h--)
                if (cams[h]>sToV_ && cams[h-1]<=sToV_)
                    return h;

        } else {
            for (int h=0; h<size_; h++)
                if (cams[h]<=sToV_ && cams[h+1]>sToV_)
                    return h+1;

        }

    } else if (exceed_ == 2) {
        if (sToV_ > back_/2) {
            for (int h=size_-1; h>=0; h--)
                if (cams[h]>=sToV_ && cams[h-1]<sToV_)
                    return h-1;

        } else {
            for (int h=0; h<size_; h++)
                if (cams[h]<sToV_ && cams[h+1]>=sToV_)
                    return h;

        }

    }

    //if (exceed_ == 1) {
        //for (int h=0; h<size_; h++) {
            //if (h>sToV_)
                //return h;
        //}
    //} else if (exceed_ == 2) {
        //for (int h=size_; h>=0; h--) {
            //if (h<sToV_)
                //return h;
        //}
    //}

}


int T;
int n, m, L, V;
int d, v, a;
int p;

int exceeds=0;
int cams_need=0;

int main() {

    freopen("detect1.in", "r", stdin);
    freopen("detect1.out", "w", stdout);


    cin >> T;
    for (int i=0; i<T; i++) {

        cin >> n >> m >> L >> V;
        for (int j=0; j<n; j++) {
            cin >> d >> v >> a;

            Index index;
            if (a != 0) {
                index.sToV = double(d) + double(pow(V,2)-pow(v,2))/(2*a);
            } else if (a==0 && v>=V){
                index.yes = 1;
            }
            if (a>0) {
                index.exceed = 1; //after v
            } else if (a<0) {
                index.exceed = 2; //before v
            } else {
                index.exceed = 0; //constant v0
            }
            indexs.push_back(index);

        }

        for (int j=0; j<m; j++) {
            cin >> cams[j];
        }

        sort(cams, cams+m-1);

        bool flag = 0;
        for (int j=0; j<indexs.size(); j++) {
            if ((indexs[j].sToV>=cams[0] && indexs[j].sToV<=cams[m-1] || indexs[j].yes)) {
                exceeds ++;

                if (indexs[j].yes)
                    flag = 1;
                else if (find(opens.begin(), opens.end(), cam_need(indexs[j].sToV, cams[0], indexs[j].exceed, m-1, cams[m-1])) != opens.end()) {
                    opens.push_back(cam_need(indexs[j].sToV, cams[0], indexs[j].exceed, m-1, cams[m-1]));
                    cams_need ++;
                }
            }
        }
        if (flag && cams_need==0)
            cams_need = 1;
    }

    cout << exceeds << ' ' << m-cams_need << endl;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
