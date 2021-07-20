# Machine Learning Image Denoiser

This project uses the [Intel Open Image Denoiser](https://github.com/OpenImageDenoise/oidn) to denoise raytraced images.
It is built using [QT](https://www.qt.io/).

## Compilation

### Prerequisites

Install the [Git Large File Storage (LFS)](https://git-lfs.github.com/) extension to clone this repository.
Afterwards you can clone the project from this repository using the following command:

    git clone --recursive https://github.com/tobieder/MLImageDenoiser.git
    
And initialize the OIDN submodule using:

    git submodule update --init --recursive
    
Install and compile OIDN as described in the [README.md](https://github.com/OpenImageDenoise/oidn/blob/master/README.md#prerequisites).
Install the TBB libraries into the following directory `oidn\vendor\tbb`.

### Compiling

Using `CMake` to build a Visual Studio solution (tested on VS 2019) into a `build` directory.

    cd path/to/MLImageDenoiser
    mkdir build
    cd build
    cmake "Visual Studio 16 2019 Win64" ..
    cmake --build . --config Release
    
Precompiled binaries are available for download.
