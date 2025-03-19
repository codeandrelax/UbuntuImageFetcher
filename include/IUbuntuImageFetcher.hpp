
#ifndef IUBUNTUIMAGEFETCHER_H
#define IUBUNTUIMAGEFETCHER_H

/**
 * @file IUbuntuImageFetcher.h
 * 
 * @author Damjan Prerad
 * @date 19.3.2025
 * 
 * @brief This file defines the abstract interface class IUbuntuImageFetcher.
 * 
 * The IUbuntuImageFetcher interface is responsible for providing methods 
 * to fetch and retrieve information related to the latest Ubuntu Cloud images 
 * in Simplestreams format. The interface defines three methods:
 * 1. getSupportedReleases(): Returns a list of all currently supported Ubuntu releases.
 * 2. getCurrentLTSVersion(): Returns the current Ubuntu Long-Term Support (LTS) version.
 * 3. getDisk1ImageSHA256(): Returns the SHA256 checksum of the disk1.img item for a specified Ubuntu release.
 * 
 */

#include <string>
#include <vector>

class IUbuntuImageFetcher {
public:
    virtual ~IUbuntuImageFetcher() = default;

    virtual std::vector<std::string> getSupportedReleases() const = 0;

    virtual std::string getCurrentLTSVersion() const = 0;

    virtual std::string getDisk1ImageSHA256(const std::string& release) const = 0;
};

#endif // IUBUNTUIMAGEFETCHER_H