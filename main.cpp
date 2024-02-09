#include <iostream>
#include <cmath>
#include <gmpxx.h>
#include <chrono>

// test

using namespace std;

int main()
{
    unsigned long int p;

    while (true) {
        cout << "\nCheck a Mersenne number M_p = 2^p - 1 for primality." << endl;
        cout << "p = ";
        if ((cin >> p)&&(p>1)) {

            auto start_time = chrono::high_resolution_clock::now();
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

            if (mpz_cmp_ui(k, 0)==0) {
                cout << "\nM_" << p << " is prime." << endl;
            }
            else {
                cout << "\nM_" << p << " is composite." << endl;
            }
            mpz_clear(k);
            mpz_clear(Mp);

            auto end_time = chrono::high_resolution_clock::now();
            auto time = end_time-start_time;

            cout << "\nVerified in ";
            if (chrono::duration_cast<chrono::hours>(time).count()>0) {
                cout << chrono::duration_cast<chrono::minutes>(time).count() << " minutes.\n";
            }
            else if (chrono::duration_cast<chrono::minutes>(time).count()>0) {
                cout << chrono::duration_cast<chrono::seconds>(time).count() << " seconds.\n";
            }
            else if (chrono::duration_cast<chrono::seconds>(time).count()>0) {
                cout << chrono::duration_cast<chrono::milliseconds>(time).count() << " milliseconds.\n";
            }
            else if (chrono::duration_cast<chrono::milliseconds>(time).count()>0) {
                cout << chrono::duration_cast<chrono::milliseconds>(time).count() << " milliseconds.\n" << endl;
            }
            else if (chrono::duration_cast<chrono::microseconds>(time).count()>0) {
                cout << chrono::duration_cast<chrono::microseconds>(time).count() << " microseconds.\n" << endl;
            }

        }
        else {
            cout << "\np must be a natural number greater than 1." << endl;
        }
    }

    return 0;
}