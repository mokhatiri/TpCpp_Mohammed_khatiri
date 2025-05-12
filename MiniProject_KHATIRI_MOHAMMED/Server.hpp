#ifndef SERVER_HPP
#define SERVER_HPP

#include "Resource.hpp"
#include "Pod.hpp"
#include "CloudExceptions.hpp"
#include <string>
#include <vector>
#include <memory>

class Server : public Resource {
private:
    bool active_;
    std::vector<std::unique_ptr<Pod>> pods;
    double total_cpu_;
    double total_memory_;

public:
    Server(const std::string& id, double cpu, double memory);
    void start() override;
    void stop() override;
    bool isActive() const { return active_; }
    void allocate(double cpu, double memory);
    void addPod(std::unique_ptr<Pod> pod);
    const std::string& getId() const { return id_; }
    double getAvailableCPU() const { return cpu_; }
    double getAvailableMemory() const { return memory_; }
    const std::vector<std::unique_ptr<Pod>>& getPods() const { return pods; }
    std::string getMetrics() const override;
};

#endif // SERVER_HPP
