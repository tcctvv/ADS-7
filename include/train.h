// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };

    Car* first;
    int   size;
    long  countOp;

public:
    Train();
    ~Train();

    void addCar(bool light);
    int  getLength();
    long getOpCount() const;
};

#endif  // INCLUDE_TRAIN_H_
