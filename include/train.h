// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <cstdint>

class Train {
private:
    struct Car {
        bool light{};
        Car* next{};
        Car* prev{};
    };

    Car*    first{nullptr};
    int     size{0};
    int64_t opCount{0};

    static void linkCars(Car* a, Car* b)
    { a->next = b;  b->prev = a; }

public:
    Train() = default;
    ~Train();

    void   addCar(bool light);
    int    getLength();
    int64_t getOpCount() const { return opCount; }
};

#endif  // INCLUDE_TRAIN_H_
