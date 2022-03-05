#pragma once
#include<assert.h>
#include<math.h>
#include<iostream>
#include<cmath>
#include<string>
#include <type_traits>
#include <algorithm>
#include <cinttypes>
#include <limits>
#include <memory>
#include <vector>
#include <assert.h>
#include <string.h>

namespace MyOFRenderer {
	//classes
	template<typename T>
	class Vector2;
	template<typename T>
	class Vector3;
	template<typename T>
	class Point3;
	template<typename T>
	class Point2;
	template <typename T>
	class Normal3;
	class Ray;
	class RayDifferential;
	template<typename T>
	class Bounds3;
	template<typename T>
	class Bounds2;

	inline float Lerp(float t, float v1, float v2) { return (1 - t) * v1 + t * v2; }
}
