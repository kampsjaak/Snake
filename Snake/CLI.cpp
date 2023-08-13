#include "CLI.h"
#include "lyra/lyra.hpp"

Snek::CLI::CLI(int argc, const char** argv) {
    int width = 0;
    int height = 0;
    int language = 0;

    auto cli = lyra::cli();
    cli.add_argument(lyra::opt(width, "width")
        .name("-w").name("--width").help("How wide should it be?"));
    cli.add_argument(lyra::opt(height, "height")
        .name("-h").name("--height").help("How high should it be?"));
    cli.add_argument(lyra::opt(language, "language")
        .name("-l").name("--lang").help("What language should it be?"));


    //// Parse the program arguments:
    //auto result = cli.parse({ argc, argv });

    //// Check that the arguments where valid:
    //if (!result)
    //{
    //    std::cerr << "Error in command line: " << result.message() << std::endl;
    //    return 1;
    //}

    //std::cout << "width = " << width << ", name = " << name << ", doIt = " << doIt << "\n";
    //return 0;
}