#include <gtest/gtest.h>

#include <chess/field/field.hpp>
#include <iostream>

#include "chess/chess.hpp"

TEST(TestFieldConstruction, test1) {
  chess::field::Field f;
  f.PrintInConsole();
}

TEST(TestPositions, test2) {
  chess::game::Game g;
  EXPECT_EQ(g.ValidPosition(1, 2), true);
  EXPECT_EQ(g.ValidPosition(0, 2), false);
  EXPECT_EQ(g.ValidPosition(-1, 2), false);
  EXPECT_EQ(g.ValidPosition(2, -21323), false);
  EXPECT_EQ(g.ValidPosition(2, 10), false);
  EXPECT_EQ(g.ValidPosition(10, 10), false);
  EXPECT_EQ(g.ValidPosition(10, 1), false);
  EXPECT_EQ(g.ValidPosition(1, 2), true);
  EXPECT_EQ(g.ValidPosition(2, 1), true);
  EXPECT_EQ(g.ValidPosition(8, 8), true);
}

TEST(TestCanSelect, test3) {
  chess::game::Game g;
  EXPECT_EQ(g.CanSelect(1, 2), true);
  EXPECT_EQ(g.CanSelect(2, 2), true);
  EXPECT_EQ(g.CanSelect(3, 3), false);
  EXPECT_EQ(g.CanSelect(2, 3), false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
