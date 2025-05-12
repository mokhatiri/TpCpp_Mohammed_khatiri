#include "Server.hpp"
#include "CloudExceptions.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

Server::Server(const std::string& id, double cpu, double memory)
    : Resource(id, cpu, memory), total_cpu_(cpu), total_memory_(memory) {}

void Server::allocate(double cpu, double memory) {
    if (!active_) {
        std::cout << "Exception capturée : Allocation Error: Serveur " + id_ + " est inactif" << std::endl;
        return;
    }
    if (cpu > cpu_ || memory > memory_) {
        std::cout << "Exception capturée : Allocation Error: Ressources insuffisantes sur le serveur " + id_ << std::endl;
        return;
    }
    cpu_ -= cpu;
    memory_ -= memory;
}

void Server::addPod(std::unique_ptr<Pod> pod) {
    if (!active_) {
        std::cout << "Exception capturée : Allocation Error: Server " + id_ + " n'est pas actif" << std::endl;
        return;
    }
    // Check if we have enough resources
    if (pod->getCPU() > cpu_ || pod->getMemory() > memory_) {
        std::cout << "Exception capturée : Allocation Error: Ressources insuffisantes sur le serveur " + id_ << std::endl;
        return;
    }
    // Subtract pod's resources from available resources
    cpu_ -= pod->getCPU();
    memory_ -= pod->getMemory();
    pods.push_back(std::move(pod));
}

void Server::start() {
    active_ = true;
}

void Server::stop() {
    active_ = false;
}

std::string Server::getMetrics() const {
    std::ostringstream oss;
    oss << "[Server: " << std::left << std::setw(10) << id_ << " | "
        << "Total: " << std::fixed << std::setprecision(0) << total_cpu_ << " CPU, "
        << std::fixed << std::setprecision(0) << total_memory_ << " MB | "
        << "Free: " << std::fixed << std::setprecision(0) << cpu_ << " CPU, "
        << std::fixed << std::setprecision(0) << memory_ << " MB]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
}

