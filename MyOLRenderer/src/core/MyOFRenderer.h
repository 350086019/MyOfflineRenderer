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
	#define MachineEpsilon (std::numeric_limits<float>::epsilon() * 0.5)

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
	class Shape;
	class SurfaceInteraction;

	static float ShadowEpsilon = 0.0001f;
	static float Pi = 3.14159265358979323846;
	static float InvPi = 0.31830988618379067154;
	static float Inv2Pi = 0.15915494309189533577;
	static float Inv4Pi = 0.07957747154594766788;
	static float PiOver2 = 1.57079632679489661923;
	static float PiOver4 = 0.78539816339744830961;
	static float Sqrt2 = 1.41421356237309504880;

	inline float Lerp(float t, float v1, float v2) { return (1 - t) * v1 + t * v2; }

	inline float Radians(float deg) { return (Pi / 180) * deg; }

	inline float gamma(int n) {
		return (n * MachineEpsilon) / (1 - n * MachineEpsilon);
	}
}
