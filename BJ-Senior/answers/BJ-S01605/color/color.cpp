

#include <iostream>
#include <fstream>

using namespace std;
int a[29];
int n;
int x[29];
int soloscore = 0, ansscore = -2e9;
int T;
void one () {
    for (int i = 0; i < 2; i++) {
        a[n] = i;
        /*for (int m = 1; m <= n; m++) {
            cout << a[m] << " ";
        }*/
        //cout << endl;
        for (int m = 1; m <= n; m++) {
            for (int k = m - 1; k >= 1; k--) {
                //cout << m << " " << a[m] << " " << x[m] << "  sadfasdfasdf  " << k << " " << a[k] << " " << x[k] << endl;
                if (a[k] == a[m]) {
                    if (x[k] == x[m]) {
                        soloscore += x[m];
                        break;
                    }
                }

            }

        }
        ansscore = max(ansscore, soloscore);
        soloscore = 0;
    }
}
void two () {
    for (int i = 0; i < 2; i++) {
        a[n - 1] = i;
        one();
    }
}
void three () {
    for (int i = 0; i < 2; i++) {
        a[n - 2] = i;
        two();

    }
}
void four () {
    for (int i = 0; i < 2; i++) {
        a[n - 3] = i;
        three();

    }
}

void five () {
    for (int i = 0; i < 2; i++) {
        a[n - 4] = i;
        four();

    }
}
void six () {
    for (int i = 0; i < 2; i++) {
        a[n - 5] = i;
        five();
        
    }
}
void seven() {
    for (int i = 0; i < 2; i++) {
        a[n - 6] = i;
        six();

    }
}
void eight () {
    for (int i = 0; i < 2; i++) {
        a[n - 7] = i;
        seven();

    }
}
void nine () {
    for (int i = 0; i < 2; i++) {
        a[n - 8] = i;
        eight();

    }
}
void ten () {
    for (int i = 0; i < 2; i++) {
        a[n - 9] = i;
        nine();

    }
}
void eleven () {
    for (int i = 0; i < 2; i++) {
        a[n - 10] = i;
        ten();
    }
}

void twelve () {
    for (int i = 0; i < 2; i++) {
        a[n - 11] = i;
        eleven();        
    }
}
void thirteen () {
    for (int i = 0; i < 2; i++) {
        a[n - 12] = i;
        twelve();

    }
}
void fourteen () {
    for (int i = 0; i < 2; i++) {
        a[n - 13] = i;
        thirteen();

    }
}
void fifteen () {
    for (int i = 0; i < 2; i++) {
        a[n - 14] = i;
        fourteen();
    }
}
void ParseIn () {
    ifstream inFile("color.in");
    ofstream outFile("color.out");
    inFile >> T;
    for (int i = 1; i <= T; i++) {
        inFile >> n;
        for (int m = 1; m <= n; m++) {
            inFile >> x[m];

        }
        if (n == 1) {
            one();
        }
        if (n == 2) {
            two();

        }
        if (n == 3) {
            three();
        }
        if (n == 4) {
            four();
        }
        if (n == 5) {
            five();
        }
        if (n == 6) {
            six();
        }
        if (n == 7) {
            seven();
        }
        if (n == 8) {
            eight();
        }
        if (n == 9) {
            nine();
        }
        if (n == 10) {
            ten();
        }
        if (n == 11) {
            eleven();
        }
        if (n == 12) {
            twelve();
        }
        if (n == 13) {
            thirteen();
        }
        if (n == 14) {
            fourteen();
        }
        if (n == 15) {
            fifteen();
        }
        outFile << ansscore << endl;
        soloscore = 0;
        ansscore = -2e9;
    }
    inFile.close();
    outFile.close();
}

int main () {
    ParseIn();
    //Core();
    return 0;
}