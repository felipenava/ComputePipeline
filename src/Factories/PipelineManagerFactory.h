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
 * Factory responsible for creating and configuring a PipelineManager instance.
 * Centralizes the instantiation and registration of processing systems used in the pipeline.
 *
 * Responsibilities:
 * - Creates an instance of PipelineManager.
 * - Registers processing systems dynamically using the RegisterProcessor method.
 * - Ensures modularity and extensibility by allowing easy addition of new processors.
 *
 * Methods:
 * - CreatePipelineManager: Instantiates and configures a PipelineManager with predefined processors.
 */
class PipelineManagerFactory {
public:
    /**
     * CreatePipelineManager Method (Static)
     * -------------------------------------
     * Creates and configures a PipelineManager instance with predefined processing systems.
     * This method ensures that the pipeline is ready for processing different data types.
     *
     * Workflow:
     * - Instantiates a PipelineManager.
     * - Registers various processing systems dynamically:
     *     - DecompressSystem -> Handles compressed files (.zip).
     *     - DecodeImageSystem -> Handles image decoding (.jpg).
     *     - ParseJsonSystem -> Handles JSON parsing (.json).
     *     - UnknownFileSystem -> Handles unknown or unsupported file types.
     * - Returns a unique pointer to the fully configured PipelineManager.
     *
     * Returns:
     * - std::unique_ptr<PipelineManager>: A fully configured PipelineManager ready for processing.
     */
    static std::unique_ptr<PipelineManager> CreatePipelineManager() {
        auto pipeline = std::make_unique<PipelineManager>();
        pipeline->RegisterProcessor(DataType::COMPRESSED, std::make_unique<DecompressSystem>());
        pipeline->RegisterProcessor(DataType::IMAGE, std::make_unique<DecodeImageSystem>());
        pipeline->RegisterProcessor(DataType::JSON, std::make_unique<ParseJsonSystem>());
        pipeline->RegisterProcessor(DataType::UNKNOWN, std::make_unique<UnknownFileSystem>());
        return pipeline;
    }
};

#endif
