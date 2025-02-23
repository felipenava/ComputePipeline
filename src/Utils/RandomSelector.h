#ifndef RANDOM_SELECTOR_H
#define RANDOM_SELECTOR_H

#include <vector>
#include <string>
#include <cstdlib>  // For std::rand() and std::srand()
#include <ctime>    // For std::time()

/**
 * RandomSelector Utility
 * ----------------------
 * Utility for selecting a random file extension.
 * This utility is used to simulate the decompression of files by randomly assigning new extensions.
 *
 * Responsibilities:
 * - Randomly selects an extension from a predefined list.
 * - Initializes the random seed only once to ensure randomness across executions.
 * - Returns the selected extension as a string.
 */

 /**
  * GetRandomExtension Function
  * ---------------------------
  * Selects a random extension from a predefined list of possible extensions.
  * This function is used in the DecompressSystem to simulate the output of decompressed files.
  *
  * Workflow:
  * - Initializes the random seed only once to ensure randomness.
  * - Chooses a random extension from the list:
  *     - .jpg  -> Simulates an image output.
  *     - .json -> Simulates a JSON output.
  *     - .zip  -> Simulates a nested compressed file.
  *
  * Returns:
  * - std::string: The randomly selected extension.
  */
inline std::string GetRandomExtension() {
    // Initialize the seed only once, on the first call.
    static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(static_cast<unsigned int>(time(nullptr)));  // Seed for randomness.
        seedInitialized = true;                           // Mark as initialized.
    }

    // Possible extensions for decompressed files (constant and reusable).
    static const std::vector<std::string> extensions = { ".jpg", ".json", ".zip" };

    // Randomly select an extension.
    return extensions[std::rand() % extensions.size()];
}

#endif
