#include "Cloud_Util.hpp"
#include "KubernetesCluster.hpp"
#include "CloudExceptions.hpp"
#include "MetricLogger.hpp"
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
    std::cout << "=== Test AllocationException direct ===\n";
    Server failNode("fail-node", 1.0, 1024.0);
    failNode.allocate(4.0, 4096.0); // Trop gros

    std::cout << "\n=== Test FileException ===\n";
    KubernetesCluster cluster;
    auto nodeX = std::make_shared<Server>("nodeX", 12.0, 12048.0);
    nodeX->start(); // activer le noeud
    cluster.addNode(nodeX); // cluster non vide
    saveClusterMetrics(cluster, "cluster1_metrics.txt");

    std::cout << "\n=== Test Lambda : serveurs inactifs ===\n";
    KubernetesCluster cluster1;
    auto inactiveServer = std::make_shared<Server>("node3", 2.0, 4096.0); // Ne sera pas activé
    cluster1.addNode(inactiveServer);
    auto inactifs = cluster1.getFilteredServers([](const Server& s) {
        return !s.isActive();
    });
    for (const auto& server : inactifs) {
        std::cout << server->getMetrics() << std::endl;
    }

    std::cout << "\n=== Déploiement sur un serveur inactif ===\n";
    auto c = std::make_unique<Container>("inactive-c1", "busybox", 1.0, 1024.0);
    auto pod = std::make_unique<Pod>("test-pod");
    pod->addContainer(std::move(c));
    cluster1.deployPod(std::move(pod));

    std::cout << "\n=== Pods triés par nombre de conteneurs ===\n";
    // Création des conteneurs
    auto c1 = std::make_unique<Container>("c1", "nginx", 2.0, 1024.0);
    auto c2 = std::make_unique<Container>("c2", "redis", 4, 2048.0);
    auto c3 = std::make_unique<Container>("c3", "mysql", 2, 1024.0);
    auto c4 = std::make_unique<Container>("c4", "myapp", 10, 12024.0);

    // Création des pods
    auto pod1 = std::make_unique<Pod>("web-pod");
    pod1->addContainer(std::move(c1));
    pod1->addContainer(std::move(c2));
    auto pod2 = std::make_unique<Pod>("db-pod");
    pod2->addContainer(std::move(c3));

    // Déploiement sans planification réelle, on injecte les pods manuellement
    std::vector<std::unique_ptr<Pod>> pods;
    pods.push_back(std::move(pod1));
    pods.push_back(std::move(pod2));

    for (auto& pod : pods) {
        std::cout << "-> Déploiement du Pod " << pod->getMetrics();
        cluster.deployPod(std::move(pod));
    }

    std::cout << "\n=== Tri des pods ===\n";
    std::vector<const Pod*> podRefs;
    for (const auto& server : cluster.getServers()) {
        for (const auto& pod : server->getPods()) {
            podRefs.push_back(pod.get());
        }
    }
    std::sort(podRefs.begin(), podRefs.end(), 
        [](const Pod* a, const Pod* b) {
            return a->getContainers().size() > b->getContainers().size();
        });
    for (const auto& pod : podRefs) {
        std::cout << pod->getMetrics();
    }

    std::cout << "\n=== Tous les conteneurs du cluster 1 ===\n";
    forEachContainer(cluster, [](const Container& c) {
        std::cout << c.getMetrics() << std::endl;
    });

    return 0;
}

/*
expected output:
---------------

=== Test AllocationException direct ===
Exception capturée : Allocation Error: Serveur fail-node est inactif

=== Test FileException ===
Métriques sauvegardées avec succès.

=== Test Lambda : serveurs inactifs ===
[Server: node3 | Total: 2 CPU, 4096 MB | Free: 2 CPU, 4096 MB]

=== Déploiement sur un serveur inactif ===
Exception capturée : Allocation Error: Server node3 n'est pas actif

=== Pods triés par nombre de conteneurs ===
-> Déploiement du Pod [Pod: web-pod]
[Container: c1 : 2 CPU, 1024 Memory, nginx ]
[Container: c2 : 4 CPU, 2048 Memory, redis ]
sur le nœud
[Server: nodeX | Total: 12 CPU, 12048 MB | Free: 6 CPU, 8976 MB]
-> Déploiement du Pod [Pod: db-pod]
[Container: c3 : 2 CPU, 1024 Memory, mysql ]
sur le nœud
[Server: nodeX | Total: 12 CPU, 12048 MB | Free: 4 CPU, 7952 MB]

=== Tri des pods ===
[Pod: web-pod]
[Container: c1 : 2 CPU, 1024 Memory, nginx ]
[Container: c2 : 4 CPU, 2048 Memory, redis ]
[Pod: db-pod]
[Container: c3 : 2 CPU, 1024 Memory, mysql ]

=== Tous les conteneurs du cluster 1 ===
[Container: c1 : 2 CPU, 1024 Memory, nginx ]
[Container: c2 : 4 CPU, 2048 Memory, redis ]
[Container: c3 : 2 CPU, 1024 Memory, mysql ]
*/