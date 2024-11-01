

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int _cc = 0;

int n, m, k, x, y, d;

int curx, cury, curd;

char _g[1009][1009];

bool hs[1009][1009];

int T;

void dfs(int nx, int ny, int nd) {
    int solox, soloy, solod;
    if (nd == 0) {
        solox = nx;
        soloy = ny + 1;
        if (_g[solox][soloy] == 'x' || solox > n || solox < 1 || soloy > m || soloy < 1) {
            nd = (nd + 1) % 4;
            curx = nx, cury = ny, curd = nd; 
            return ;
        }
        if (!hs[solox][soloy]) {
            _cc++;
            hs[solox][soloy] = 1;
        }
        
        curx = solox, cury = soloy, curd = nd;
    }else if (nd == 1) {
        solox = nx + 1;
        soloy = ny;
        if (_g[solox][soloy] == 'x' || solox > n || solox < 1 || soloy > m || soloy < 1) {
            nd = (nd + 1) % 4;
            curx = nx, cury = ny, curd = nd; 
            return ;
        }
        if (!hs[solox][soloy]) {
            _cc++;
            hs[solox][soloy] = 1;
        }
        
        curx = solox, cury = soloy, curd = nd;
    }else if (nd == 2) {
        solox = nx;
        soloy = ny - 1;
        if (_g[solox][soloy] == 'x' || solox > n || solox < 1 || soloy > m || soloy < 1) {
            nd = (nd + 1) % 4;
            curx = nx, cury = ny, curd = nd; 
            return ;
        }
        if (!hs[solox][soloy]) {
            _cc++;
            hs[solox][soloy]= 1;
        }
        curx = solox, cury = soloy, curd = nd;
    }else if (nd == 3) {
        solox = nx - 1;
        soloy = ny;
        if (_g[solox][soloy] == 'x' || solox > n || solox < 1 || soloy > m || soloy < 1) {
            nd = (nd + 1) % 4;
            curx = nx, cury = ny, curd = nd; 
            return ;
        }
        if (!hs[solox][soloy]) {
            _cc++;
            hs[solox][soloy] = 1;
        }
        curx = solox, cury = soloy, curd = nd;
    }
}
void ParseIn () {
    ifstream inFile("explore.in");
    ofstream outFile("explore.out");
    inFile >> T;
    for (int i = 0; i < T; i++) {
        inFile >> n >> m >> k;
        inFile >> x >> y >> d;
        for (int l = 1; l <= n; l++) {
            for (int p = 1; p <= m; p++) {
                inFile >> _g[l][p];
                
            }
        }
        curx = x, cury = y, curd = d;
        hs[curx][cury] = 1;
        for (int i = 0; i < k; i++) {
            dfs(curx, cury, curd);
        }
        //ofstream outFile("explore.out");
        outFile << _cc + 1 << endl;
       // outFile.close();
        _cc = 0;
        memset(hs, 0, sizeof(hs));
    }
    inFile.close();
    outFile.close();
}

int main () {
    ParseIn();
    //Core();
    return 0;
}
