#include<iostream>
#include<unordered_map>
#include"Wrapper.hpp"

using vectorArgs = std::vector<std::pair<std::string, int>>;

class Engine {
public:
	void registerCommand(Wrapper const& wrapper, std::string const& command) {
		if (command == "") {
			throw std::exception("invalid command name");
		}
		if (wrappersMap.contains(command)) {
			throw std::exception("such command already exists");
		}
		wrappersMap.insert({ command,  wrapper });
	}

	int execute(std::string const& command, vectorArgs const& args) {
		if (!wrappersMap.contains(command)) {
			throw std::exception("no such command");
		}
		return wrappersMap.at(command).run(args);
	}

private:
	std::unordered_map<std::string, Wrapper> wrappersMap;
};