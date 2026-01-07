//
// Created by fanboyan on 2025/8/26.
//

#include "damage.h"

namespace Revenants {
    DamageManager::~DamageManager() { damages.clear(); }

    void DamageManager::setDamage(const std::string& source, const float damage) { damages[source] = damage; }

    float DamageManager::getDamage(const std::string &source) const {
        using ConstIterator = std::unordered_map<std::string, float>::const_iterator;
        const ConstIterator iterator = damages.find(source);

        if (iterator != damages.end()) return iterator->second;
        return NONE;
    }
}