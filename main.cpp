#include <SDL2/SDL.h>
#include "Archive.hpp"
#include "ArchiveFile.hpp"

#define ARCHIVE_FILE_NAME "arc.bin"

void show_usage() {
	cout << "usage: arc [c|x] filename" << endl;
	cout << "c: create an archive" << endl;
	cout << "x: extract an archive" << endl;
}

bool create_archive()
{
	// initialize
	char *files[] = { "main.cpp", "archiver.hpp", "archiver.coo" };

	// add ArchiveFiles
	Archive arc;
	bool ret = true;
	for (int i = 0; i < sizeof(files)/sizeof(char *); i++) {
		ret = ret && arc.add( new ArchiveFile(files[i]) );
	}
	if (ret == false) {
		return false;
	}
	ret = ret && arc.wrtite(ARCHIVE_FILE_NAME);

	// do nothing about destruction
	//  because all ArchiveFiles will be deleted when Archive's gone
	
	return ret;
}

bool extract_archive()
{
	// create from an arcvhie file
	Archive arc;
	arc.read(ARCHIVE_FILE_NAME);
	
	// extract all files
	size_type num = arc.get_num_of_files();
	ArchiFile *pfile;
	for (size_type i = 0; i < num; i++) {
		arc.get_arc_file_at(i)->write();
		SDL_RWclose(io);
	}
}

int main(int argc, char *argv[])
{
	// operate
	if (argc != 2) {
		show_usage();
		return -1;
	}

	switch (argv[1][0]) {
		case 'c':
			create_archive();
			break;
		case 'x':
			extract_archive();
			break;
		default:
			show_usage();
			break;
	}
	
	return 0;
}
