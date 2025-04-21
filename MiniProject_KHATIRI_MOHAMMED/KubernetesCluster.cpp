#include "KubernetesCluster.hpp"
#include <algorithm>

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(std::move(node));
}

bool KubernetesCluster::removePod(const std::string& name) {
    auto it = std::remove_if(pods_.begin(), pods_.end(), [&](const auto& pod) {
        return pod->getMetrics().find(name) != std::string::npos;
    });
    if (it != pods_.end()) {
        pods_.erase(it, pods_.end());
        return true;
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    if (schedulePod(*pod)) {
        pod->deploy();
        std::cout << *pod << "déployé avec succès.\n";
        pods_.push_back(std::move(pod));
    } else {
        std::cout << "Échec du déploiement du pod \n" << *pod << ": ressources insuffisantes.\n";
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double total_cpu = 0, total_mem = 0;
    for (const auto& c : pod.getContainers()) {
        total_cpu += c->getCPU();     
        total_mem += c->getMemory();  
    }
    for (auto& node : nodes_) {
        if (node->allocate(total_cpu, total_mem)) {
            std::cout << "-> Déploiement du Pod " << pod.getMetrics();
            std::cout << "sur le nœud " << *node << '\n';
            return true;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    for (const auto& pod : pods_) {
        if (pod->getMetrics().find(name) != std::string::npos) {
            return pod.get();
        }
    }
    return nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::string result = "=== Cluster Metrics ===\n";
    for (const auto& node : nodes_) {
        result += node->getMetrics() + "\n";
    }
    for (const auto& pod : pods_) {
        result += pod->getMetrics() + "\n";
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    return os << c.getMetrics();
}

