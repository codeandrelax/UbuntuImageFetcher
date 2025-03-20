

#ifndef UBUNTUIMAGEFETCHER_H
#define UBUNTUIMAGEFETCHER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "IUbuntuImageFetcher.hpp"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/URI.h>

/**
 * @file UbuntuImageFetcher.h
 * 
 * @author Damjan Prerad
 * @date 19.3.2025
 * 
 * @brief This file defines the class `UbuntuImageFetcher`, which implements the 
 * `IUbuntuImageFetcher` interface. The class fetches Ubuntu image information 
 * in Simplestreams format from the provided JSON endpoint and provides methods 
 * to retrieve supported releases, the current LTS version, and SHA256 checksums 
 * for the disk1.img files of specific releases.
 * 
 * The class uses the Poco library to fetch data via HTTP and parse the Simplestreams 
 * JSON data.
 */

class UbuntuImageFetcher : public IUbuntuImageFetcher {
public:
    UbuntuImageFetcher(const std::string& url);
    virtual ~UbuntuImageFetcher() = default;

    /**
     * @brief Fetches a list of all supported Ubuntu releases for the amd64 architecture.
     *
     * This method retrieves the list of all supported Ubuntu releases from the cloud image stream
     * for the `amd64` architecture.
     *
     * @return A vector containing the names of all supported releases (specifically for amd64).
     */
    std::vector<std::string> getSupportedReleases() const override;

    /**
     * @brief Returns the current Ubuntu LTS version for the amd64 architecture.
     *
     * This method fetches and returns the latest Long-Term Support (LTS) version of Ubuntu 
     * available for the `amd64` architecture.
     *
     * @return A string representing the current LTS version (e.g., "20.04 LTS").
     */
    std::string getCurrentLTSVersion() const override;

    /**
     * @brief Retrieves the SHA256 hash of the disk1.img item for a given Ubuntu release (amd64 only).
     *
     * This method fetches the SHA256 hash for the disk1.img file associated with a specific release
     * of Ubuntu, specifically for the `amd64` architecture.
     *
     * @param release The name of the release for which to fetch the SHA256 hash (e.g., "22.04").
     * @return The SHA256 hash as a string (e.g., "d7109495731c8cdec9151d9a4f4fd2d5792a65a21eaf7c2afdd1e1620ce6a911").
     */
    std::string getDisk1ImageSHA256(const std::string& release) const override;

private:
    std::string fetchSimplestreamsData() const;
    Poco::JSON::Object::Ptr parseJson(const std::string& jsonData) const;
    std::string url_;
    Poco::JSON::Object::Ptr root_;
};

#endif // UBUNTUIMAGEFETCHER_H