#ifndef PIPELINE_MANAGER_H
#define PIPELINE_MANAGER_H

#include "../Core/ActionResult.h"   // Core structure for processing results.
#include "../Core/IProcessor.h"     // Interface for all processing systems.
#include <memory>
#include <iostream>
#include <map>

/**
 * PipelineManager Class
 * ---------------------
 * This class manages the processing pipeline for ActionResult objects.
 * It coordinates the flow through various processing systems.
 *
 * Responsibilities:
 * - Directs the processing flow based on the type of ActionResult.
 * - Injects different processing systems via constructor for flexibility and testability.
 * - Manages the lifecycle and order of processing.
 * - Ensures that the pipeline stops when an item is fully processed.
 */
class PipelineManager {
public:
    /**
     * Constructor
     * -----------
     * Injects dependencies for each processing system.
     * This allows flexibility and makes the pipeline easily testable by enabling mocks.
     *
     * Parameters:
     * - decompress:  System for handling compressed files.
     * - decodeImage: System for decoding image files.
     * - parseJson:   System for parsing JSON files.
     * - unknownFile: System for handling unknown file types.
     */
    PipelineManager(
        std::unique_ptr<IProcessor> decompress,
        std::unique_ptr<IProcessor> decodeImage,
        std::unique_ptr<IProcessor> parseJson,
        std::unique_ptr<IProcessor> unknownFile)
        : decompressSystem(std::move(decompress)),
          decodeImageSystem(std::move(decodeImage)),
          parseJsonSystem(std::move(parseJson)),
          unknownFileSystem(std::move(unknownFile))
    {
    }

    /**
     * Process Method
     * ---------------
     * Manages the processing pipeline for a given ActionResult.
     * The pipeline continues until the item is fully processed (item.isProcessed = true).
     *
     * Workflow:
     * - Checks the type of ActionResult (COMPRESSED, IMAGE, JSON, UNKNOWN, etc.).
     * - Directs the item to the appropriate processing system:
     *     - COMPRESSED -> DecompressSystem
     *     - IMAGE      -> DecodeImageSystem
     *     - JSON       -> ParseJsonSystem
     *     - UNKNOWN    -> UnknownFileSystem
     * - If the type is not implemented, the pipeline stops for this item.
     *
     * Parameters:
     * - item (ActionResult&): A reference to the ActionResult to be processed.
     */
    void Process(ActionResult& item) {
        // Continue processing until the item is fully processed.
        while (!item.isProcessed) {
            if (item.type == DataType::COMPRESSED) {
                // Process using DecompressSystem.
                decompressSystem->Process(item);
            }
            else if (item.type == DataType::IMAGE) {
                // Process using DecodeImageSystem.
                decodeImageSystem->Process(item);
            }
            else if (item.type == DataType::JSON) {
                // Process using ParseJsonSystem.
                parseJsonSystem->Process(item);
            }
            else if (item.type == DataType::UNKNOWN) {
                // Process using UnknownFileSystem.
                unknownFileSystem->Process(item);
            }
            else {
                // Handle unimplemented types.
                std::cout << "Unimplemented Type Detected.\n";
                item.isProcessed = true;  // Stops the pipeline for this item.
            }
        }
    }

private:
    /**
     * Members
     * -------
     * These members store the injected processing systems.
     */
    std::unique_ptr<IProcessor> decompressSystem;
    std::unique_ptr<IProcessor> decodeImageSystem;
    std::unique_ptr<IProcessor> parseJsonSystem;
    std::unique_ptr<IProcessor> unknownFileSystem;
};

#endif
