#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include "../Core/ActionResult.h"  // Core structure for processing results.

/**
 * IProcessor Interface
 * --------------------
 * This interface defines the contract for all processing systems within the pipeline.
 * It ensures consistent processing behavior and enables polymorphism in the PipelineManager.
 *
 * Responsibilities:
 * - Declares the Process method that all processing systems must implement.
 * - Provides a uniform interface for the PipelineManager to interact with different systems.
 */
class IProcessor {
public:
    /**
     * Virtual Destructor
     * ------------------
     * Ensures proper cleanup of derived classes.
     * Declared as default because no specific cleanup is required in the interface itself.
     */
    virtual ~IProcessor() = default;

    /**
     * Process Method (Pure Virtual)
     * -----------------------------
     * Pure virtual method that all derived processing systems must implement.
     * This method processes an ActionResult object and transforms it as needed.
     *
     * Parameters:
     * - item (ActionResult&): A reference to the ActionResult to be processed.
     */
    virtual void Process(ActionResult& item) = 0;
};

#endif
