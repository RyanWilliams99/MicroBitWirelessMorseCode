#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2019 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 27 // UTC day 1-31
#define YOTTA_BUILD_HOUR 11 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 51 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 42 // UTC second 0-61
#define YOTTA_BUILD_UUID 08ed2eb9-ee29-4a17-afbe-c896209e1e9a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 54a2d6b8bf8df5fe578485ee61e14d4756688700 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 54a2d6b // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
