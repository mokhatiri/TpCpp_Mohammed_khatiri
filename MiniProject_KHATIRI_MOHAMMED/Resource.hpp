#pragma once
#include <string>

class Resource {
protected:
    std::string id_;
    double cpu_;
    double memory_;
    bool active_;

public:
    Resource(std::string id, double cpu, double memory)
        : id_(std::move(id)), cpu_(cpu), memory_(memory), active_(false) {}

    double getCPU() const { return cpu_; }      
    double getMemory() const { return memory_; }
    const std::string& getId() const { return id_; }
    
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual std::string getMetrics() const = 0;
    virtual ~Resource() = default;
};
