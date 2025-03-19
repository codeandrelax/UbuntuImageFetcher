# UbuntuImageFetcher

UbuntuImageFetcher is a C++ project that fetches the latest Ubuntu Cloud image information in Simplestreams format. 
This application uses the Poco C++ Libraries for handling networking and JSON parsing.

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

For windows use precompiled package.

Building from source is also an option [here](https://docs.pocoproject.org/current/00200-GettingStarted.html)

## Building the Project

```
git clone <repo-url>
cd <repo-directory>
mkdir build
cd build
cmake ..
make
```
