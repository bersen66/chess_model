#include "chess/chess.hpp"

#include "boost/stacktrace.hpp"
#include <fmt/ostream.h>
#include "csignal"

void HandleSIGSEGV(int signal)
{
    // Show stacktrace if SIGSEGV
    fmt::print("\nSIGSEGV OCCURED!\nSIGNAL: {}\nBACKTRACE: {}", signal, boost::stacktrace::stacktrace());
    std::exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    std::signal(SIGSEGV, HandleSIGSEGV);
    chess::RunGame();
    return 0;
}
