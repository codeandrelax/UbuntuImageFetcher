
#include <iostream>
#include "UbuntuImageFetcher.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " --option [--supported-releases, --current-lts, --sha256 <release>]" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    UbuntuImageFetcher fetcher("https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json");

    if (option == "--supported-releases") {
        auto releases = fetcher.getSupportedReleases();
        for (const auto& release : releases) {
            std::cout << release << std::endl;
        }
    } else if (option == "--current-lts") {
        std::cout << fetcher.getCurrentLTSVersion() << std::endl;
    } else if (option == "--sha256" && argc == 3) {
        std::cout << fetcher.getDisk1ImageSHA256(argv[2]) << std::endl;
    } else {
        std::cerr << "Unknown option or missing argument." << std::endl;
        return 1;
    }

    return 0;
}