/*
 * Centaurean Chronometer
 *
 * Copyright (c) 2015, Guillaume Voirin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this
 *        list of conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright notice,
 *        this list of conditions and the following disclaimer in the documentation
 *        and/or other materials provided with the distribution.
 *
 *     3. Neither the name of the copyright holder nor the names of its
 *        contributors may be used to endorse or promote products derived from
 *        this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * 3/05/15 17:52
 */

#ifndef CHRONOMETER_API_H
#define CHRONOMETER_API_H

#if defined(_WIN64) || defined(_WIN32)
#include <time.h>

#define CHRONOMETER_WINDOWS_EXPORT  __declspec(dllexport)
#else

#include <sys/resource.h>

#define CHRONOMETER_WINDOWS_EXPORT
#endif

typedef enum {
    CHRONOMETER_STATE_IDLE, CHRONOMETER_STATE_RUNNING
} CHRONOMETER_STATE;

typedef struct {
    struct timeval start;
    struct timeval lap;
    struct timeval stop;
    CHRONOMETER_STATE state;
} chronometer;

/*
 * Get the current running task's total usertime
 *
 * @return a timeval structure containing the current running task's total usertime
 */
CHRONOMETER_WINDOWS_EXPORT struct timeval chronometer_get_current_time();

/*
 * Start a chronometer
 *
 * @param chronometer a usertime chronometer structure
 */
CHRONOMETER_WINDOWS_EXPORT void chronometer_start(chronometer *chrono);

/*
 * Get a lap time in seconds (time since the last start or lap function was used)
 *
 * @param chronometer a usertime chronometer structure
 */
CHRONOMETER_WINDOWS_EXPORT double chronometer_lap(chronometer *chrono);

/*
 * Stop the chronometer, and get time since its start in seconds
 *
 * @param chronometer a usertime chronometer structure
 */
CHRONOMETER_WINDOWS_EXPORT double chronometer_stop(chronometer *chrono);

#endif