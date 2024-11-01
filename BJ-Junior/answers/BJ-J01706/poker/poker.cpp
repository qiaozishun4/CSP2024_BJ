#include <iostream>
#include <cstdio>
#include <set>
using namespace std;//dchs

/* int f1(char c) {
    if (c == 'D'){
        return 1;
    } else if (c == 'C') {
        return 2;
    } else if (c == 'H') {
        return 3;
    } else if (c == 'S') {
        return 4;
    }
}

int f2(char c) {
    switch (c) {
        case 'A':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
    }
} */

int main(int argc, char const *argv[]) {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    //
    int n;
    set<string> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        a.insert(str);
    }
    cout << 52 - a.size();
    //
    fclose(stdin);
    fclose(stdout);
    return 0;
}
