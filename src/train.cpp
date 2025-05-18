// Copyright 2021 NNTU-CS
#include "train.h"
#include <stdexcept>

Train::~Train()
{
    if (!first) return;
    Car* cur = first;
    for (int i = 0; i < size; ++i) {
        Car* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

void Train::addCar(bool light)
{
    Car* c = new Car{light};
    if (!first) {
        first = c;
        linkCars(c, c);
    } else {
        Car* tail = first->prev;
        linkCars(tail, c);
        linkCars(c, first);
    }
    ++size;
}

int Train::getLength()
{
    if (size < 2)
        throw std::logic_error("Train must consist of at least two cars.");

    bool allOff = true, allOn = true;
    for (Car* cur = first, *end = first; ; ) {
        allOff &= !cur->light;
        allOn  &=  cur->light;
        cur = cur->next;
        if (cur == end) break;
    }

    opCount = allOn ? int64_t(size) * int64_t(size + 1)
                    : int64_t(2) * size;

    return size;
}
