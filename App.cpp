#include <iostream>
#include "App.h"

int App::start() {
    Queue<int> queue();
    try {
        queue().pop();
    }
    catch (QueueExceptions &e) {
        std::cerr << e.what() << std::endl;
    }
    queue().push(1);
    queue().push(2);
    queue().push(3);
    queue().sizeOf();
}