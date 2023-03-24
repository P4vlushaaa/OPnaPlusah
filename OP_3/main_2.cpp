#include <iostream>
#include "Head_2.hh"
using namespace std;

int main() {

    int arr1[10] = { 1, 3, 1, 0, 1, 0, 1, 0, 1, 0 };
    int arr2[10] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

    Subset s1(arr1);
    Subset s2(arr2);

    Subset s3 = s1 + s2;
    s3.print();

    if (s1 == s2) {
        std::cout << "s1 is equal to s2" << std::endl;
    }
    else {
        std::cout << "s1 is not equal to s2" << std::endl;
    }

    if (s1 != s2) {
        std::cout << "s1 is not equal to s2" << std::endl;
    }
    else {
        std::cout << "s1 is equal to s2" << std::endl;
    }

    s1 += 5;
    s1.print();
    s2 -= 2;
    s2.print();

    return 0;
}