#include <string>

namespace disk {
	namespace file {
		std::string getContent(std::string path);
		bool exists(std::string path);
		bool create(std::string path);
		bool overwriteContent(std::string path, std::string content);
	}
	namespace dir {
		int exists(std::string path);
    	void create(std::string path);
	}
}