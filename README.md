# pipeline-test

A simple C++ example project built with CMake, with an Azure DevOps CI pipeline.

## Project structure

```
.
├── CMakeLists.txt          # CMake build configuration
├── azure-pipelines.yml     # Azure DevOps pipeline
└── src/
    ├── calculator.h        # Calculator class declaration
    ├── calculator.cpp      # Calculator class implementation
    └── main.cpp            # Entry point
```

## Build locally

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
./build/calculator
```

## CI pipeline

The `azure-pipelines.yml` file defines an Azure DevOps pipeline that:

1. **Configures** the project with CMake (Release mode)
2. **Builds** the project
3. **Runs** the resulting binary as a smoke-test
