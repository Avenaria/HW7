#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Flat {
    double price_;
    double area_;
public:
    Flat() :price_(0), area_(0) {};
    Flat(const double& prc, const double& area) :price_(prc), area_(area) {};
    Flat(const Flat& other) :price_(other.price_), area_(other.area_) {};
    Flat& operator = (const Flat&);
    bool operator == (const Flat&);
    bool operator != (const Flat&);
    bool operator > (const Flat&);
    bool operator < (const Flat&);
    friend ostream& operator<<(ostream& out, const Flat& other);
};
Flat& Flat::operator = (const Flat& other) {
    if (this == &other)
        return *this;
    price_ = other.price_;
    area_ = other.area_;
    return *this;
}
bool Flat::operator == (const Flat& other) {
    return area_ == other.area_;
}
bool Flat::operator != (const Flat& other) {
    return !(area_ == other.area_);
}
bool Flat::operator > (const Flat& other) {
    return price_ > other.price_;
}
bool Flat::operator < (const Flat& other) {
    return price_ < other.price_;
}
ostream& operator<<(ostream& out, const Flat& other) {
    out << "Ïëîùàäü: " << other.area_ << ", Öåíà: " << other.price_;
    return out;
}

