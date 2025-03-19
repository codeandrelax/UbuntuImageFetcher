#include "UbuntuImageFetcher.hpp"
#include <iostream>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/URI.h>

/**
 * @file UbuntuImageFetcher.cpp
 * 
 * @author Damjan Prerad
 * @date March 19, 2025
 * 
 * @brief Implementation of the `UbuntuImageFetcher` class, which fetches and parses 
 * Ubuntu Cloud image information in Simplestreams format from a JSON endpoint.
 * 
 * This implementation extracts all Ubuntu releases for the `amd64` architecture.
 */

UbuntuImageFetcher::UbuntuImageFetcher(const std::string& url) 
    : url_(url) {
}

std::vector<std::string> UbuntuImageFetcher::getSupportedReleases() const {
    std::vector<std::string> releases;
    std::string jsonData = fetchSimplestreamsData();
    Poco::JSON::Object::Ptr root = parseJson(jsonData);
    if (!root) {
        std::cerr << "Failed to parse JSON data" << std::endl;
        return releases;
    }

    const Poco::JSON::Object::Ptr products = root->getObject("products");
    if (!products) {
        std::cerr << "No products object found in JSON data" << std::endl;
        return releases;
    }

    for (const auto& productEntry : *products) {
        const std::string& productKey = productEntry.first;
        const Poco::Dynamic::Var& productValue = productEntry.second;

        if (productValue.type() == typeid(Poco::JSON::Object::Ptr)) {
            Poco::JSON::Object::Ptr productObj = productValue.extract<Poco::JSON::Object::Ptr>();

            if (productObj->has("arch") && productObj->getValue<std::string>("arch") == "amd64") {
                if (productObj->has("release")) {
                    std::string release = productObj->getValue<std::string>("release");
                    releases.push_back(release);
                }
            }
        }
    }

    return releases;
}

std::string UbuntuImageFetcher::getCurrentLTSVersion() const {

    std::cout << "N/A";
    return "N/A";
}

std::string UbuntuImageFetcher::getDisk1ImageSHA256(const std::string& release) const {

    // return "SHA256 not found";
    return "UbuntuImageFetcher::getDisk1ImageSHA256";
}

std::string UbuntuImageFetcher::fetchSimplestreamsData() const {
    try {
        Poco::URI uri(url_);
        std::string host = uri.getHost();
        std::string path = uri.getPathAndQuery();

        Poco::Net::HTTPSClientSession session(host);
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPRequest::HTTP_1_1);
        Poco::Net::HTTPResponse response;

        session.sendRequest(request);

        if (response.getStatus() != Poco::Net::HTTPResponse::HTTP_OK) {
            throw std::runtime_error("Failed to fetch data. HTTP Status: " + std::to_string(response.getStatus()));
        }

        std::istream& inputStream = session.receiveResponse(response);
        std::string jsonData;
        Poco::StreamCopier::copyToString(inputStream, jsonData);

        return jsonData;

    } catch (const Poco::Exception& e) {
        std::cerr << "Poco Exception: " << e.displayText() << std::endl;
        return "";
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << std::endl;
        return "";
    }
}

Poco::JSON::Object::Ptr UbuntuImageFetcher::parseJson(const std::string& jsonData) const {
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result = parser.parse(jsonData);
    return result.extract<Poco::JSON::Object::Ptr>();
}