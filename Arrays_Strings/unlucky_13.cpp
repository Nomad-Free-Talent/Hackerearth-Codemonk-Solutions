#include<bits/stdc++.h>
#include<vector>

#define MODULO 1000000009

using namespace std;

struct Matrix {
    vector <vector <long long>> val = vector <vector <long long>>(2, vector <long long>(2, 0));
    Matrix operator* (const Matrix& other) {
        Matrix res;
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 2; j ++)
                for (int k = 0; k < 2; k ++)
                    res.val[i][j] = (res.val[i][j] + val[i][k] * other.val[k][j]) % MODULO;
        return res;
    }
};

Matrix calcExponent(Matrix M, long long cnt) {
    Matrix res;
    res.val[0][0] = res.val[1][1] = 1;
    while (cnt) {
        if (cnt & 1) {
            res = res * M;
        }
        M = M * M;
        cnt >>= 1;
    }
    return res;
}

long long answer (long long Num ) {
    Matrix single;
    single.val[0][0] = 9; single.val[0][1] = 8;
    single.val[1][0] = 1; single.val[1][1] = 1;
    Matrix expo = calcExponent(single, Num);
    return (expo.val[0][0] + expo.val[1][0]) % MODULO;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        long long Num;
        cin >> Num;

        long long out_;
        out_ = answer(Num);
        cout << out_;
        cout << "\n";
    }
}
