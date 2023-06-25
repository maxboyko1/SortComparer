#include "randomnumbers.hpp"

/**
 * Program that generates and prints to standard output a specified amount of
 * randomly-generated long integers, or 1000 of them by default.
 */
int main (int argc, char *argv[]) {
    if (argc < 0 || argc > 2) {
        cerr << "USAGE: ./randomnumbers [<count>]" << endl;
        return 1;
    }

    long long count = (argc == 1) ? 1000 : atoll(argv[1]);
    if (count <= 0) {
        cerr << "ERROR: argument must be a valid positive number" << endl;
        return 1;
    }

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long> distribution(numeric_limits<long>::min());

    cout << distribution(generator);
    while (--count)
        cout << " " << distribution(generator);
    cout << endl;

    return 0;
}
