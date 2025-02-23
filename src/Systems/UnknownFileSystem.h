#ifndef UNKNOWN_FILE_SYSTEM_H
#define UNKNOWN_FILE_SYSTEM_H

#include "../Core/IProcessor.h"     // Interface for processing systems.
#include "../Core/ActionResult.h"   // Core structure for processing results.
#include <iostream>

/**
 * UnknownFileSystem Class
 * -----------------------
 * This class handles unknown file types that are not supported by the pipeline.
 * It implements the IProcessor interface, ensuring it can be plugged into the processing pipeline.
 *
 * Responsibilities:
 * - Detect when a file type is unsupported.
 * - Mark the file as processed to stop further processing.
 */
class UnknownFileSystem : public IProcessor {
public:
    /**
     * Process Method (Override)
     * -------------------------
     * Handles ActionResult objects with unknown or unsupported file types.
     * This method is called by the PipelineManager when no other system can process the file.
     *
     * Parameters:
     * - item (ActionResult&): A reference to the ActionResult to be processed.
     */
    void Process(ActionResult& item) override {
        // Log the action.
        std::cout << "Unknown File Type Detected: " << item.source << "\n";

        // Set the content to indicate that the file type is not supported.
        item.content = "Unsupported File Type";

        // Add metadata to track the action (or lack of action).
        item.metadata["Action"] = "No action";

        // Mark the item as processed to stop the pipeline.
        item.isProcessed = true;
    }
};

#endif