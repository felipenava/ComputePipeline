#ifndef PARSE_JSON_SYSTEM_H
#define PARSE_JSON_SYSTEM_H

#include "../Core/IProcessor.h"    // Interface for processing systems
#include "../Core/ActionResult.h"  // Core structure for processing results
#include <iostream>

/**
 * ParseJsonSystem Class
 * ---------------------
 * This class handles the processing of JSON files within the pipeline.
 * It implements the IProcessor interface, allowing it to be plugged into the pipeline architecture.
 *
 * Responsibilities:
 * - Detects and processes JSON data.
 * - Transforms the JSON content into a simulated C++ object.
 * - Marks the item as processed to end the pipeline for this ActionResult.
 */
class ParseJsonSystem : public IProcessor {
public:
    /**
     * Process Method (Override)
     * -------------------------
     * Handles ActionResult objects containing JSON data.
     * This method is called by the PipelineManager when the ActionResult type is JSON.
     *
     * Parameters:
     * - item (ActionResult&): A reference to the ActionResult to be processed.
     */
    void Process(ActionResult& item) override {
        // Log the action.
        std::cout << "Converting JSON to C++ Object...\n";

        // Set the content to indicate JSON has been parsed.
        item.content = "JSON Parsed";

        // Add metadata to track the action taken.
        item.metadata["Action"] = "JSON Parsed";

        // Mark the item as processed to end the pipeline for JSON.
        item.isProcessed = true;
    }
};

#endif
