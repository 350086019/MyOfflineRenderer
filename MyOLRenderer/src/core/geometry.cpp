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
		return std::min(v.x, v.y);
	}
	//最大元素
	template <typename T> 
	T MaxComponent(const Vector2<T>& v) {
		return std::max(v.x, v.y);
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
		return std::min(v.x, std::min(v.y, v.z));
	}
	//最大元素
	template <typename T> 
	T MaxComponent(const Vector3<T>& v) {
		return std::max(v.x, std::max(v.y, v.z));
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
		return Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
	}
	//各元素最小
	template <typename T> Point2<T>
	Max(const Point2<T>& p1, const Point2<T>& p2) {
		return Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
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
		return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
				std::min(p1.z, p2.z));
	}
	//各元素最小
	template <typename T> Point3<T>
	Max(const Point3<T>& p1, const Point3<T>& p2) {
		return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
				std::max(p1.z, p2.z));
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

	//---------------Bounds3--------------------//
	//包围盒求并
	template <typename T> 
	Bounds3 <T> Union(const Bounds3<T>& b, const Point3<T>& p) {
		return Bounds3<T>(Point3<T>(std::min(b.pMin.x, p.x),
			std::min(b.pMin.y, p.y),
			std::min(b.pMin.z, p.z)),
			Point3<T>(std::max(b.pMax.x, p.x),
				std::max(b.pMax.y, p.y),
				std::max(b.pMax.z, p.z)));
	}
	template <typename T> 
	Bounds3<T> Union(const Bounds3<T>& b1, const Bounds3<T>& b2) {
		return Bounds3<T>(Point3<T>(std::min(b1.pMin.x, b2.pMin.x),
			std::min(b1.pMin.y, b2.pMin.y),
			std::min(b1.pMin.z, b2.pMin.z)),
			Point3<T>(std::max(b1.pMax.x, b2.pMax.x),
				std::max(b1.pMax.y, b2.pMax.y),
				std::max(b1.pMax.z, b2.pMax.z)));
	}
	//包围盒求交
	template <typename T> 
	Bounds3<T> Intersect(const Bounds3<T>& b1, const Bounds3<T>& b2) {
		return Bounds3<T>(Point3<T>(std::max(b1.pMin.x, b2.pMin.x),
			std::max(b1.pMin.y, b2.pMin.y),
			std::max(b1.pMin.z, b2.pMin.z)),
			Point3<T>(std::min(b1.pMax.x, b2.pMax.x),
				std::min(b1.pMax.y, b2.pMax.y),
				std::min(b1.pMax.z, b2.pMax.z)));
	}
	//相交检测
	template <typename T>
	bool Overlaps(const Bounds3<T>& b1, const Bounds3<T>& b2) {
		bool x = (b1.pMax.x >= b2.pMin.x) && (b1.pMin.x <= b2.pMax.x);
		bool y = (b1.pMax.y >= b2.pMin.y) && (b1.pMin.y <= b2.pMax.y);
		bool z = (b1.pMax.z >= b2.pMin.z) && (b1.pMin.z <= b2.pMax.z);
		return (x && y && z);
	}
	//内部检测
	template <typename T>
	bool Inside(const Point3<T>& p, const Bounds3<T>& b) {
		return (p.x >= b.pMin.x && p.x <= b.pMax.x &&
			p.y >= b.pMin.y && p.y <= b.pMax.y &&
			p.z >= b.pMin.z && p.z <= b.pMax.z);
	}
	template <typename T>
	bool InsideExclusive(const Point3<T>& p, const Bounds3<T>& b) {
		return (p.x >= b.pMin.x && p.x < b.pMax.x&&
			p.y >= b.pMin.y && p.y < b.pMax.y&&
			p.z >= b.pMin.z && p.z < b.pMax.z);
	}//不包括右上边
	//扩大
	template <typename T, typename U> 
	inline Bounds3<T> Expand(const Bounds3<T>& b, U delta) {
		return Bounds3<T>(b.pMin - Vector3<T>(delta, delta, delta),
			b.pMax + Vector3<T>(delta, delta, delta));
	}
	//---------------Bounds2--------------------//
	//包围盒求并
	template <typename T>
	Bounds2 <T> Union(const Bounds2<T>& b, const Point2<T>& p) {
		return Bounds2<T>(Point2<T>(std::min(b.pMin.x, p.x),
			std::min(b.pMin.y, p.y)),
			Point2<T>(std::max(b.pMax.x, p.x),
				std::max(b.pMax.y, p.y)));
	}
	template <typename T>
	Bounds2<T> Union(const Bounds2<T>& b1, const Bounds2<T>& b2) {
		return Bounds2<T>(Point2<T>(std::min(b1.pMin.x, b2.pMin.x),
			std::min(b1.pMin.y, b2.pMin.y)),
			Point2<T>(std::max(b1.pMax.x, b2.pMax.x),
				std::max(b1.pMax.y, b2.pMax.y)));
	}
	//包围盒求交
	template <typename T>
	Bounds2<T> Intersect(const Bounds2<T>& b1, const Bounds2<T>& b2) {
		return Bounds2<T>(Point2<T>(std::max(b1.pMin.x, b2.pMin.x),
			std::max(b1.pMin.y, b2.pMin.y)),
			Point2<T>(std::min(b1.pMax.x, b2.pMax.x),
				std::min(b1.pMax.y, b2.pMax.y)));
	}
	//相交检测
	template <typename T>
	bool Overlaps(const Bounds2<T>& b1, const Bounds2<T>& b2) {
		bool x = (b1.pMax.x >= b2.pMin.x) && (b1.pMin.x <= b2.pMax.x);
		bool y = (b1.pMax.y >= b2.pMin.y) && (b1.pMin.y <= b2.pMax.y);
		return (x && y);
	}
	//内部检测
	template <typename T>
	bool Inside(const Point2<T>& p, const Bounds2<T>& b) {
		return (p.x >= b.pMin.x && p.x <= b.pMax.x &&
			p.y >= b.pMin.y && p.y <= b.pMax.y);
	}
	template <typename T>
	bool InsideExclusive(const Point2<T>& p, const Bounds2<T>& b) {
		return (p.x >= b.pMin.x && p.x < b.pMax.x&&
			p.y >= b.pMin.y && p.y < b.pMax.y);
	}//不包括右上边
	//扩大
	template <typename T, typename U>
	inline Bounds2<T> Expand(const Bounds2<T>& b, U delta) {
		return Bounds2<T>(b.pMin - Vector2<T>(delta, delta),
			b.pMax + Vector2<T>(delta, delta));
	}
	

}