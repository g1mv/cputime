CPUTIME
=======
A simple multi-platform CPU user-mode chronometer

Branch|Linux & OSX|Windows
---|---|---
master|[![Build Status](https://travis-ci.org/k0dai/cputime.svg?branch=master)](https://travis-ci.org/k0dai/cputime)|[![Build status](https://ci.appveyor.com/api/projects/status/vfuxoenyd0y9iidx/branch/master?svg=true)](https://ci.appveyor.com/project/gpnuma/cputime/branch/master)
dev|[![Build Status](https://travis-ci.org/k0dai/cputime.svg?branch=dev)](https://travis-ci.org/k0dai/cputime)|[![Build status](https://ci.appveyor.com/api/projects/status/vfuxoenyd0y9iidx/branch/dev?svg=true)](https://ci.appveyor.com/project/gpnuma/cputime/branch/dev)

Build
-----
To build a static and dynamic library of CPUTime on Windows, Linux or Mac OSX,

1) Download [premake 5](http://premake.github.io/) and make it available in your path

2) Run the following from the command line

```
    git clone https://github.com/k0dai/cputime.git
    cd cputime/build
    premake5 gmake
    make
```

or alternatively, on Windows for example :

```
    premake5.exe vs2017
    msbuild CPUTime.sln
```

If msbuild.exe is not available in your path, just launch Visual Studio by double clicking on CPUTime.sln and build the library inside the IDE.

Quick start
-----------
```C
#include "cputime_api.h"

cputime_chronometer chrono;
cputime_chronometer_start(&chrono);
// Do something
double lap = cputime_chronometer_lap(&chrono);
// Do something else
double elapsed = cputime_chronometer_stop(&chrono);

// At any time, if needed, it's possible to get a timeval structure containing the total elapsed usermode time
struct timeval current_total_usertime = cputime_get_current_total_usertime();
```
