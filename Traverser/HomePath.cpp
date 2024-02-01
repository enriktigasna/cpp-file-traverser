#include <string>

std::string getHomePath() {
	std::string homePath;
#ifdef _WIN32
	// On Windows, use USERPROFILE as the home directory
	const char* varName = "USERPROFILE";

#else 
	const char* varName = "HOME";
#endif
	size_t requiredSize = 0;
	getenv_s(&requiredSize, nullptr, 0, varName);

	char* userProfile = new char[requiredSize];

	if (getenv_s(&requiredSize, userProfile, requiredSize, varName) == 0) {
		homePath = userProfile;
	}

	return homePath;
}