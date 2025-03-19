#include <iostream>
#include "test_UbuntuImageFetcher.hpp"

int main() {
    testGetSupportedReleases();
    testGetCurrentLTSVersion();
    testGetDisk1ImageSHA256();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
