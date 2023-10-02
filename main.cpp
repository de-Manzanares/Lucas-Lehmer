#include <iostream>
#include <cmath>
#include <gmpxx.h>
#include <chrono>

using namespace std;

int main()
{
    unsigned long int p;

    // while (true) {
    // cout << "\nCheck a Mersenne number M_p = 2^p - 1 for primality." << endl;
    // cout << "p = ";
    // if ((cin >> p)&&(p>1)) {

    int const mk = 28;
    int const tk = 5;

    int test_mp[mk] = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607,
            1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701,
            23209, 44497, 86243};//, 110503, 132049, 216091};
    int results_Method_1[mk][tk] = {0};
    int results_Method_2[mk][tk] = {0};

    for (int i = 0; i<mk; i++) {
        for (int j = 0; j<tk; j++) {

            auto start_time = chrono::high_resolution_clock::now();

            p = test_mp[i];

            mpz_t k;
            mpz_t Mp;
            int count = 1;
            unsigned long int limit = p-2;
            mpz_init_set_ui(k, 4);
            mpz_init(Mp);
            mpz_ui_pow_ui(Mp, 2, p);
            mpz_sub_ui(Mp, Mp, 1);

            cout << "\nu(0) = 4\n" << endl;

            do {

                cout << "u(" << count << ") = (" << k << " ^ 2 - 2) % M_" << p;
                cout << " = ";

                mpz_mul(k, k, k);
                mpz_sub_ui(k, k, 2);
                mpz_mod(k, k, Mp);

                gmp_printf("%Zd", k);
                cout << endl << "\n";

                count++;
            }
            while (count<=limit);

            auto end_time = chrono::high_resolution_clock::now();
            auto time = end_time-start_time;

            results_Method_1[i][j] = static_cast<int>(chrono::duration_cast<chrono::microseconds>(time).count());

            // if (mpz_cmp_ui(k, 0)==0) {
            //     cout << "\nM_" << p << " is prime." << endl;
            // }
            // else {
            //     cout << "\nM_" << p << " is composite." << endl;
            // }
            mpz_clear(k);
            mpz_clear(Mp);

            // cout << "\nVerified in ";
            // if (chrono::duration_cast<chrono::hours>(time).count()>0) {
            //     cout << chrono::duration_cast<chrono::milliseconds>(time).count() << " milliseconds.\n";
            // }
            // else if (chrono::duration_cast<chrono::minutes>(time).count()>0) {
            //     cout << chrono::duration_cast<chrono::milliseconds>(time).count() << " milliseconds.\n";
            // }
            // else if (chrono::duration_cast<chrono::seconds>(time).count()>0) {
            //     cout << chrono::duration_cast<chrono::milliseconds>(time).count() << " milliseconds.\n";
            // }
            // else if (chrono::duration_cast<chrono::milliseconds>(time).count()>0) {
            //     cout << chrono::duration_cast<chrono::milliseconds>(time).count() << " milliseconds.\n" << endl;
            // }
            // else if (chrono::duration_cast<chrono::microseconds>(time).count()>0) {
            //     cout << chrono::duration_cast<chrono::microseconds>(time).count() << " microseconds.\n" << endl;
            // }

            //     }
            //     else {
            //         cout << "\np must be a natural number greater than 1." << endl;
            //     }


        }
    }

    for (int i=0; i<mk; i++) {
        for (int j=0; j<tk; j++){

        }
    }
    for (int i = 0; i<mk; i++) {
        for (int j = 0; j<tk; j++) {
            cout << "\t" << results_Method_1[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i<mk; i++) {
        for (int j = 0; j<tk; j++) {
            cout << "\t" << results_Method_2[i][j];
        }
        cout << endl;
    }
// }

    return 0;
}