#pragma once

#include <vector>
#include <chess/field/sector/sector.hpp>

namespace chess::field {
class Field {
public:
    Field();
    void PrintInConsole() const;

    bool HasCharacter(size_t x, size_t y) const;

    bool IsValidMove(size_t src_x, size_t src_y, size_t dest_x, size_t dest_y) const;

    void MoveCharacter(size_t src_x, size_t src_y, size_t dest_x, size_t dest_y);

private:
    static std::vector<std::vector<sector::Sector>> Build();
private:
    std::vector<std::vector<sector::Sector>> field;
};
} // namespace chess::field