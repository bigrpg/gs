#ifndef __IFILESYSTEM__H__
#define __IFILESYSTEM__H__


class IFileSystem
{
public:
	typedef enum 
	{
		FILE_TYPE_NOTFOUND = 0,
		FILE_TYPE_DIRECTORY,
		FILE_TYPE_FILE,
		FILE_TYPE_MAX
	}FILETYPE;

	typedef struct _FILEINFO
	{
		uint64 size_;
		uint64 create_;
		uint64 modified_;
		uint64 accessed_;
	}FILEINFO;


};


#endif //__IFILESYSTEM__H__