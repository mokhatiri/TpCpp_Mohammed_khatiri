#ifndef KUBERNETES_CLUSTER_HPP
#define KUBERNETES_CLUSTER_HPP

#include "Server.hpp"
#include "Pod.hpp"
#include <vector>
#include <memory>
#include <functional>
#include <string>

class KubernetesCluster {
private:
    std::vector<std::shared_ptr<Server>> servers;
    std::vector<std::unique_ptr<Pod>> pods;

public:
    void addNode(std::shared_ptr<Server> server);
    void deployPod(std::unique_ptr<Pod> pod);
    const std::vector<std::shared_ptr<Server>>& getServers() const { return servers; }
    const std::vector<std::unique_ptr<Pod>>& getPods() const { return pods; }
    std::string getMetrics() const;
    std::vector<std::shared_ptr<Server>> getFilteredServers(const std::function<bool(const Server&)>& filter) const;
};

#endif // KUBERNETES_CLUSTER_HPP
