#ifndef LOADER_FACTORY_H
#define LOADER_FACTORY_H

#include "../Core/ILoader.h"            // Interface for all loaders.
#include "../Loaders/FileLoader.h"      // Loader for file:// protocol.
#include "../Loaders/HttpLoader.h"      // Loader for http:// and https:// protocols.
#include "../Loaders/BundleLoader.h"    // Loader for bundle:// protocol.
#include <memory>
#include <iostream>

/**
 * LoaderFactory Class
 * -------------------
 * This factory class is responsible for selecting the appropriate Loader
 * based on the source's protocol. It centralizes the logic for protocol detection
 * and Loader instantiation.
 *
 * Responsibilities:
 * - Detects the protocol of the source (file://, http://, https://, bundle://).
 * - Instantiates the appropriate Loader for the detected protocol.
 * - Returns a unique pointer to the created Loader.
 * - Returns nullptr if no suitable Loader is found.
 */
class LoaderFactory {
public:
    /**
     * CreateLoader Method (Static)
     * ----------------------------
     * Static method to create a Loader based on the source's protocol.
     * This method detects the protocol and instantiates the corresponding Loader.
     *
     * Supported Protocols:
     * - file://                -> Uses FileLoader
     * - http:// and https://   -> Uses HttpLoader
     * - bundle://              -> Uses BundleLoader
     * - Any other protocol is considered unsupported.
     *
     * Parameters:
     * - source (const std::string&): The source string containing the file path or URL.
     *
     * Returns:
     * - std::unique_ptr<ILoader>: A unique pointer to the appropriate Loader.
     * - nullptr if no suitable Loader is found.
     */
    static std::unique_ptr<ILoader> CreateLoader(const std::string& source) {
        // Check for file:// protocol and return FileLoader.
        if (source.find("file://") == 0) {
            return std::make_unique<FileLoader>();
        }
        // Check for http:// or https:// protocols and return HttpLoader.
        else if (source.find("http://") == 0 || source.find("https://") == 0) {
            return std::make_unique<HttpLoader>();
        }
        // Check for bundle:// protocol and return BundleLoader.
        else if (source.find("bundle://") == 0) {
            return std::make_unique<BundleLoader>();
        }
        // If no known protocol is detected, log an error and return nullptr.
        else {
            std::cerr << "Unknown protocol: " << source << "\n";
            return nullptr;
        }
    }
};

#endif
