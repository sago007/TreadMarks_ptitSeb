// This file is part of Tread Marks
// 
// Tread Marks is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tread Marks is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tread Marks.  If not, see <http://www.gnu.org/licenses/>.

#include "../Directories.h"
#include "cifm.h"
#include <sys/stat.h>

CStr GetAppDataDir()
{
    static char* appdata = NULL;
    if(!appdata) {
        appdata = (char*)malloc(4096);
        strncpy(appdata, getenv("HOME"), 4096);
        strncat(appdata, ".TreadMarks", 4096);
        if(!ci_FileExists(appdata))
              mkdir(appdata, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    return CStr(appdata);
}

CStr GetCommonAppDataDir()
{
#ifdef PANDORA
    return CStr("/mnt/utmp/treadmarks/");
#else
    return CStr("/usr/local/share/TreadMarks/");
#endif
}
