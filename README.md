# Machine Learning Image Denoiser

This project uses the [Intel Open Image Denoiser](https://github.com/OpenImageDenoise/oidn) to denoise raytraced images.
It is built using [QT](https://www.qt.io/).

## Compilation

### Prerequisites

To compile this repository you need the following prerequisites:

- CMake 3.1 or later
- Visual Studio 2019
- Python 2.7 or later
- QT 5.12.2

Clone the repository by using the following command:

    git clone https://github.com/tobieder/MLImageDenoiser.git
    
## Compiling
    
Go to the `scripts` directory and execute the `_SETUP.py`. This will download the matching oidn binaries for your operating system.

Use `CMake` to build a Visual Studio solution (tested on VS 2019) into a `build` directory by executing the following commands:

    cd path/to/MLImageDenoiser
    mkdir build
    cd build
    cmake "Visual Studio 16 2019 Win64" ..
    cmake --build . --config Release
    
Precompiled executables are available for download.
