#ifndef TYPE_DETECTOR_H
#define TYPE_DETECTOR_H

#include "../Core/ActionResult.h"  // Core structure for processing results.
#include <string>

/**
 * TypeDetector Utility
 * --------------------
 * Utility function for detecting the type of file based on its extension.
 * It determines the DataType of an ActionResult by examining the source's file extension.
 *
 * Supported File Types:
 * - .jpg   -> IMAGE
 * - .json  -> JSON
 * - .zip   -> COMPRESSED
 * - Any other extension is considered UNKNOWN.
 */

 /**
  * DetectFileType Function
  * -----------------------
  * Detects the file type of the given source string based on its extension.
  * This function is used in the pipeline to determine the appropriate processing system.
  *
  * Parameters:
  * - source (const std::string&): The source string containing the file path or URL.
  *
  * Returns:
  * - DataType: The detected type of the file (IMAGE, JSON, COMPRESSED, or UNKNOWN).
  */
DataType DetectFileType(const std::string& source) {
    if (source.find(".jpg") != std::string::npos)
        return DataType::IMAGE;
    if (source.find(".json") != std::string::npos)
        return DataType::JSON;
    if (source.find(".zip") != std::string::npos)
        return DataType::COMPRESSED;

    // Any other extension is considered UNKNOWN.
    return DataType::UNKNOWN;
}

#endif
