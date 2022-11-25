#include<iostream>
#include <functional>
#include<unordered_map>
#include"Arguments.hpp"

using vectorArgs = std::vector<std::pair<std::string, int>>;

class Wrapper {
public:

	Wrapper() = delete;

	template<typename Subject, typename ... Args>
	Wrapper(Subject* sub, int(Subject::* method)(Args...), const vectorArgs& _args){
		args = std::make_shared<Arguments>(_args);
		subMethod = [this, sub, method](std::vector<int> const& funcArgs) {
			return callMethod(sub, method, funcArgs, std::make_index_sequence<sizeof...(Args)>{});
		};		
	}



private:
	std::shared_ptr<Arguments> args = nullptr;
	std::function<int(std::vector<int> const& args)> subMethod;

	template<typename Subject, typename Method, size_t... I>
	int callMethod(Subject* sub, Method method, std::vector<int> const& args, std::index_sequence<I...>) {
		return (sub->*method)(args[I]...);
	}
};