#ifndef _FILEREADER_H_
#define _FILEREADER_H_
#pragma once

#include "RapidStashCommon.h"
#include "FilesystemCommon.h"
#include "FileIOCommon.h"

namespace STORAGE {
	class Filesystem; // Forward declare

	namespace IO {

		/*
		*  Reader class.
		*  Gives the user access to read a specific file.  The user must perform all locking/unlocking if necessary
		*/
		class Reader : public FileIO {
		public:
			Reader(Filesystem *, File);
			int readInt();
			char readChar();
			std::string readString(FileSize);
			std::string readString();
			char *readRaw(FileSize);
			char *readRaw();
		};

		class SafeReader : public Reader {
		public:
			SafeReader(Filesystem *, File);
			char *readRaw();
		};
	}
}
#endif
