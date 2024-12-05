#pragma once
#include <fstream>
#include <fstream>
#include <string>
#include <iostream>
#include "Object.h"

class OpenGlParser
{
	std::vector<float> vertices;
	std::vector <std::vector<int>> faceData;

	std::string str;

	std::ifstream file;
public:
	void openObj(const char path[]) {
		file = std::ifstream(path);
	}

	void loadVertices() {
		vertices = {};
		std::string keyword;
		while (std::getline(file, str)) {
			// Output the text from the file
			if (str.at(0) != '#') {
				keyword = getToken(str, 0);

				if (keyword == "v") {
					auto tokens = getTokens(str);
					vertices.push_back(std::stof(tokens[1]) / 10.0f);
					vertices.push_back(std::stof(tokens[2]) / 10.0f);
					vertices.push_back(std::stof(tokens[3]) / 10.0f);
					//std::cout << std::stof(tokens[1]) << " " << std::stof(tokens[2]) << " " << std::stof(tokens[3]) << "\n";
				}

				if (keyword == "f") {
					auto tokens = getTokens(str);
					std::vector<int> face = {};
					
					for (auto token : tokens) {
						if (token.find('/') != std::string::npos) {
							//std::cout << token << "\n";
							face.push_back(std::stoi(split(token, '/')[0]));
						}
					}
					faceData.push_back(face);
					//faceData.push_back(std::stof(split(tokens[1], '/')[0]));
					//faceData.push_back(std::stof(split(tokens[2], '/')[0]));
					//faceData.push_back(std::stof(split(tokens[3], '/')[0]));
				}
			}
		}
	}

	void loadFaceData()
	{
		//faceData = {};
		//std::string keyword;
		//while (std::getline(file, str)) {
		//	// Output the text from the file
		//	if (str.at(0) != '#') {
		//		keyword = getToken(str, 0);
		//		std::cout << keyword << std::endl;
		//		if (keyword == "f") {
		//			auto tokens = getTokens(str);
		//			faceData.push_back(std::stof(split(tokens[1], '/')[0]));
		//			faceData.push_back(std::stof(split(tokens[2], '/')[0]));
		//			faceData.push_back(std::stof(split(tokens[3], '/')[0]));

		//			//std::cout << std::stof(tokens[1]) << " " << std::stof(tokens[2]) << " " << std::stof(tokens[3]) << "\n";
		//		}
		//	}
		//}
	}

	void createObject(Object* obj) {
		//obj = new Object(vertices);

		obj->name = "as";
		obj->vertices = vertices;
		obj->faceData = faceData;

		//obj = new Object();
		//for (int i = 0; i < vertices.size() / 3; i++) {
		//	obj->vertices.push_back(vertices[i + 1]);
		//	obj->vertices.push_back(vertices[i + 2]);
		//	obj->vertices.push_back(vertices[i + 3]);
		//}
	}

	void clearState() {
		vertices.clear();
	}

private:
	std::string getToken(std::string str, int index)
	{
		int occurance = index;
		std::string outStr = "";
		char c;

		for (int i = 0; i < str.size(); i++) {
			c = str.at(i);
			if (c == ' ') {
				if (occurance == index)
					break;
				else
					occurance++;
			}
			else
				outStr.push_back(c);
		}

		return outStr;
	}

	std::vector<std::string> getTokens(std::string str) {
		std::vector<std::string> outVec = {};
		std::string outStr = "";
		char c;

		for (int i = 0; i < str.size(); i++) {
			c = str.at(i);
			if (c != ' ')
			{
				outStr.push_back(c);
				if (i == str.size() - 1)
					outVec.push_back(outStr);
			}
			else {
				outVec.push_back(outStr);
				outStr = "";
			}


		}

		return outVec;
	}

	std::vector<std::string> split(std::string str, char delimitter) {
		std::vector<std::string> outVec = {};
		std::string outStr = "";
		char c;

		for (int i = 0; i < str.size(); i++) {
			c = str.at(i);
			if (c != delimitter)
			{
				outStr.push_back(c);
				if (i == str.size() - 1)
					outVec.push_back(outStr);
			}
			else {
				outVec.push_back(outStr);
				outStr = "";
			}


		}

		return outVec;
	}
};

