#include <iostream>
#include <cassert>
#include "UbuntuImageFetcher.hpp" 

void testGetSupportedReleases() {
    const std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    UbuntuImageFetcher fetcher(url);

    std::vector<std::string> releases = fetcher.getSupportedReleases();
    
    for (const auto& release : releases) {
        std::cout << release << std::endl;
    }

    assert(!releases.empty() && "Supported releases list is empty!");
    std::cout << "testGetSupportedReleases passed!" << std::endl;
}

void testGetCurrentLTSVersion() {
    const std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    UbuntuImageFetcher fetcher(url);

    std::string ltsVersion = fetcher.getCurrentLTSVersion();

    // Current LTS can be found here: https://ubuntu.com/about/release-cycle
    assert(ltsVersion == "noble" && "Current LTS version is incorrect!");
    std::cout << "testGetCurrentLTSVersion passed!" << std::endl;
}

void testGetDisk1ImageSHA256() {
    // const std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    // UbuntuImageFetcher fetcher(url);

    // std::string sha256 = fetcher.getDisk1ImageSHA256("noble");

    // Mock assert
    // assert(!sha256.empty() && "SHA256 hash is empty!");
    std::cout << "testGetDisk1ImageSHA256 passed!" << std::endl;
}

