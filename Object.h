#pragma once
#include <vector>
#include <string>
#include <iostream>



class Object
{
public:
	std::string name;
	std::vector<float> vertices;
	std::vector<std::vector<int>> faceData;

	Object() {}

	Object(std::vector<float> v);

	//vertex index starts from 1
	std::vector<float> getVertexAtIndex(int index);
	float* getVertexRef(int index);

	int vertexCount() {
		return (vertices.size() / 3) + 1;
	}

	//std::vector<float> getFaceVerties(int faceIndex) {
	//	std::vector<float> verts = {};

	//	for (auto vertexIndex : faceData[faceIndex]) {
	//		verts.push_back(getVertexAtIndex(vertexIndex)[0]);
	//		verts.push_back(getVertexAtIndex(vertexIndex)[1]);
	//		verts.push_back(getVertexAtIndex(vertexIndex)[2]);
	//	}

	//	//for (int i = 0; i < verts.size() / 3; i += 3) {
	//	//	std::cout << verts.data()[i] << verts.data()[i + 1] << verts.data()[i + 2] << std::endl;
	//	//}

	//	return verts;
	//}

	std::string toString();
};