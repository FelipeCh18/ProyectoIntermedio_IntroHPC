// Particle.hpp
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
public:
    Particle(double x = 0, double y = 0);

    double getX() const;
    double getY() const;
    void move(double dx, double dy);

private:
    double x_;
    double y_;
};

#endif // PARTICLE_HPP
