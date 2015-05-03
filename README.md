CPUTIME
=======
A simple multi-platform CPU user-mode chronometer

Build
-----
To build a static and dynamic library of CPUTime on Windows, Linux or Mac OSX,

1. Download [premake](http://premake.github.io/) and make it available in your path
2. Run the following from the command line :
> cd build
> premake4 gmake
or alternatively, on windows for example :
> premake4.exe vs2010
> make

Quick start
-----------
```C
#include "cputime.h"

cputime_chronometer chrono;
cputime_chronometer_start(&chrono);
// Do something
double elapsed = cputime_chronometer_stop(&chrono);

// At any time if needed, it's possible to access the timeval structure of the total elapsed usermode time
struct timeval current_total_usertime = cputime_get_current_total_usertime();