#ifndef POD_HPP
#define POD_HPP

#include "Container.hpp"
#include <string>
#include <vector>
#include <memory>

class Pod : public Resource {
private:
    std::vector<std::unique_ptr<Container>> containers;

public:
    explicit Pod(const std::string& id);
    void addContainer(std::unique_ptr<Container> container);
    const std::vector<std::unique_ptr<Container>>& getContainers() const { return containers; }
    double getTotalCPU() const;
    double getTotalMemory() const;
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
};

#endif // POD_HPP
