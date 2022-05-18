/*
    Copyright (C) 2022 saltq144

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Author email: topiasq333fl@gmail.com
*/
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