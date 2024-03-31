// Particle.cpp
#include "Particle.hpp"

Particle::Particle(double x, double y) : x_(x), y_(y) {}

double Particle::getX() const {
    return x_;
}

double Particle::getY() const {
    return y_;
}

void Particle::move(double dx, double dy) {
    x_ += dx;
    y_ += dy;
}
