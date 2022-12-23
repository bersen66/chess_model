#include <fmt/color.h>
#include <fmt/core.h>

#include <chess/field/sector/sector.hpp>

namespace chess::field::sector {

void Sector::PrintInConsole() const {
    const auto& background_color = ColorMap.at(background);
    const auto& figure_color = figure::FigureColorMap.at(figure->color);
    fmt::print(
        fmt::bg(background_color) | fmt::fg(figure_color) | fmt::emphasis::bold,
        "{}", static_cast<char>(figure->type));
}

}  // namespace chess::field::sector
