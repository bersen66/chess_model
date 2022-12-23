#pragma once
#include <memory>  // for std::shared_ptr
#include <unordered_map>
#include <iostream>
#include <fmt/color.h>

namespace chess::field::sector::figure {


enum class FigureType : char {
    EMPTY = ' ',   //
    PAWN = 'p',    // пешка
    KNIGHT = 'K',  // конь
    ROOK = 'R',    // ладья
    BISHOP = 'B',  // слон
    QUEEN = 'Q',   // ферзь
    KING = '*',    // король
};

enum class FigureColor {
    BLACK,
    WHITE,
    NO_COLOR,
};

static const std::unordered_map<FigureColor, fmt::color> FigureColorMap = {
    {FigureColor::BLACK, fmt::color::black},
    {FigureColor::WHITE, fmt::color::light_golden_rod_yellow},
    {FigureColor::NO_COLOR, fmt::color::white},
};

struct Figure {

    FigureType type = FigureType::EMPTY;
    FigureColor color = FigureColor::NO_COLOR;

    bool SameColor(const Figure& other) const;
};

using FigureHolder = std::shared_ptr<Figure>;


}  // namespace chess::field::sector::figure