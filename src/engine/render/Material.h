#pragma once
#include <unordered_map>
#include <string>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
struct Material
{
	std::unordered_map <std::string, float> floatMap;
	std::unordered_map <std::string, glm::vec3> vec3Map;
	std::unordered_map <std::string, glm::vec2> vec2Map;
	std::string shaderName;
	Material() : shaderName("DefaultShader") {}
	Material(const char* shaderName) : shaderName(shaderName) {}
	Material(const char* shaderName, std::unordered_map <std::string, float> fMap) : floatMap(fMap), shaderName(shaderName)
	{

	}
	
};