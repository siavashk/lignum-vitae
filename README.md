# lignum-vitae
Examples of Graph Traversals Using Boost


## Dependencies
This project only depends on [CMake](https://cmake.org/) and [Boost](https://www.boost.org). CMake can be downloaded from [here](https://cmake.org/download/).

There are many ways for installing Boost, but I prefer installation from source. These are the steps that I follow:

* Download the latest version from [here](ttps://www.boost.org/users/download/) and extract it contents.
* Navigate to extracted directory and run `./bootstrap.sh --prefix=./` for an in-source build.
* Build and install Boost by running `./b2 install`.

## Build
From your build directory call:

```bash
cmake $PATH_TO_SOURCE_DIR -G $GENERATOR -DBOOST_ROOT=$PATH_TO_BOOST_DIR
```

, where:

* `PATH_TO_SOURCE_DIR` is the location where you cloned this repository.
* [`GENERATOR`](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) is the build tool used for building this project.
* `PATH_TO_BOOST_DIR` is where you installed Boost.
