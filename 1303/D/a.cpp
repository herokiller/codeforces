#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 100

using namespace std;

void solve(long long n, int m, int a[]) {
    bool b[N];
    memset(b, 0, sizeof(b));
    int p = 0;
    while ( n > 0 ) {
        if ( n%2 != 0 )
            b[p] = 1;
           
        p++;
        n /= 2;
    }

    bool ok;
    int ans = 0;
    
    for ( int i = 0; i <= 60; i++ ) {
        if ( b[i] ) {
            if ( a[i] > 0 ) {
                a[i]--;
            } else {
                ok = 0;
                int p = 0;
                for ( int j = i+1; j <= 60; j++ ) {
                    if ( a[j] > 0 ) {
                        p = j;
                        ok = 1;
                        break;
                    }
                }

                if (!ok) {
                    printf("-1\n");
                    return;
                }

                for ( int j = i+1; j <= p-1; j++ )
                    a[j] = 1;
                a[p]--;
                ans += p - i;
            }
        }

        a[i+1] += a[i]/2;
    }

    printf("%d\n", ans);
    return;
}

int main() {
    int nt;
    scanf("%d", &nt);
    for ( int t = 1; t <= nt; t++ ) {
        long long n;
        int m, x, a[N];
        memset(a, 0, sizeof(a));
        scanf("%lld%d", &n, &m);
        for ( int i = 1; i <= m; i++ ) {
            scanf("%d", &x);
            for ( int j = 0; j <= 30; j++ )
                if (( x & ( 1 << j )) > 0 ) {
                    a[j]++;
                    break;
                }
        }

        solve(n, m, a);
    }
    return 0;
}

