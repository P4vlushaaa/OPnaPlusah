#include "Pair.h"

template<class Type>
Type Pair::findMin(Type a, Type b) {
    if (a < b) return a;
    return b;
}