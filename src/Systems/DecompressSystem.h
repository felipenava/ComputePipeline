#ifndef DECOMPRESS_SYSTEM_H
#define DECOMPRESS_SYSTEM_H

#include "../Core/IProcessor.h"       // Interface for processing systems.
#include "../Core/ActionResult.h"     // Core structure for processing results.
#include "../Utils/TypeDetector.h"    // Utility for detecting file types.
#include "../Utils/RandomSelector.h"  // Utility for selecting random extensions.
#include <iostream>
#include <vector>

/**
 * DecompressSystem Class
 * ----------------------
 * This class handles the processing of compressed files within the pipeline.
 * It implements the IProcessor interface, allowing it to be plugged into the pipeline architecture.
 *
 * Responsibilities:
 * - Simulates the decompression of a file.
 * - Generates a new file extension randomly for the decompressed content.
 * - Updates the ActionResult with the new source and type.
 * - Adds metadata to track the decompression action.
 */
class DecompressSystem : public IProcessor {
public:
    /**
     * Process Method (Override)
     * -------------------------
     * Handles ActionResult objects containing compressed data.
     * This method is called by the PipelineManager when the ActionResult type is COMPRESSED.
     *
     * Parameters:
     * - item (ActionResult&): A reference to the ActionResult to be processed.
     */
    void Process(ActionResult& item) override {
        // Log the action.
        std::cout << "Decompressing File...\n";

        // (IMPORTANT) Randomly generates a new file extension for the decompressed content.
        // This is not necessary for the processing itself, but is used to simulate the output
        // of a decompression action, making it look like a new file was extracted from the compressed one.
        std::string newExtension = GetRandomExtension();

        // (IMPORTANT) Update the source and content to reflect the decompressed state.
        // This line is purely for simulation purposes. It is not required for the actual pipeline logic,
        // but is used to demonstrate how the source might change after decompression (e.g., .zip -> .jpg).
        std::string newSource = item.source.substr(0, item.source.find_last_of('.')) + newExtension;
        item.source = newSource;
        item.content = "Decompressed Content";

        // Detect and set the next type for the ActionResult.
        item.type = DetectFileType(newSource);

        // Add metadata to track the action and the new extension.
        item.metadata["File Uncompressed"] = newExtension;
        item.metadata["Action"] = "File Decompressed";
    }
};

#endif
