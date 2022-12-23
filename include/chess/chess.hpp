#pragma once
#include <chess/field/field.hpp>
namespace chess {

namespace game {
class Game {
public:

    Game() = default;

    bool CanSelect(size_t x, size_t y) const;
    void Select(size_t x, size_t y);

    void MoveTo(size_t x, size_t y);

    bool CanMoveTo(size_t x, size_t y) const;

    void PrintInConsole() const;

    bool ValidPosition(size_t x, size_t y) const;

private:

    size_t selected_x = 0;
    size_t selected_y = 0;
    chess::field::sector::figure::FigureColor current_turn;
    chess::field::Field field;
};
}  // namespace game

[[noreturn]] void RunGame();

}  // namespace chess