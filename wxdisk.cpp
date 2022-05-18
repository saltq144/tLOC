#include <fstream>
#include <string>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <filesystem>
#include <iostream>

namespace disk {
	namespace file {
		std::string getContent(std::string path) {
			std::string content = "";
			std::string line = "";
			std::ifstream fil(path);

			if (fil.is_open()) {
				while (std::getline(fil, line)) {
					content = content + line;
					content = content + "\n";
				}
			}

			fil.close();
			return content;
		}



		bool exists(std::string path) {
			std::ifstream fil(path);
			if (fil) {
				fil.close();
				return true;
			}
			else {
				fil.close();
				return false;
			}
		}
		bool create(std::string path) {
			std::ofstream fil(path,
				std::ios::in |
				std::ios::out |
				std::ios::binary |
				std::ios::trunc);
			if (fil) return true;
			fil << std::endl;
			if (fil) return true;
			return false;
		}


		bool overwriteContent(std::string path, std::string content) {
			std::ofstream file(path,
				std::ios::in |
				std::ios::out |
				std::ios::binary |
				std::ios::trunc);
			if (file.is_open()) {
				file << content;
				file.close();
				return true;
			}
			return false;
		}
	}
	namespace dir {
		int exists(std::string path) {
			struct stat info;
        	if( stat( path.c_str(), &info ) != 0 )
        		return 0;
        	else if( info.st_mode & S_IFDIR ) 
        		return 1;
        	else
    			return -1;
        }
    	void create(std::string path) {
			std::filesystem::create_directories(path);
		}
	}
}