#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 222

using namespace std;

int nt;

struct key {
    int l, r;
    char letter;
};

key a[N];

void solve(string s) {
    bool b[N];
    memset(b, 0, sizeof(b));

    int size = 1, p = 1;
    a[1].letter = s[0];
    a[1].l = 0;
    a[1].r = 0;
    b[(int)s[0]] = 1;

    for ( int i = 1; i < s.length(); i++ ) {
        int pl = a[p].l;
        if (( pl != 0 ) && ( a[pl].letter == s[i] )) {
            p = pl;
            continue;
        }

        int pr = a[p].r;
        if (( pr != 0 ) && ( a[pr].letter == s[i] )) {
            p = pr;
            continue;
        }

        if ( b[(int)s[i]] ) {
            printf("NO\n");
            return;
        }

        if ( pl == 0 ) {
            b[(int)s[i]] = 1;
            size++;
            a[p].l = size;
            a[size].letter = s[i];
            a[size].l = 0;
            a[size].r = p;
            p = size;
            continue;
        }

        if ( pr == 0 ) {
            b[(int)s[i]] = 1;
            size++;
            a[p].r = size;
            a[size].letter = s[i];
            a[size].l = p;
            a[size].r = 0;
            p = size;
            continue;
        }

        printf("NO\n");
        return;
    }

    printf("YES\n");

    for ( int i = 1; i <= size; i++ )
        if ( a[i].l == 0 ) {
            p = i;
            break;
        }

    while ( p > 0 ) {
        printf("%c", a[p].letter);
        p = a[p].r;
    }

    for ( int i = (int)('a'); i <= (int)('z'); i++ )
        if ( !b[i] )
            printf("%c", (char)i);

    printf("\n");

    return;
}

int main() {
    scanf("%d\n", &nt);
    for ( int t = 1; t <= nt; t++ ) {
        string s;
        getline(cin, s);
        solve(s);        
    }

    return 0;
}

