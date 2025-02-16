<!---
Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
SPDX-License-Identifier: Apache-2.0
--->
# Palace: 3D Finite Element Solver for Computational Electromagnetics-GSLIB-WINDOWS

# PACKAGE INSTALL
Msys2 UCRT64 compiler for windows is required, it contains gcc, fortran, GNU-make.

1. Set proxy(if needed)
```
export https_proxy=http://192.168.8.5:7890
export http_proxy=http://192.168.8.5:7890
```

2. Install CMAKE
```
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-cmake
```
3. Install MS-MPI
```
pacman -S mingw-w64-ucrt-x86_64-msmpi
```
4. Install OPENBLAS
```
pacman -S mingw-w64-ucrt-x86_64-openblas
pacman -S mingw-w64-ucrt-x86_64-openblas64
```
# INSTALL
```
cmake -G "MinGW Makefiles" ..
make
```

The libgs.a file is in build\lib\libgs.a