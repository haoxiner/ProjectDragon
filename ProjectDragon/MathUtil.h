#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

namespace PD
{
using Vector2f = glm::vec2;
using Vector3f = glm::vec3;
using Quaternion = glm::quat;
using Matrix4x4f = glm::mat4;

inline Matrix4x4f MakeTranslationMatrix(const Vector3f& vec3f)
{
	Matrix4x4f identity(1.0f);
	return glm::translate(identity, vec3f);
}
}