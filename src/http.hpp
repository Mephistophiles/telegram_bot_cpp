#include <string>
#include <vector>

class Http {
	private:
		std::string buffer;

	public:
		Http(void);
		~Http(void);

		std::string Get(std::string url);
		std::string Post(std::string url, std::vector<std::string> params);
};
