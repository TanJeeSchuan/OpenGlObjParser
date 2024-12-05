#include "Object.h"
#include <iterator>

Object::Object(std::vector<float> v)
{
	//std::copy(v.begin(), v.end(), back_inserter(this->vertices));
	this->vertices = v;
}

std::vector<float> Object::getVertexAtIndex(int index)
{
	std::vector<float> vertex = {};

	if (index > vertices.size() / 3)
		return vertex;

	vertex.push_back(vertices[((index - 1) * 3) + 0]);
	vertex.push_back(vertices[((index - 1) * 3) + 1]);
	vertex.push_back(vertices[((index - 1) * 3) + 2]);


	return vertex;
}

float* Object::getVertexRef(int index)
{
	if (index > vertices.size() / 3 || index < 1)
		return nullptr;

	return &(vertices.at((index - 1) * 3));
}

std::string Object::toString()
{
	std::string str = "";

	for (int i = 0; i < vertices.size() / 3; i++) {
		str.append("V"+ std::to_string(i+1) +	":\tX: "   + std::to_string(vertices[i + 1]));
		str.append(							"\tY: " + std::to_string(vertices[i + 2]));
		str.append(							"\tZ: " + std::to_string(vertices[i + 3]));
		str.append("\n");
	}

	str.append("Face Data: \n");

	for (auto face : faceData) {
		int i = 0;
		for (auto vertexIndex : face) {
			str.append(" V" + std::to_string(i)+ ": " + std::to_string(vertexIndex));
			i++;
		}
		str.append("\n");
	}

	//for (int i = 0; i < faceData.size() / 4; i++) {
	//	str.append("V1: " + std::to_string(faceData[i*4 + 0]));
	//	str.append("\tV2: " + std::to_string(faceData[i*4 + 1]));
	//	str.append("\tV3: " + std::to_string(faceData[i*4 + 2]));
	//	str.append("\tV4: " + std::to_string(faceData[i*4 + 3]));
	//	str.append("\n");
	//}

	return str;
}
