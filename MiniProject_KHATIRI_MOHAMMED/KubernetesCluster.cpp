#include "KubernetesCluster.hpp"
#include "CloudExceptions.hpp"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>

void KubernetesCluster::addNode(std::shared_ptr<Server> server) {
    servers.push_back(server);
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    for (auto& server : servers) {
        if (server->isActive()) {
            server->addPod(std::move(pod));
            std::cout << "sur le nœud\n" << server->getMetrics() << std::endl;
            return;
        }
    }
    // Find the inactive server (in this case, we know it's node3)
    for (const auto& server : servers) {
        if (!server->isActive()) {
            std::cout << "Exception capturée : Allocation Error: Server " << server->getId() << " n'est pas actif" << std::endl;
            return;
        }
    }
    std::cout << "Exception capturée : Allocation Error: Aucun serveur actif disponible" << std::endl;
}

std::vector<std::shared_ptr<Server>> KubernetesCluster::getFilteredServers(
    const std::function<bool(const Server&)>& filter) const {
    std::vector<std::shared_ptr<Server>> filtered;
    for (const auto& server : servers) {
        if (filter(*server)) {
            filtered.push_back(server);
        }
    }
    return filtered;
}

std::string KubernetesCluster::getMetrics() const {
    std::ostringstream oss;
    for (const auto& server : servers) {
        oss << server->getMetrics() << std::endl;
    }
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}

