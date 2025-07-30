//
// Created by fanboyan on 2025/7/22.
//

#ifndef DREAM_ENGINE_BAR_H
#define DREAM_ENGINE_BAR_H

#include "view.h"
#include "alignment.h"
#include "edge.h"
#include "color.h"

namespace DreamEngine {
    /// A UI component that displays a progress bar with optional trailing animation and title support.
    /// It automatically updates its progress when bound to an Observable<float> object.
    ///
    class BarView final : public View, public Observer<float> {
        /// Maximum value for the progress bar.
        public: float maxProgress = NONE;

        /// Current progress value to be visually represented.
        public: float currentProgress = maxProgress;

        /// Speed at which the trailing progress catches up to the current value.
        public: float trailingSpeed = DEFAULT_TRAILING_SPEED;

        /// Delay before the trailing animation begins.
        public: float trailingDelay = DEFAULT_TRAILING_DELAY;

        /// Determines whether trailing animation is active.
        public: bool isTrailingEnabled = true;

        /// Color of the filled progress area.
        public: Color foregroundColor = Color::Red;

        /// Color of the unfilled background area.
        public: Color backgroundColor = Color::Grey;

        /// Color of the outline surrounding the bar.
        public: Color outlineColor = Color::Black;

        /// Color used for the trailing progress indicator.
        public: Color trailingColor = Color::White;

        /// Width of the outline stroke.
        public: float outlineWidth = NONE;

        /// Optional title text displayed on the bar.
        public: std::string titleContent = std::string();

        /// Font used for the title text.
        public: std::string titleFont = std::string();

        /// Font size used for the title.
        public: float titleFontSize = DEFAULT_TITLE_SIZE;

        /// Scale factor applied to the title font size.
        public: float titleScaleFactor = NONE;

        /// Color of the title text.
        public: Color titleColor = Color::White;

        /// Alignment of the title text within the bar.
        public: Alignment titleAlignment = Alignment::Center;

        /// Padding applied to the title text within its container.
        public: EdgeInsets titlePaddings = EdgeInsets();

        /// Internal trailing value used for delayed animation rendering.
        private: float trailingProgress;

        /// Timer tracking remaining delay before trailing animation starts.
        private: float trailingDelayTimer = trailingDelay;

        /// Constructs a progress bar with the given maximum progress value.
        /// @param maxProgress The maximum progress this bar can represent.
        ///
        public: explicit BarView(float maxProgress);

        /// Default Destructor.
        public: ~BarView() override = default;

        /// Updates the bar's internal state, including trailing animation.
        /// @param interval Time elapsed since the last update.
        ///
        public: void onUpdate(float interval) override;

        /// Renders the progress bar to the screen using the provided camera.
        /// @param camera Camera reference for coordinate transformation.
        ///
        public: void onRender(const Camera& camera) const override;

        /// Called when the observed value changes and update the current progress representation.
        /// @param newValue The new float value from the observable source.
        ///
        public: void onNotified(const float& newValue) override;
    };
}

#endif //DREAM_ENGINE_BAR_H
