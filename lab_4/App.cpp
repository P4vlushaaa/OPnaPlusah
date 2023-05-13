#include "App.hh"
#include "hexagon.hh"
#include "circle.hh"

#define hex 1

int app::start() {
    std::cout << "input number of figures:\n";
    int number;
    std::cin >> number;
    for (int i = 0; i < number; i++) {
        initFromDialog();
    }
    return 0;
}

void app::add(IGeoFig *figure) {
    arr.push_back(figure);
}

void app::initFromDialog() {
    int input;
    float mass[4]{};
    std::cout << "input coordinates:\na_x=";
    std::cin >> mass[0];
    std::cout << "\na_y=";
    std::cin >> mass[1];
    std::cout << "\nb_x=";
    std::cin >> mass[2];
    std::cout << "\nb_y=";
    std::cin >> mass[3];
    std::cout << "choose figure:\n1.hexagon\n2.circle\n";
    std::cin >> input;
    if (input == hex) {
        arr.push_back(new figure::hexagon(mass[0], mass[1], mass[2], mass[3]));
    } else {
        arr.push_back(new figure::circle(mass[0], mass[1], mass[2], mass[3]));
    }
}
