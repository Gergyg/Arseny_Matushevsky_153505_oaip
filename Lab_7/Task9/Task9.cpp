#include <iostream>
unsigned int check_in();
int main()
{
    unsigned int k;
    std::cout << "Input the number: ";
    k = check_in();
    unsigned int n = floor(double(log(2 * k + 1) / log(3)));

    unsigned int three = 1;
    for (int i = 0; i < n - 1; i++) {
        three *= 3;
    }

    long long result = 0;
    while (k && three) {

        int t = k / three;
        int p = three-1;
        p = p / 2;
        if ( p > k % three) {
            result = result * 10 + k / three - 1;
            k = k % three + three;
        }
        else {

            result = result * 10 + k / three;

            k = k % three;
        }


    

    three = three / 3;
}


    std::cout << result<<'\n';
    
    
}


unsigned int check_in() {
    while (true) {
        unsigned int t;
        std::cin >> t;
        if (std::cin.fail() || t == 0) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nError, try again.\n";
        }
        else {
            std::cin.ignore(32768, '\n');
            return t;
        }
    }
}
