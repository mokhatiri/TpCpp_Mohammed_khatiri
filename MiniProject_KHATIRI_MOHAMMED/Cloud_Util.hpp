#ifndef CLOUD_UTIL_HPP
#define CLOUD_UTIL_HPP

#include "KubernetesCluster.hpp"
#include "Container.hpp"
#include <string>
#include <functional>

void display(const KubernetesCluster& cluster);
void displayServers(const std::vector<std::shared_ptr<Server>>& servers);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);
void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename);
void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func);

#endif // CLOUD_UTIL_HPP

