#include <iostream>
#include "head.h"

int main() {


    int matrix[3][3] = {
            {1, 1, 1},
            {2, 2, 2},
            {3, 3, 3}
    };

    int x = 8;
    int y = 3;
    changeNumberL(x, y);
    std::cout << x << "\n" << y << "\n";

    double z = 4.5;
    reverseNumL(z);
    std::cout << z << "\n";

    double radius = 10;
    double raz = 7;
    changeRP(radius, raz);
    std::cout << radius << "\n";

    int first = 0;
    int second = 2;
    changeStrP(matrix, first, second);
    std::cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << "\n";
    std::cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << "\n";
    std::cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << "\n";
    return 0;
}

