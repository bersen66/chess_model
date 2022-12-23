#include "chess/field/field.hpp"

namespace chess::field {

Field::Field() : field(Build()) {}

namespace {
sector::BackgroundColor DefineBackgroundColor(size_t i, size_t j) {
    return (i + j) % 2 ? sector::BackgroundColor::BLACK
                       : sector::BackgroundColor::WHITE;
}

sector::figure::FigureType DefineFigureType(size_t i, size_t j) {
    // .clang-format off
    static const std::vector<sector::figure::FigureType> figures = {
        sector::figure::FigureType::ROOK,   sector::figure::FigureType::KNIGHT,
        sector::figure::FigureType::BISHOP, sector::figure::FigureType::QUEEN,
        sector::figure::FigureType::KING,   sector::figure::FigureType::BISHOP,
        sector::figure::FigureType::KNIGHT, sector::figure::FigureType::ROOK,
    };
    // .clang-format on

    switch (i) {
        case 1:
            return figures[j - 1];

        case 8:
            return figures[8 - j];

        case 2:
        case 7:
            return sector::figure::FigureType::PAWN;
        default:
            return sector::figure::FigureType::EMPTY;
    }
}

sector::figure::FigureColor DefineFigureColor(size_t i, size_t j) {
    if (1 <= i && i <= 2) {
        return sector::figure::FigureColor::BLACK;
    }
    if (7 <= i && i <= 8) {
        return sector::figure::FigureColor::WHITE;
    }
    return sector::figure::FigureColor::NO_COLOR;
}
}  // namespace

std::vector<std::vector<sector::Sector>> Field::Build() {
    const size_t n = 8;
    std::vector<std::vector<sector::Sector>> result(
        n, std::vector<sector::Sector>(n));

    size_t cnt = 0;

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            result[i - 1][j - 1] = sector::Sector{
                .figure = std::make_shared<sector::figure::Figure>(
                    sector::figure::Figure{.type = DefineFigureType(i, j),
                                           .color = DefineFigureColor(i, j)}),

                .background = DefineBackgroundColor(i, j)};
        }
    }

    return result;
}

void Field::PrintInConsole() const {
    int cnt = 1;
    for (const auto& row : field) {
        for (const auto& sector : row) {
            sector.PrintInConsole();
        }
        fmt::print("--{}\n", cnt++);
    }
}

bool Field::HasCharacter(size_t x, size_t y) const {
    return field[y-1][x-1].figure->type != sector::figure::FigureType::EMPTY;
}

void Field::MoveCharacter(size_t src_x, size_t src_y, size_t dest_x,
                          size_t dest_y) {
    auto& src_sector = field[src_y - 1][src_x - 1];
    auto& dest_sector = field[dest_y - 1][dest_x - 1];

    dest_sector.figure->type = src_sector.figure->type;
    dest_sector.figure->color = src_sector.figure->color;

    src_sector.figure->type = sector::figure::FigureType::EMPTY;
    src_sector.figure->color = sector::figure::FigureColor::NO_COLOR;
}

bool Field::IsValidMove(size_t src_x, size_t src_y, size_t dest_x,
                        size_t dest_y) const {

    const auto& figure = *field[src_y - 1][src_x - 1].figure;
    const auto& opponent = *field[dest_y - 1][dest_x - 1].figure;

    return !figure.SameColor(opponent);
}

}  // namespace chess::field