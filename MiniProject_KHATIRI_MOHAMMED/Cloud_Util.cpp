#include "Cloud_Util.hpp"
#include "CloudExceptions.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics() << std::endl;
}

void displayServers(const std::vector<std::shared_ptr<Server>>& servers) {
    for (const auto& server : servers) {
        std::cout << server->getMetrics() << std::endl;
    }
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        cluster.deployPod(std::move(pod));
    }
    pods.clear();
}

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Exception capturée : File Error: Impossible d'ouvrir le fichier " + filename << std::endl;
        return;
    }
    file << cluster.getMetrics();
    std::cout << "Métriques sauvegardées avec succès." << std::endl;
}

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    for (const auto& server : cluster.getServers()) {
        for (const auto& pod : server->getPods()) {
            for (const auto& container : pod->getContainers()) {
                func(*container);
            }
        }
    }
}

