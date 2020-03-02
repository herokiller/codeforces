#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int nt;
    scanf("%d\n", &nt);
    for ( int t = 1; t <= nt; t++ ) {
        string s;
        getline(cin, s);
        int n = s.length(), ans = 0;
        
        for ( int i = 0; i < n; i++ ) {
            if ( s[i] == '0' ) 
                ans++;
        }

        for ( int i = 0; i < n; i++ ) {
            if ( s[i] == '0' ) 
                ans--;
            if ( s[i] == '1' ) 
                break;
        }

        for ( int i = n-1; i >= 0; i-- ) {
            if ( s[i] == '0' ) 
                ans--;
            if ( s[i] == '1' ) 
                break;
        }

        if ( ans <= 0 )
            ans = 0;

        printf("%d\n", ans);
    }
    return 0;
}

