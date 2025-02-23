#ifndef HTTP_LOADER_H
#define HTTP_LOADER_H

#include "../Core/ILoader.h"         // Interface for all loaders.
#include "../Utils/TypeDetector.h"   // Utility for detecting file types.
#include <iostream>

/**
 * HttpLoader Class
 * ----------------
 * This class handles loading data from HTTP and HTTPS URLs.
 * It implements the ILoader interface, allowing it to be plugged into the LoaderFactory.
 *
 * Responsibilities:
 * - Detects the file type based on the URL.
 * - Identifies the protocol (http or https).
 * - Initializes the ActionResult with the content and metadata for URLs.
 */
class HttpLoader : public ILoader {
public:
    /**
     * Load Method (Override)
     * ----------------------
     * Loads data from a given HTTP or HTTPS URL.
     * This method is called by the LoaderFactory when the source starts with http:// or https://.
     *
     * Parameters:
     * - source (const std::string&): The URL containing the file path.
     *
     * Returns:
     * - ActionResult: The initialized ActionResult object ready for pipeline processing.
     */
    ActionResult Load(const std::string& source) override {
        // Log the loading action.
        std::cout << "Loading data from URL: " << source << "\n";

        // Detect the file type using the TypeDetector utility.
        DataType type = DetectFileType(source);

        // Identify the protocol (http or https).
        std::string protocol = (source.find("https://") == 0) ? "https" : "http";

        // Initialize the content description for URLs.
        std::string content = "Initial URL Content";

        // Create the ActionResult object.
        ActionResult item(type, source, protocol, content);

        // Add metadata specific to URLs.
        item.metadata["Loaded From"] = "URL";
        item.metadata["Source Path"] = source;

        // Return the initialized ActionResult.
        return item;
    }
};

#endif
