// RelativelyPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//bool factor(int n);
bool factor(int n, int t);
void listRelPrimes(int n);
void listRelPrimes(int n, int m);
bool checkIfRelPrime(int n, int m);

int main()
{
    std::cout << "Enter any number\n";
    //factor(13);
    //std::cout << checkIfRelPrime(12, 12);
    int n;
    std::cin >> n;
    std::cout << "\nList of numbers relatively prime to " << n << ":\n";
    listRelPrimes(n);
    //std::cout << factor(12, 5);
}

//bool factor(int n) {
//    int t = n - 1;
//    if (t >= 1) {
//        if (n % t == 0)
//            return true;
//        t--;
//        factor(n, t);
//    }
//    return false;
//}

bool factor(int n, int m) {
    int lar = n, small = m;
    if (small > lar) {
        int temp = lar;
        lar = small;
        small = temp;
    }

    for (int i = 2; i < lar; i++) {
        if ((lar % i == 0) && (small % i == 0))
            return true;
    }

    return false;
}

void listRelPrimes(int n) {
    int t = n - 1;
    if (t > 1) {
        listRelPrimes(n, t);
    }
    std::cout << "1.\n\n";
}

void listRelPrimes(int n, int m) {
    if (m <= 1) {
        return;
    }
    else {
        if (checkIfRelPrime(n, m)) {
            std::cout << m << ", ";
        }
        m--;
        listRelPrimes(n, m);
    }
}

bool checkIfRelPrime(int n, int m) {
    //need to determine highest num to factor correctly
    int lar = n, small = m;
    if (small > lar) {
        int temp = lar;
        lar = small;
        small = temp;
    }

    if (small > 1) {
        if (factor(lar,small))
            return false;
        else {
            small--;
            checkIfRelPrime(lar, small);
        }
    }

    return true;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
