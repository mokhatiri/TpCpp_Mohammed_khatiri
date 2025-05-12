#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Resource.hpp"
#include <iostream>
#include <string>

class Container : public Resource {
private:
    std::string image;

public:
    Container(const std::string& id, const std::string& image, double cpu, double memory);
    const std::string& getId() const { return id_; }
    const std::string& getImage() const { return image; }
    double getCPU() const { return cpu_; }
    double getMemory() const { return memory_; }
    void start() override;
    void stop() override;
    std::string getMetrics() const override;

    friend std::ostream& operator<<(std::ostream& os, const Container& c);
};

#endif // CONTAINER_HPP
