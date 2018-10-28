#ifndef __ARCHIVE_HPP__
#define __ARCHIVE_HPP__

class Archive
{
	vector <ArchiveFile *> my_arc_files;
public:
	virtual ~Archive(); // will delete all ArchiveFile *ptrs
	bool add(ArchiveFile *pfile);
	
	// only read & write can access archive file in file system
	bool write(char *archive_file_name);
	bool read(char *archive_file_name);

	// get ArchiveFile instance
	size_type get_num_of_files() { return my_arc_files.size(); }
	ArchiveFile *get_arc_file_at(size_type i) { return my_arc_files.at(i); }
};

#endif

