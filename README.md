# Esterv.Crypto.Slip10

[TOC]

This repo produce a library for deriving private keys from a master key following this [slip](https://github.com/satoshilabs/slips/blob/master/slip-0010.md).
This repo only works with ed25519 curve types.

## Configure, build, test, package ...
 
The project uses [CMake presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) as a way to share CMake configurations.
Refer to [cmake](https://cmake.org/cmake/help/latest/manual/cmake.1.html), [ctest](https://cmake.org/cmake/help/latest/manual/ctest.1.html) and [cpack](https://cmake.org/cmake/help/latest/manual/cpack.1.html) documentation for more information on the use of presets.

## Adding the libraries to your CMake project 

```CMake
include(FetchContent)
FetchContent_Declare(
	EstervSlip10
	GIT_REPOSITORY https://github.com/EddyTheCo/Esterv.Crypto.Slip10.git
	GIT_TAG vMAJOR.MINOR.PATCH
	FIND_PACKAGE_ARGS MAJOR.MINOR CONFIG
	)
FetchContent_MakeAvailable(EstervSlip10)
target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> Esterv::slip10)
```

## API reference

You can read the [API reference](https://eddytheco.github.io/Esterv.Crypto.Slip10/) here, or generate it yourself like

```
cmake --workflow --preset default-documentation
```

## Contributing

We appreciate any contribution!


You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.
