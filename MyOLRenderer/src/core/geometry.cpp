#include"geometry.h"

namespace MyOFRenderer {
	//---------------Vector2--------------------//
	//标量乘
	template<typename T>
	inline Vector2<T> operator*(T s, const Vector2<T>& v) {
		return v * s;
	}
	//绝对值
	template<typename T>
	Vector2<T> Abs(const Vector2<T>& v) {
		return Vector2<T>(abs(v.x), abs(v.y));
	}
	//点乘
	template<typename T>
	inline T Dot(const Vector2<T>& v1, const Vector2<T>& v2) {
		return v1.x * v2.x + v1.y * v2.y ;
	}
	//绝对值点乘
	template<typename T>
	inline T AbsDot(const Vector2<T>& v1, const Vector2<T>& v2) {
		return abs(Dot(v1,v2));
	}
	//正规化
	template <typename T>
	inline Vector2<T> Normalize(const Vector2<T>& v) {
		return v/v.Length();
	}
	//最小元素
	template <typename T> 
	T MinComponent(const Vector2<T>& v) {
		return min(v.x, v.y);
	}
	//最大元素
	template <typename T> 
	T MaxComponent(const Vector2<T>& v) {
		return max(v.x, v.y);
	}
	//最大的下标
	template <typename T>
	int MaxDimension(const Vector2<T>& v) {
		return (v.x > v.y) ? 0 : 1;
	}
	//改变顺序
	template <typename T>
	Vector2<T> Permute(const Vector2<T>& v, int x, int y) {
		return Vector2<T>(v[x], v[y]);
	}

	//---------------Vector3--------------------//
	//叉乘
	template <typename T>
	inline Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2) {
		double v1x = v1.x, v1y = v1.y, v1z = v1.z;
		double v2x = v2.x, v2y = v2.y, v2z = v2.z;
		return Vector3<T>((v1y * v2z) - (v1z * v2y),
			(v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x));
	}
	//标量乘
	template<typename T>
	inline Vector3<T> operator*(T s, const Vector3<T>& v) {
		return v * s;
	}
	//绝对值
	template<typename T>
	Vector3<T> Abs(const Vector3<T>& v) {
		return Vector3<T>(abs(v.x), abs(v.y), abs(v.z));
	}
	//点乘
	template<typename T>
	inline T Dot(const Vector3<T>& v1, const Vector3<T>& v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}
	//绝对值点乘
	template<typename T>
	inline T AbsDot(const Vector3<T>& v1, const Vector3<T>& v2) {
		return abs(Dot(v1, v2));
	}
	//正规化
	template <typename T>
	inline Vector3<T> Normalize(const Vector3<T>& v) {
		return v / v.Length();
	}
	//改变顺序
	template <typename T> 
	Vector3<T> Permute(const Vector3<T>& v, int x, int y, int z) {
			return Vector3<T>(v[x], v[y], v[z]);
	}
	//最小元素
	template <typename T> 
	T MinComponent(const Vector3<T>& v) {
		return min(v.x, min(v.y, v.z));
	}
	//最大元素
	template <typename T> 
	T MaxComponent(const Vector3<T>& v) {
		return max(v.x, max(v.y, v.z));
	}
	//最大的下标
	template <typename T> 
	int MaxDimension(const Vector3<T>& v) {
		return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) :
			((v.y > v.z) ? 1 : 2);
	}
	//建立局部坐标系
	template <typename T> 
	inline void CoordinateSystem(const Vector3<T>& v1, Vector3<T>* v2, Vector3<T>* v3) {
		if (abs(v1.x) > abs(v1.y))
			*v2 = Vector3<T>(-v1.z, 0, v1.x) /
			sqrt(v1.x * v1.x + v1.z * v1.z);
		else
			*v2 = Vector3<T>(0, v1.z, -v1.y) /
			sqrt(v1.y * v1.y + v1.z * v1.z);
		*v3 = Cross(v1, *v2);
	}

	//---------------Point2--------------------//
	//距离
	template <typename T>
	inline float Distance(const Point2<T>& p1, const Point2<T>& p2) {
		return (p1 - p2).Length();
	}
	template <typename T>
	inline float DistanceSquared(const Point2<T>& p1, const Point2<T>& p2) {
		return (p1 - p2).LengthSquared();
	}
	//标量乘
	template<typename T>
	inline Point2<T> operator*(T s, const Point2<T>& v) {
		return v * s;
	}
	//插值
	template<typename T>
	Point2<T> Lerp(float t, const Point2<T>& p0, const Point2<T>& p1) {
		return (1 - t) * p0 + t * p1;
	}
	//各元素最大
	template <typename T> Point2<T>
	Min(const Point2<T>& p1, const Point2<T>& p2) {
		return Point2<T>(min(p1.x, p2.x), min(p1.y, p2.y));
	}
	//各元素最小
	template <typename T> Point2<T>
	Max(const Point2<T>& p1, const Point2<T>& p2) {
		return Point2<T>(max(p1.x, p2.x), max(p1.y, p2.y));
	}
	//下取整
	template <typename T> Point2<T> Floor(const Point2<T>& p) {
		return Point2<T>(floor(p.x), floor(p.y));
	}
	//上取整
	template <typename T> Point2<T> Ceil(const Point2<T>& p) {
		return Point2<T>(ceil(p.x), ceil(p.y));
	}
	//绝对值
	template <typename T> Point2<T> Abs(const Point2<T>& p) {
		return Point2<T>(abs(p.x), abs(p.y));
	}
	//改变顺序
	template <typename T> Point2<T>
	Permute(const Point2<T>& p, int x, int y) {
		return Point2<T>(p[x], p[y]);
	}
	//---------------Point3--------------------//
	//距离
	template <typename T>
	inline float Distance(const Point3<T>& p1, const Point3<T>& p2) {
		return (p1 - p2).Length();
	}
	template <typename T>
	inline float DistanceSquared(const Point3<T>& p1, const Point3<T>& p2) {
		return (p1 - p2).LengthSquared();
	}
	//标量乘
	template<typename T>
	inline Point3<T> operator*(T s, const Point3<T>& v) {
		return v * s;
	}
	//插值
	template<typename T>
	Point3<T> Lerp(float t, const Point3<T>& p0, const Point3<T>& p1) {
		return (1 - t) * p0 + t * p1;
	}
	//各元素最大
	template <typename T> Point3<T>
	Min(const Point3<T>& p1, const Point3<T>& p2) {
		return Point3<T>(min(p1.x, p2.x), min(p1.y, p2.y),
				min(p1.z, p2.z));
	}
	//各元素最小
	template <typename T> Point3<T>
	Max(const Point3<T>& p1, const Point3<T>& p2) {
		return Point3<T>(max(p1.x, p2.x), max(p1.y, p2.y),
				max(p1.z, p2.z));
	}
	//下取整
	template <typename T> Point3<T> Floor(const Point3<T>& p) {
		return Point3<T>(floor(p.x), floor(p.y), floor(p.z));
	}
	//上取整
	template <typename T> Point3<T> Ceil(const Point3<T>& p) {
		return Point3<T>(ceil(p.x), ceil(p.y), ceil(p.z));
	}
	//绝对值
	template <typename T> Point3<T> Abs(const Point3<T>& p) {
		return Point3<T>(abs(p.x), abs(p.y), abs(p.z));
	}
	//改变顺序
	template <typename T> Point3<T>
	Permute(const Point3<T>& p, int x, int y, int z) {
		return Point3<T>(p[x], p[y], p[z]);
	}

	//---------------Normal3--------------------//
	template <typename T> 
	inline Normal3<T> Normalize(const Normal3<T>& n) {
		return n / n.Length();
	}
	template <typename T> 
	inline Vector3<T>::Vector3(const Normal3<T>& n) : x(n.x), y(n.y), z(n.z) {
		assert(!n.HasNaNs());
	}
	//点乘
	template<typename T>
	inline T Dot(const Normal3<T>& n1, const Vector3<T>& v2) {
		return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
	}
	//绝对值点乘
	template<typename T>
	inline T AbsDot(const Normal3<T>& v1, const Vector3<T>& v2) {
		return abs(Dot(v1, v2));
	}
	template <typename T> 
	inline Normal3<T> Faceforward(const Normal3<T>& n, const Vector3<T>& v) {
		return (Dot(n, v) < 0.f) ? -n : n;
	}


}