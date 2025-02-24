
# ComputePipeline

This project is C++ pipeline processor.  
It is designed to demonstrate the flow of a data processing pipeline, supporting multiple file types such as images, JSON, and compressed files.  

⚠️ **Important:** This project is a simulation and does not perform real parsing or decompression. The purpose is to showcase the structure and flow of a pipeline architecture.

---

## **Features:**
- Modular design using **C++14** and **CMake**.
- Extensible architecture for adding new file types and systems.
- Simulates the processing flow of:
  - **Images (.jpg)**
  - **JSON files (.json)**
  - **Compressed files (.zip)**

---

## **Project Purpose:**
This project is designed to **demonstrate the flow of a data processing pipeline**.  
It serves as an example of how to:
- Design a **scalable pipeline architecture** for processing different file types.

### ⚠️ **No Real Parsing or Decompression:**
- The project does **not perform actual parsing** of images or JSON.
- It **simulates** the behavior of a parser or decompressor for demonstration purposes.
- The **decompression step** is simulated by **randomly generating a new file extension** to represent the extracted content.

---

## **How it Works:**
1. The pipeline **loads a file** using the appropriate loader (File, HTTP, or Bundle).
2. The file type is **detected based on its extension**.
3. The pipeline manager **passes the file through a series of processing systems**, depending on its type:
    - **Compressed Files (.zip):** 
      - Simulates decompression by **randomly changing the file extension** to `.jpg`, `.json`, or `.zip`.
      - This is for **demonstration purposes only** and does **not actually extract content**.
    - **Images (.jpg):** 
      - Simulates decoding by updating the content to **"Decoded Image"**.
    - **JSON Files (.json):** 
      - Simulates parsing by updating the content to **"JSON Parsed"**.
4. Each step **adds metadata** to the file, tracking the actions performed.
5. The pipeline **ends** when the file is fully processed.

---

## **Building and Running:**

### On Linux/MacOS (Using GCC/Clang)
```bash
mkdir build
cd build
cmake ..
make
./ComputePipeline
```

---

## Project Structure:
```bash
src/
├── main.cpp
├── Core/
│   ├── ActionResult.h            # Data structure for pipeline results.
│   ├── IProcessor.h              # Interface for processing systems.
│   └── ILoader.h                 # Interface for loaders.
├── Factories/
│   ├── LoaderFactory.h           # Factory to choose the appropriate loader.
│   └── PipelineManagerFactory.h  # Factory to create and configure the pipeline manager.
├── Systems/
│   ├── PipelineManager.h         # Manages the flow through the pipeline.
│   ├── DecompressSystem.h        # Simulates decompression (no real extraction).
│   ├── DecodeImageSystem.h       # Simulates image decoding.
│   ├── ParseJsonSystem.h         # Simulates JSON parsing.
│   └── UnknownFileSystem.h       # Handles unsupported file types.
├── Loaders/
│   ├── FileLoader.h              # Loads files from the local system.
│   ├── HttpLoader.h              # Loads files from HTTP/HTTPS URLs.
│   └── BundleLoader.h            # Loads files from bundle sources.
└── Utils/
    ├── RandomSelector.h          # Utility to simulate file extraction.
    └── TypeDetector.h            # Detects file types based on extensions.
```

---

## Output:
```plaintext
Processing: file://example.zip
Decompressing File...
New Type: IMAGE, Content: Decompressed Content
Decoding Image...
Source: file://example_internal.jpg
Protocol: file
Content: Decoded Image
Metadata:
 - File Uncompressed: .jpg
 - Action: Image Decoded
Processing Complete for: file://example_internal.jpg

