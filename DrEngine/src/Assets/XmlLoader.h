#pragma once
#include <memory>
#include <fstream>
#include <stdexcept>
#include "IAssetLoader.h"
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

struct XmlAsset {
    std::shared_ptr<std::string> text;
    std::shared_ptr<rapidxml::xml_document<>> doc;
};

class XmlLoader : public IAssetLoader {
public:
    std::shared_ptr<void> load(const std::string& path) override {
        // Read
        std::ifstream file(path);
        if (!file) throw std::runtime_error("Cannot open XML file: " + path);

        std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        auto xmlCopy = std::make_shared<std::string>(std::move(buffer));

        // Parse XML
        auto doc = std::make_shared<rapidxml::xml_document<>>();
        doc->parse<0>(&(*xmlCopy)[0]); //RapidXML needs non-const char*

        // 3Wrap both buffer and document
        auto asset = std::make_shared<XmlAsset>();
        asset->text = xmlCopy;
        asset->doc = doc;

        return asset;
    }
};
