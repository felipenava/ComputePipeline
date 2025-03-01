#ifndef PIPELINE_MANAGER_H
#define PIPELINE_MANAGER_H

#include "../Systems/PipelineManager.h"      // Pipeline Manager for orchestrating processing systems.
#include "../Systems/DecompressSystem.h"     // System for handling compressed files.
#include "../Systems/DecodeImageSystem.h"    // System for decoding image files.
#include "../Systems/ParseJsonSystem.h"      // System for parsing JSON files.
#include "../Systems/UnknownFileSystem.h"    // System for handling unknown file types.
#include <memory>
#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * PipelineManager Class
 * ---------------------
 * Manages the processing pipeline for ActionResult objects.
 * Handles registration and execution of different processing systems dynamically.
 *
 * Responsibilities:
 * - Registers and manages processing systems dynamically.
 * - Processes ActionResult objects based on their DataType.
 * - Ensures that an item is fully processed before completing its pipeline execution.
 * - Allows easy extension by adding new processing systems without modifying core logic.
 *
 * Methods:
 * - RegisterProcessor: Registers a processing system for a specific DataType.
 * - Process: Executes the appropriate processors for a given ActionResult.
 */
class PipelineManager {
public:
    /**
     * Registers a processing system for a specific DataType.
     *
     * Parameters:
     * - type (DataType): The type of data that the processor handles.
     * - processor (std::unique_ptr<IProcessor>): The processor instance to register.
     */
    void RegisterProcessor(DataType type, std::unique_ptr<IProcessor> processor) {
        processors[type].emplace_back(std::move(processor));
    }

    /**
     * Processes an ActionResult object through the pipeline.
     *
     * Workflow:
     * - Identifies the appropriate processors based on the ActionResult type.
     * - Iterates through all registered processors for that type and executes them.
     * - Stops execution if the item is marked as processed.
     * - Logs a message if no processor is available for the given type.
     *
     * Parameters:
     * - item (ActionResult&): The ActionResult to be processed.
     */
    void Process(ActionResult& item) {
        if (processors.find(item.type) != processors.end()) {
            for (auto& processor : processors[item.type]) {
                processor->Process(item);
                if (item.isProcessed) break;
            }
        }
        else {
            std::cout << "No processor found for type: " << static_cast<int>(item.type) << "\n";
            item.isProcessed = true;
        }
    }

private:
    /**
     * Stores the registered processing systems.
     * Each DataType maps to a vector of processors, allowing multiple processors per type.
     */
    std::unordered_map<DataType, std::vector<std::unique_ptr<IProcessor>>> processors;
};

#endif
