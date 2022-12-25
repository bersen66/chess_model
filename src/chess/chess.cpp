#include <stdlib.h>

#include <chess/chess.hpp>
namespace chess {

namespace game {

void Game::Select(size_t x, size_t y) {
    selected_x = x;
    selected_y = y;
}

void Game::MoveTo(size_t x, size_t y) {
    field.MoveCharacter(selected_x, selected_y, x, y);
}

bool Game::CanMoveTo(size_t x, size_t y) const {
    return ValidPosition(x, y) &&
           field.IsValidMove(selected_x, selected_y, x, y);
}

void Game::PrintInConsole() const {
    field.PrintInConsole();
    for (int i = 1; i <= 8; i++) {
        fmt::print("|");
    }
    fmt::print("\n");
    for (int i = 1; i <= 8; i++) {
        fmt::print("{}", i);
    }
}
bool Game::ValidPosition(size_t x, size_t y) const {
    return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}
bool Game::CanSelect(size_t x, size_t y) const {
    return ValidPosition(x, y) && field.HasCharacter(x, y) && field.HasCharacter(x, y) ;
}

}  // namespace game

namespace {
void Clear() {
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}
}  // namespace
[[noreturn]] void RunGame() {
    game::Game chess;
    size_t src_x, src_y, dest_x, dest_y;
    while (true) {
        fmt::print("\x1B[3J\x1B[H");
        Clear();
        chess.PrintInConsole();

        fmt::print(fmt::fg(fmt::color::green), "\nSelect figure (x, y):\n");
        std::cin >> src_x >> src_y;

        while (!chess.CanSelect(src_x, src_y)) {
            fmt::print(fmt::fg(fmt::color::red), "\nInvalid location\n");
            std::cin >> src_x >> src_y;
        }
        chess.Select(src_x, src_y);
        fmt::print(fmt::fg(fmt::color::green), "\nWhere to go (x, y):\n");
        std::cin >> dest_x >> dest_y;

        while (!chess.CanMoveTo(dest_x, dest_y)) {
            fmt::print(fmt::fg(fmt::color::red), "\nInvalid move\n");
            std::cin >> dest_x >> dest_y;
        }

        chess.MoveTo(dest_x, dest_y);
    }
}

}  // namespace chess