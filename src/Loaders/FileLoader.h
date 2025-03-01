#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "../Core/ILoader.h"         // Interface for all loaders.
#include "../Utils/TypeDetector.h"   // Utility for detecting file types.
#include <iostream>

/**
 * FileLoader Class
 * ----------------
 * This class handles loading data from the local file system.
 * It implements the ILoader interface, allowing it to be plugged into the LoaderFactory.
 *
 * Responsibilities:
 * - Detects the file type based on the file extension.
 * - Identifies the protocol as "file".
 * - Initializes the ActionResult with the content and metadata for file sources.
 * - Simulates data loading for test purposes.
 */
class FileLoader : public ILoader {
public:
    /**
     * Load Method (Override)
     * ----------------------
     * Loads data from a given local file path.
     * This method is called by the LoaderFactory when the source starts with file://.
     *
     * Parameters:
     * - source (const std::string&): The source string containing the file path.
     *
     * Returns:
     * - ActionResult: The initialized ActionResult object ready for pipeline processing.
     */
    ActionResult Load(const std::string& source) override {
        // Log the loading action.
        std::cout << "Loading file: " << source << "\n";

        // Detect the file type using the TypeDetector utility.
        DataType type = DetectFileType(source);

        // Identify the protocol as "file".
        std::string protocol = "file";

        // Initialize the content description for files.
        std::string content = "Initial File Content";

        // Create the ActionResult object.
        ActionResult item(type, source, protocol, content);

        // Add metadata specific to local files.
        item.metadata["Loaded From"] = "File System";
        item.metadata["Source Path"] = source;

        // Simulate loading file data.
        item.data = std::vector<char>(100, 'X'); // Placeholder 100 bytes of 'X'.

        // Return the initialized ActionResult.
        return item;
    }
};

#endif
