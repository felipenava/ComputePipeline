#ifndef BUNDLE_LOADER_H
#define BUNDLE_LOADER_H

#include "../Core/ILoader.h"         // Interface for all loaders.
#include "../Utils/TypeDetector.h"   // Utility for detecting file types.
#include <iostream>

/**
 * BundleLoader Class
 * ------------------
 * This class handles loading data from bundle sources.
 * It implements the ILoader interface, allowing it to be plugged into the LoaderFactory.
 *
 * Responsibilities:
 * - Detects the file type based on the bundle's file extension.
 * - Identifies the protocol as "bundle".
 * - Initializes the ActionResult with the content and metadata for bundles.
 */
class BundleLoader : public ILoader {
public:
    /**
     * Load Method (Override)
     * ----------------------
     * Loads data from a given bundle source.
     * This method is called by the LoaderFactory when the source starts with bundle://.
     *
     * Parameters:
     * - source (const std::string&): The source string containing the bundle path.
     *
     * Returns:
     * - ActionResult: The initialized ActionResult object ready for pipeline processing.
     */
    ActionResult Load(const std::string& source) override {
        // Log the loading action.
        std::cout << "Loading data from Bundle: " << source << "\n";

        // Detect the file type using the TypeDetector utility.
        DataType type = DetectFileType(source);

        // Identify the protocol as "bundle".
        std::string protocol = "bundle";

        // Initialize the content description for bundles.
        std::string content = "Initial Bundle Content";

        // Create the ActionResult object.
        ActionResult item(type, source, protocol, content);

        // Add metadata specific to bundles.
        item.metadata["Loaded From"] = "Bundle";
        item.metadata["Source Path"] = source;

        // Return the initialized ActionResult.
        return item;
    }
};

#endif
