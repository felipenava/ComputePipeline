#ifndef ILOADER_H
#define ILOADER_H

#include "../Core/ActionResult.h"  // Core structure for processing results.

/**
 * ILoader Interface
 * -----------------
 * This interface defines the contract for all loaders within the pipeline.
 * It ensures consistent loading behavior and enables polymorphism in the LoaderFactory.
 *
 * Responsibilities:
 * - Declares the Load method that all loaders must implement.
 * - Provides a uniform interface for the LoaderFactory to interact with different loaders.
 */
class ILoader {
public:
    /**
     * Virtual Destructor
     * ------------------
     * Ensures proper cleanup of derived classes.
     * Declared as default because no specific cleanup is required in the interface itself.
     */
    virtual ~ILoader() = default;

    /**
     * Load Method (Pure Virtual)
     * --------------------------
     * Pure virtual method that all derived loaders must implement.
     * This method loads data from the given source and initializes an ActionResult.
     *
     * Parameters:
     * - source (const std::string&): The source string containing the file path or URL.
     *
     * Returns:
     * - ActionResult: The initialized ActionResult object ready for pipeline processing.
     */
    virtual ActionResult Load(const std::string& source) = 0;
};

#endif
