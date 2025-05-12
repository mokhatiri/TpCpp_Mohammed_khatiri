#include "Container.hpp"
#include <sstream>
#include <iomanip>

Container::Container(const std::string& id, const std::string& image, double cpu, double memory)
    : Resource(id, cpu, memory), image(image) {}

void Container::start() {
    active_ = true;
}

void Container::stop() {
    active_ = false;
}

std::string Container::getMetrics() const {
    std::ostringstream oss;
    oss << "[Container: " << std::left << std::setw(10) << id_ << " : "
        << std::fixed << std::setprecision(0) << cpu_ << " CPU, "
        << std::fixed << std::setprecision(0) << memory_ << " Memory, " << image << " ]" << std::endl;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
}
