//
// Created by fanboyan on 2025/7/30.
//

#ifndef DREAM_ENGINE_ALIGNMENT_H
#define DREAM_ENGINE_ALIGNMENT_H

namespace DreamEngine {
    /// Specifies alignment options for UI layout or content positioning, defines various positions that can be used to
    /// align views, components, or content within a container or region, where
    ///     - Leading: Align to the leading edge, left, or top, depending on the orientation.
    ///     - Trailing: Align to the trailing edge, right, or bottom, depending on the orientation.
    ///     - Center: Align to the center.
    ///     - Top: Align to the top edge.
    ///     - Bottom: Align to the bottom edge.
    ///     - None: No alignment specified or default fallback.
    ///
    enum class Alignment { Leading, Trailing, Center, Top, Bottom, None };
}

#endif //DREAM_ENGINE_ALIGNMENT_H
