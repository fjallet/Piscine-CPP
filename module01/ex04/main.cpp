#include <iostream>
#include <fstream>

int main(int	argv, char	**argc){
	if (argv != 4)
		std::cout << "the right syntax is ./replace <filename> \"string 1\" \"string 2\"" << std::endl;

	std::ifstream	ifs(argc[1]);
	std::string		str;
	std::string		res;
	std::string		add;
	std::string		s1;
	std::string		s2;
	std::string		ret;
	size_t			pos1;
	size_t			pos2;
	ifs >> add;
	while (add.size() != 0){
		str += add;
		str += '\n';
		add = "";
		ifs >> add;
	}
	pos1 = 0;
	pos2 = 0;
	s1 = argc[2];
	s2 = argc[3];
	while (pos2 != std::string::npos){
		pos2 = str.find(s1, pos1);
		if (pos2 == std::string::npos){
			if (res.empty())
				res = str;
			else
				res += str.substr(pos1, str.size() - pos1);
			break;
		}
		res += str.substr(pos1, pos2 - pos1);
		res += s2;
		pos1 = pos2 + s1.size();
	}
	ret += argc[1];
	ret += ".replace";
	std::ofstream	ofs(ret);
	ofs << res;
	//std::cout << str << std::endl;
	//std::cout << res << std::endl;
	return (0);
}