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
#include <experimental/filesystem>

static void CreateDirectoriesRecursivly(const char* the_path) {
	std::error_code e;
	std::experimental::filesystem::create_directories(the_path, e);
	if (e) {
		fprintf(stderr, "Failed to create \"%s\". Error: %s\n", the_path, e.message().c_str());
	}
}

CStr GetAppDataDir()
{
	CStr the_path;
      // Could also have been XDG_CONFIG_HOME but XDG_DATA_HOME matches Window's AppData better.
      const char* xdg_data_home = getenv("XDG_DATA_HOME");
      const char* the_home = getenv("HOME");
      if (xdg_data_home) {
            the_path = xdg_data_home;
            the_path = the_path + CStr("/Tread Marks/");
      }
      else {
            the_path = the_home;
            the_path = the_path + CStr("/.local/share/Tread Marks/");
      }
	CreateDirectoriesRecursivly(the_path.get());
	return the_path;
}


CStr GetCommonAppDataDir()
{
#ifdef PANDORA
    return CStr("/mnt/utmp/treadmarks/");
#else
    return CStr("/usr/local/share/TreadMarks/");
#endif
}
