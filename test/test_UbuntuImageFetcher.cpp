
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
    // Current is: 24.04 LTS
    assert(ltsVersion == "24.04 LTS" && "Current LTS version is incorrect!");
    std::cout << "testGetCurrentLTSVersion passed!" << std::endl;
}

void testGetDisk1ImageSHA256() {
    const std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    UbuntuImageFetcher fetcher(url);

    std::string sha256 = fetcher.getDisk1ImageSHA256("noble");

    assert(!sha256.empty() && "SHA256 hash is empty!");
    assert(sha256 == "32a9d30d18803da72f5936cf2b7b9efcb4d0bb63c67933f17e3bdfd1751de3f3" && 
           "SHA256 hash for 'noble' release is incorrect!");

    std::cout << "testGetDisk1ImageSHA256 passed!" << std::endl;
}

