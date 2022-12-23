#pragma once
#include "chess/field/sector/figure/figure.hpp"
#include <fmt/color.h>

namespace chess::field::sector {

enum class BackgroundColor : uint32_t {
    BLACK,
    WHITE,
};

static const std::unordered_map<BackgroundColor, fmt::color> ColorMap = {
    {BackgroundColor::BLACK, fmt::color::brown},
    {BackgroundColor::WHITE, fmt::color::slate_gray},
};

struct Sector {
    figure::FigureHolder figure;
    BackgroundColor background;

    void PrintInConsole() const;
};



}  // namespace chess::field::sector