// Copyright 2021 NNTU-CS
#include "train.h"
#include <stdexcept>

Train::Train() : first(nullptr), size(0), COP(0) {}

Train::~Train() {
    if (!first) return;
    Car* cur = first;
    for (int i = 0; i < size; ++i) {
        Car* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

void Train::addCar(bool light) {
    Car* c = new Car{light, nullptr, nullptr};
    if (!first) {
        first = c;
        first->next = first->prev = first;
    } else {
        Car* tail = first->prev;
        tail->next = c;
        c->prev  = tail;
        c->next  = first;
        first->prev = c;
    }
    ++size;
}

int Train::getLength() {
    if (size < 2) throw std::logic_error("Train must have at least two cars");

    // наивный алгоритм
    Car* start = first;
    if (!start->light) start->light = true;

    Car* cur = start->next;
    ++COP;

    while (true) {
        if (!cur->light) {
            cur->light = true;
        } else if (cur == start) {
            break;
        }
        cur = cur->next;
        ++COP;
    }
    return COP;
}

long Train::getOpCount() const { return COP; }
