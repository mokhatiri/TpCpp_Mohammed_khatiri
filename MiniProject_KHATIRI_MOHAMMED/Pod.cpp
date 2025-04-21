#include "Pod.hpp"
#include <algorithm>

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels)
    : name_(std::move(name)), labels_(std::move(labels)) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string& id) {
    auto it = std::remove_if(containers_.begin(), containers_.end(), [&](const auto& c) {
        return c->getMetrics().find(id) != std::string::npos;
    });
    if (it != containers_.end()) {
        containers_.erase(it, containers_.end());
        return true;
    }
    return false;
}

void Pod::deploy() {
    for (auto& container : containers_) {
        container->start();
    }
}

std::string Pod::getMetrics() const {
    std::string result = "[Pod: " + name_ + "]\n";
    for (const auto& container : containers_) {
        result += container->getMetrics() + "\n";
    }
    return result;
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    return os << p.getMetrics();
}
