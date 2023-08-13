#include "CLI.h"
#include "lyra/lyra.hpp"

Snek::CLI::CLI(int argc, const char** argv) {
    int error_code = -1;

    auto cli = lyra::cli();
    cli.add_argument(lyra::opt(WIDTH, "width")
        .name("-w").name("--width").help("How wide should it be?"));
    cli.add_argument(lyra::opt(HEIGHT, "height")
        .name("-h").name("--height").help("How high should it be?"));
    cli.add_argument(lyra::opt(LANGUAGE, "language")
        .name("-l").name("--lang").help("What language should it be?"));

    auto result = cli.parse({ argc, argv });

    // Check that the arguments where valid:
    if (!result)
    {
        std::cerr << "Error in command line: " << result.message() << std::endl;
        error_code = 1;
    }

    std::cout << "width = " << WIDTH << ", height = " << HEIGHT << ", language = " << LANGUAGE << "\n";
    error_code = 0;
}