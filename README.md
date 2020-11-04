# Kit

ANSI C utility library!

## Build

You will need `meson` in order to build the library.

Build the library by running this in the root of the repository:

```bash
meson builddir --buildtype release
cd builddir
meson compile
```

(Optionally do `--buildtype debug` instead if you would like to keep debugging information and turn optimizations off, e.g., if you want to do development.)

## Run the tests

Run the tests by running this in the build directory:

```bash
meson test
```

## Install

And when you are ready to install the library do this in the build directory:

```bash
meson install
```
