

#ifndef UBUNTUIMAGEFETCHER_H
#define UBUNTUIMAGEFETCHER_H

#include "IUbuntuImageFetcher.h"
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <string>
#include <vector>

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

    std::vector<std::string> getSupportedReleases() const override;
    std::string getCurrentLTSVersion() const override;
    std::string getDisk1ImageSHA256(const std::string& release) const override;

private:
    std::string fetchSimplestreamsData() const;
    Poco::JSON::Object::Ptr parseJson(const std::string& jsonData) const;
    std::string url_;
    Poco::JSON::Object::Ptr root_;
};

#endif // UBUNTUIMAGEFETCHER_H