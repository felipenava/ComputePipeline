#ifndef ACTION_RESULT_H
#define ACTION_RESULT_H

#include <string>
#include <unordered_map>
#include <vector>

/**
 * DataType Enum
 * -------------
 * Enumerates the possible data types for an ActionResult.
 * Used to determine the appropriate processing system in the pipeline.
 *
 * Values:
 * - IMAGE      -> Represents image files (.jpg, etc.).
 * - JSON       -> Represents JSON data files (.json).
 * - COMPRESSED -> Represents compressed files (.zip).
 * - UNKNOWN    -> Represents unsupported or unidentified file types.
 */
enum class DataType {
    IMAGE,          // Image files (e.g., .jpg).
    JSON,           // JSON files (e.g., .json).
    COMPRESSED,     // Compressed files (e.g., .zip).
    UNKNOWN         // Unidentified or unsupported types.
};

/**
 * ActionResult Class
 * ------------------
 * This class encapsulates the result of a processing action within the pipeline.
 * It stores the state and metadata of a processed item, and is passed between systems in the pipeline.
 *
 * Responsibilities:
 * - Holds the source, type, and content of the item being processed.
 * - Stores metadata as key/value pairs for traceability and auditing.
 * - Tracks the processing state to determine when the pipeline should stop.
 * - Simulates a data buffer to represent file contents.
 */
class ActionResult {
public:
    /**
     * Members
     * -------
     * - type (DataType): The detected type of the item (IMAGE, JSON, COMPRESSED, UNKNOWN).
     * - source (std::string): The original source of the item (file path, URL, etc.).
     * - protocol (std::string): The protocol used (file, http, https, bundle, etc.).
     * - content (std::string): A description of the content or the processed result.
     * - isProcessed (bool): A flag indicating whether the item has been fully processed.
     * - metadata (std::unordered_map<std::string, std::string>): Key-value pairs for processing details.
     * - data (std::vector<char>): Simulated file data buffer (acts as a placeholder for actual content).
     */
    DataType type;    // Type of the data (IMAGE, JSON, COMPRESSED, UNKNOWN).
    std::string source;   // Original source of the item (file path, URL, etc.).
    std::string protocol; // Protocol used (file, http, https, bundle, etc.).
    std::string content;  // Description of the content or processed result.
    bool isProcessed;     // Flag to indicate if the item has been fully processed.
    std::unordered_map<std::string, std::string> metadata;  // Key-value pairs for traceability.
    std::vector<char> data; // Simulated file data buffer (placeholder for actual content).

    /**
     * Constructor
     * -----------
     * Initializes an ActionResult with the given type, source, protocol, and content.
     * By default, isProcessed is set to false, indicating that the item is not fully processed.
     *
     * Parameters:
     * - tp (DataType): The detected type of the item.
     * - sc (std::string): The original source of the item.
     * - pt (std::string): The protocol used.
     * - ct (std::string): A description of the content.
     */
    ActionResult(DataType tp, std::string sc, std::string pt, std::string ct)
        : type(tp), source(sc), protocol(pt), content(ct), isProcessed(false) {
    }
};

#endif
