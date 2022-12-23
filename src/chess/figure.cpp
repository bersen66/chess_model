#include <chess/field/sector/figure/figure.hpp>

namespace chess::field::sector::figure {

bool Figure::SameColor(const Figure& other) const {
    return color == other.color;
}

}  // namespace chess::field::sector::figure