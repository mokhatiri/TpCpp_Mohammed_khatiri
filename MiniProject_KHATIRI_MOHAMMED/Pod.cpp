#include "Pod.hpp"
#include <sstream>
#include <iomanip>
#include <numeric>

Pod::Pod(const std::string& id) : Resource(id, 0.0, 0.0) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    cpu_ += container->getCPU();
    memory_ += container->getMemory();
    containers.push_back(std::move(container));
}

double Pod::getTotalCPU() const {
    return std::accumulate(containers.begin(), containers.end(), 0.0,
        [](double sum, const auto& container) { return sum + container->getCPU(); });
}

double Pod::getTotalMemory() const {
    return std::accumulate(containers.begin(), containers.end(), 0.0,
        [](double sum, const auto& container) { return sum + container->getMemory(); });
}

void Pod::start() {
    active_ = true;
}

void Pod::stop() {
    active_ = false;
}

std::string Pod::getMetrics() const {
    std::ostringstream oss;
    oss << "[Pod: " << std::left << std::setw(10) << id_ << "]" << std::endl;
    for (const auto& container : containers) {
        oss << container->getMetrics();
    }
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}
