#include <bits/stdc++.h>
#define LIM 10004
#define MOD1 1000000007
#define MOD2 1000000001

#define ll long long int

using namespace std;

int len1, len2;
char A[LIM], B[LIM];

int main() {
    scanf("%s %s", A, B);
    len1 = strlen(A);
    len2 = strlen(B);

    ll bp = 1, BP = 1;
    for(int i=1; i<len2; i++) {
        bp *= 26;
        BP *= 31;
    }

    ll h1 = 0, h2 = 0;
    ll H1 = 0, H2 = 0;

//    ///assume left endian
//    for(int i=0; i<len2; i++) {
//        h2 += B[i] * pow(26, len2-i-1);
//    }

    for(int i=0; i<len2; i++) {
        h2 = (h2*26 + B[i]) % MOD1;
        H2 = (H2*31 + B[i]) % MOD2;
    }
    cout << "h2 " << h2 << " " << H2 << endl;

    for(int i=0; i<len1; i++) {
        int p = i-len2;
        if(p >= 0) h1 -= A[p]*bp;
        if(p >= 0) H1 -= A[p]*BP;

        h1 = (h1*26 + A[i])%MOD1;
        H1 = (H1*31 + A[i])%MOD2;
        if(h1 < 0) h1 += MOD1;
        if(H1 < 0) H1 += MOD2;
        cout << "h1 " << h1 << " " << H1 << endl;

        if(i >= len2 && h1 == h2 && H1 == H2) {
            ///
            cout << "Found at " << p+1 << ":" << i << endl;
        }
    }

}



