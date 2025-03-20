# UbuntuImageFetcher

UbuntuImageFetcher is a C++ project that fetches the latest Ubuntu Cloud image information in Simplestreams format. 
This application uses the Poco C++ Libraries for handling networking and JSON parsing.

## Tested on:

`Ubuntu 22.04.4 LTS`

`macOS Sonoma Version 14.3`

`Windows 11`

## Dependencies

This project relies on the Poco library for network communication and JSON handling. 
You need to install Poco on your system before compiling and running the project.

### Installation

#### Linux (Ubuntu-based)

To install the Poco library on Linux (Ubuntu-based distributions), use the following command:

```
sudo apt-get install libpoco-dev
```

#### MacOS

To install Poco on macOS use Homebrew.

```
brew install poco
```

#### Windows

```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
vcpkg install poco[netssl] --triplet x64-windows
```

When running `cmake` command make sure to do it like this:
```
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:\path\to\vcpkg\scripts\buildsystems\vcpkg.cmake
```

Building from source is also an option [here](https://docs.pocoproject.org/current/00200-GettingStarted.html)

## Building the Project

### For Linux (Ubuntu) and macOS:
```
git clone <repo-url>
cd <repo-directory>
mkdir build
cd build
cmake ..
make
```

To run (eg.):
```
./UbuntuImageFetcher --supported-releases
```

### For Windows
```
git clone <repo-url>
cd <repo-directory>
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:\path\to\vcpkg\scripts\buildsystems\vcpkg.cmake
cmake --build . --config Release
```

Once build, executable will be found under a name `UbuntuImageFetcher`.

Before you're able to run the executable, you need to set path to `SSL_CERT_FILE`
Windows doesn't have default CA certificates set.
You can download them from [here](https://curl.se/docs/caextract.html)
Do so with:
```
 $env:SSL_CERT_FILE = <path_to_downloaded_cacert\cacert.pem>
```

To run the executable (eg.):
```
cd Release
.\UbuntuImageFetcher.exe --supported-releases
```

#### Testing
To run tests:

```
ctest
```

## Ubuntu Image Fetcher CLI

This program allows you to interact with the Ubuntu Image Fetcher through a command-line interface (CLI). 

```
./ubuntu_image_fetcher --option [arguments]
```

### Options:

#### --supported-releases

Command:

```
./UbuntuImageFetcher --supported-releases
```

Output:

```
hirsute
impish
jammy
kinetic
lunar
mantic
noble
oracular
...
```

#### --current-lts

Command:

```
./UbuntuImageFetcher --current-lts
```

Output:

```
24.04 LTS
```

#### --sha256 <release>

Command:

```
./UbuntuImageFetcher --sha256 noble
```

Output:

```
32a9d30d18803da72f5936cf2b7b9efcb4d0bb63c67933f17e3bdfd1751de3f3
```

