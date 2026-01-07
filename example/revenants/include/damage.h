//
// Created by fanboyan on 2025/8/26.
//

#ifndef REVENANTS_DAMAGE_H
#define REVENANTS_DAMAGE_H

#include "engine/core.h"

namespace Revenants {
    class DamageManager final : public DreamEngine::Singleton<DamageManager> {
        private: std::unordered_map<std::string, float> damages;

        public: DamageManager() = default;
        public: ~DamageManager() override;

        public: float getDamage(const std::string& source) const;
        public: void setDamage(const std::string& source, float damage);
    };
}

#endif //REVENANTS_DAMAGE_H
