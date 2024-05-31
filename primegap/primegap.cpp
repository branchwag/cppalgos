#include <utility>
#include <cmath>

class GapInPrimes {
    public:
    static std::pair<long long, long long> gap(int g, long long m, long long n) {
        long long previous_prime = -1;
        for (long long i =m; i <=n; ++i){
            if (is_prime(i)) {
                if (previous_prime != -1 && i - previous_prime == g){
                    return std::make_pair(previous_prime, i);
                }
                previous_prime = i;
            }
        }
    return std::make_pair(0,0);
    }


private:
    static bool is_prime(long long num) {
        if (num <= 1) return false;
        if (num <=3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;

        for (long long i=5; i * i <= num; i +=6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }

        return true;
    }
};