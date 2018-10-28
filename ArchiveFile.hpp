#ifndef __ARCHIVE_FILE_HPP__
#define __ARCHIVE_FILE_HPP__

#include <string>

class ArchiveFile
{
	std::string my_path;
	std::string my_filename;
public:
	ArchiveFile(const char *fname);
	bool write();
};

#endif

