#include "Core/ActionResult.h"                      // Core structure for processing results.
#include "Factories/PipelineManagerFactory.h"       // Factory for creating a fully configured PipelineManager.
#include "Factories/LoaderFactory.h"                // Factory for selecting the appropriate Loader.
#include <vector>
#include <memory>
#include <iostream>

int main() 
{
    // List of input sources to be processed.
    // Each source can be a file, URL, or bundle.
    std::vector<std::string> inputs = {
        "file://example.zip",
        "http://example.jpg",
        "https://example.json",
        "bundle://example.zip",
        "ftp://example.jpg",  // Wrong Case (ftp).
        "file://example.exe", // Wrong Test (.exe).
    };

    // Iterate through each input source to process them one by one.
    for (auto& source : inputs) {
        std::cout << "\nProcessing: " << source << "\n";

        /**
         * Loader Selection
         * ----------------
         * Use LoaderFactory to select the appropriate Loader for the source.
         * The selection is based on the protocol (file://, http://, https://, bundle://, etc.).
         * If no suitable Loader is found, the source is skipped.
         */
        std::unique_ptr<ILoader> loader = LoaderFactory::CreateLoader(source);

        if (loader == nullptr) {
            std::cerr << "No suitable Loader for: " << source << "\n";
            continue; // Skip this source and continue to the next one.
        }

        /**
         * Load the Item
         * -------------
         * Use the selected Loader to load the source.
         * The Loader initializes an ActionResult object with the source's details.
         * This includes the source's content, protocol, and metadata.
         */
        ActionResult item = loader->Load(source);

        /**
         * Create PipelineManager
         * ----------------------
         * Use the PipelineManagerFactory to create a fully configured PipelineManager.
         * The PipelineManager is responsible for processing the ActionResult through a series of transformations.
         * This design allows easy expansion and maintenance by configuring the pipeline in one place.
         */
        std::unique_ptr<PipelineManager> pipelineManager = PipelineManagerFactory::CreatePipelineManager();

        /**
         * Process the Item
         * ----------------
         * Pass the loaded ActionResult to the PipelineManager.
         * The PipelineManager:
         * - Detects the type of data (IMAGE, JSON, COMPRESSED, UNKNOWN, etc.).
         * - Chooses the appropriate processing system (e.g., Decompress, DecodeImage, ParseJSON).
         * - Transforms the item through the pipeline until fully processed.
         */
        pipelineManager->Process(item);

        /**
         * Output the Final Result
         * -----------------------
         * After processing, print the final state of the ActionResult.
         * This includes:
         * - Source: The original input source.
         * - Protocol: The detected protocol (file, http, https, bundle, etc.).
         * - Content: The processed content description.
         * - Metadata: Key/value pairs containing processing details and actions taken.
         */
        std::cout << "Source: "   << item.source   << "\n";
        std::cout << "Protocol: " << item.protocol << "\n";
        std::cout << "Content: "  << item.content  << "\n";

        std::cout << "Metadata:\n";
        for (const auto& meta : item.metadata) {
            std::cout << " - " << meta.first << ": " << meta.second << "\n";
        }
        std::cout << "Processing Completed for: " << item.source << "\n";
    }

    return 0;
}
