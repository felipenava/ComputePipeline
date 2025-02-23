#ifndef PIPELINE_MANAGER_FACTORY_H
#define PIPELINE_MANAGER_FACTORY_H

#include "../Systems/PipelineManager.h"      // Pipeline Manager for orchestrating processing systems.
#include "../Systems/DecompressSystem.h"     // System for handling compressed files.
#include "../Systems/DecodeImageSystem.h"    // System for decoding image files.
#include "../Systems/ParseJsonSystem.h"      // System for parsing JSON files.
#include "../Systems/UnknownFileSystem.h"    // System for handling unknown file types.
#include <memory>

/**
 * PipelineManagerFactory Class
 * ----------------------------
 * This factory class is responsible for creating and configuring the PipelineManager.
 * It centralizes the instantiation of all processing systems used in the pipeline.
 *
 * Responsibilities:
 * - Creates and configures the PipelineManager with all necessary processing systems.
 * - Decides the order of systems in the pipeline.
 */
class PipelineManagerFactory {
public:
    /**
     * CreatePipelineManager Method (Static)
     * -------------------------------------
     * Static method to create a fully configured PipelineManager.
     * This method centralizes the order and inclusion of processing systems.
     *
     * Workflow:
     * - Creates unique pointers for each processing system:
     *     - DecompressSystem   -> Handles compressed files (.zip).
     *     - DecodeImageSystem  -> Handles image decoding (.jpg).
     *     - ParseJsonSystem    -> Handles JSON parsing (.json).
     *     - UnknownFileSystem  -> Handles unknown or unsupported file types.
     * - Returns a unique pointer to the configured PipelineManager.
     *
     * Returns:
     * - std::unique_ptr<PipelineManager>: A fully configured PipelineManager ready for processing.
     */
    static std::unique_ptr<PipelineManager> CreatePipelineManager() {
        // Creates the processing systems and determines their order in the pipeline.
        auto decompress = std::make_unique<DecompressSystem>();
        auto decodeImage = std::make_unique<DecodeImageSystem>();
        auto parseJson = std::make_unique<ParseJsonSystem>();
        auto unknownFile = std::make_unique<UnknownFileSystem>();

        // Dependency Injection in PipelineManager.
        return std::make_unique<PipelineManager>(
            std::move(decompress),
            std::move(decodeImage),
            std::move(parseJson),
            std::move(unknownFile)
        );
    }
};

#endif
