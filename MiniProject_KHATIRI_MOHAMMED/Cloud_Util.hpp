#pragma once
#include "KubernetesCluster.hpp"

void display(const KubernetesCluster& cluster);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

