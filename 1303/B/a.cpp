#include <stdio.h>

using namespace std;

int nt;

int main() {
    scanf("%d", &nt);
    for ( int t = 1; t <= nt; t++ ) {
        int n, g, b;
        scanf("%d%d%d", &n, &g, &b);
        int r = n/2 + n%2;
        int f = r/g;
        long long ans = f*(long long)(g+b) + r%g;
        if (r%g == 0 )
i            ans -= b;
        if ( ans < n )
            ans = n;
        printf("%lld\n", ans);
    }
    return 0;
}

