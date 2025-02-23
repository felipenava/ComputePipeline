#ifndef DECODE_IMAGE_SYSTEM_H
#define DECODE_IMAGE_SYSTEM_H

#include "../Core/IProcessor.h"    // Interface for processing systems.
#include "../Core/ActionResult.h"  // Core structure for processing results.
#include <iostream>

/**
 * DecodeImageSystem Class
 * -----------------------
 * This class handles the processing of image files within the pipeline.
 * It implements the IProcessor interface, allowing it to be plugged into the pipeline architecture.
 *
 * Responsibilities:
 * - Simulates the decoding of an image file.
 * - Updates the ActionResult with a description of the decoded image.
 * - Adds metadata to track the decoding action.
 * - Marks the item as processed to end the pipeline for this ActionResult.
 */
class DecodeImageSystem : public IProcessor {
public:
    /**
     * Process Method (Override)
     * -------------------------
     * Handles ActionResult objects containing image data.
     * This method is called by the PipelineManager when the ActionResult type is IMAGE.
     *
     * Parameters:
     * - item (ActionResult&): A reference to the ActionResult to be processed.
     */
    void Process(ActionResult& item) override {
        // Log the action.
        std::cout << "Decoding Image...\n";

        // Set the content to indicate the image has been decoded.
        item.content = "Decoded Image";

        // Add metadata to track the action taken.
        item.metadata["Action"] = "Image Decoded";

        // Mark the item as processed to end the pipeline for IMAGE.
        item.isProcessed = true;
    }
};

#endif
