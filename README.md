# Universal private key derivation from master private key 

This repo produce a library for deriving private keys from a master key following this [slip](https://github.com/satoshilabs/slips/blob/master/slip-0010.md).
This repo only works with ed25519 curve types.

## Installing the library 

### From source code
```
git clone https://github.com/EddyTheCo/Qslip10.git 

mkdir build
cd build
qt-cmake -G Ninja -DCMAKE_INSTALL_PREFIX=installDir -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -DBUILD_DOCS=OFF ../Qslip10

cmake --build . 

cmake --install . 
```
where `installDir` is the installation path.
One can choose to build or not the tests and the documentation with the `BUILD_TESTING` and `BUILD_DOCS` variables.

### From GitHub releases
Download the releases from this repo. 

## Adding the libraries to your CMake project 

```CMake
include(FetchContent)
FetchContent_Declare(
	QtSlip10	
	GIT_REPOSITORY https://github.com/EddyTheCo/Qslip10.git
	GIT_TAG v0.1.0 
	FIND_PACKAGE_ARGS 0.1 CONFIG  
	)
FetchContent_MakeAvailable(QtSlip10)
target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> QtSlip10::qslip10)
```
## API reference

You can read the [API reference](https://eddytheco.github.io/Qslip10/) here, or generate it yourself like
```
cmake -DBUILD_DOCS=ON ../
cmake --build . --target doxygen_docs
```

## Contributing

We appreciate any contribution!


You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.
