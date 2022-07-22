#pragma once
#include"MyOFRenderer.h"

namespace MyOFRenderer {
	typedef Vector2<float> Vector2f;
	typedef Vector2<int>   Vector2i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<int>   Vector3i;

	template<typename T>
	class Vector2 {
	public:
		//methods
		Vector2() { x = y = 0; }
		Vector2(T x, T y) :x(x), y(y) { assert(!HasNaNs()); }

		bool HasNaNs() const{
			return isnan(x) || isnan(y);
		}
		//长度
		float LengthSquared()const { return x * x + y * y; }
		float Length()const { return sqrt(LengthSquared()); }

		//加法
		Vector2<T> operator+(const Vector2<T> &v)const {
			return Vector2(x + v.x, y + v.y);
		}
		Vector2<T> &operator+(const Vector2<T>& v){
			x += v.x; y += v.y;
			return *this;
		}
		//减法
		Vector2<T> operator-(const Vector2<T>& v)const {
			return Vector2(x - v.x, y - v.y);
		}
		Vector2<T>& operator-(const Vector2<T>& v) {
			x -= v.x; y -= v.y;
			return *this;
		}
		//标量乘
		Vector2<T> operator*(const T s)const {
			return Vector2<T>(x * s, y * s);
		}
		Vector2<T>& operator*=(const T s) {
			x *= s; y *= s;
			return *this;
		}
		//标量除
		Vector2<T> operator/(const T f)const {
			assert(f != 0);
			float inv = 1 / f;
			return Vector2<T>(x * inv, y * inv);
		}
		Vector2<T>& operator/=(const T f) {
			assert(f != 0);
			float inv = 1 / f;
			x *= inv; y *= inv;
			return *this;
		}
		//取负
		Vector2<T> operator-()const {
			return Vector2<T>(-x, -y);
		}

		//索引
		T operator[](int i)const {
			assert(i >= 0 && i <= 1);
			if (i == 0) return x;
			return y;
		}
		T &operator[](int i){
			assert(i >= 0 && i <= 1);
			if (i == 0) return x;
			return y;
		}
		//data
		T x, y;
	};

	template<typename T>
	class Vector3 {
	public:
		//methods
		Vector3() { x = y = z = 0; }
		Vector3(T x, T y, T z) :x(x), y(y), z(z) { assert(!HasNaNs()); }
		Vector3(const Normal3<T>&);
		Vector3(const Point3<T>&);

		bool HasNaNs() const{
			return isnan(x) || isnan(y) || isnan(z);
		}
		//长度
		float LengthSquared()const { return x * x + y * y + z * z; }
		float Length()const { return sqrt(LengthSquared()); }

		//加法
		Vector3<T> operator+(const Vector3<T>& v)const {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}
		Vector3<T>& operator+(const Vector3<T>& v) {
			x += v.x; y += v.y; z += v.z;
			return *this;
		}
		//减法
		Vector3<T> operator-(const Vector3<T>& v)const {
			return Vector3(x - v.x, y - v.y, z - v.z);
		}
		Vector3<T>& operator-(const Vector3<T>& v) {
			x -= v.x; y -= v.y; z -= v.z;
			return *this;
		}
		//标量乘
		Vector3<T> operator*(const T s)const {
			return Vector3<T>(x * s, y * s, z * s);
		}
		Vector3<T>& operator*=(const T s) {
			x *= s; y *= s; z *= s;
			return *this;
		}
		//标量除
		Vector3<T> operator/(const T f)const {
			assert(f != 0);
			float inv = 1 / f;
			return Vector3<T>(x * inv, y * inv,z * inv);
		}
		Vector3<T>& operator/=(const T f) {
			assert(f != 0);
			float inv = 1 / f;
			x *= inv; y *= inv; z *= inv;
			return *this;
		}
		//取负
		Vector3<T> operator-()const {
			return Vector3<T>(-x, -y, -z);
		}

		//索引
		T operator[](int i)const {
			assert(i >= 0 && i <= 2);
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}
		T& operator[](int i) {
			assert(i >= 0 && i <= 2);
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}
		//data
		T x, y, z;
	};

	typedef Point2<float> Point2f;
	typedef Point2<int>   Point2i;
	typedef Point3<float> Point3f;
	typedef Point3<int>   Point3i;

	template<typename T> 
	class Point3 {
	public:
		//methods
		Point3() { x = y = z = 0; }
		Point3(T x, T y, T z) : x(x), y(y), z(z) {
			assert(!HasNaNs());
		}
		template<typename U>
		explicit Point3(const Point3<U>& p) : x((T)p.x), y((T)p.y), z((T)p.z) {
			assert(!HasNaNs());
		}

		template<typename U>
		explicit operator Vector3<U>() {
			return Vector3<U>(x, y, z);
		}
		bool HasNaNs() const{
			return isnan(x) || isnan(y) || isnan(z);
		}

		//点加向量
		Point3<T> operator+(const Vector3<T>& v) const{
			return Point3<T>(x + v.x, y + v.y, z + v.z);
		}
		Point3<T> &operator+=(const Vector3<T>& v) {
			x += v.x; y += v.y; z += v.z;
			return *this;
		}
		//点减点
		Vector3<T> operator-(const Point3<T>& p) const{
			return Vector3<T>(x - p.x, y - p.y, z - p.z);
		}
		//点减向量
		Point3<T> operator-(const Vector3<T>& v) const{
			return Point3<T>(x - v.x, y - v.y, z - v.z);
		}
		Point3<T> &operator-=(const Vector3<T>& v) {
			x -= v.x; y -= v.y; z -= v.z;
			return *this;
		}
		//标量乘
		Point3<T> operator*(const T s)const {
			return Point3<T>(x * s, y * s, z * s);
		}
		Point3<T>& operator*=(const T s) {
			x *= s; y *= s; z *= s;
			return *this;
		}
		//标量除
		Point3<T> operator/(const T s)const {
			return Point3<T>(x / s, y / s, z / s);
		}
		Point3<T>& operator/=(const T s) {
			x /= s; y /= s; z /= s;
			return *this;
		}
		//点加点
		Point3<T> operator+(const Point3<T>& p)const {
			return Point3(x + p.x, y + p.y, z + p.z);
		}
		Point3<T>& operator+(const Point3<T>& p) {
			x += p.x; y += p.y; z += p.z;
			return *this;
		}
		//索引
		T operator[](int i)const {
			assert(i >= 0 && i <= 2);
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}
		T& operator[](int i) {
			assert(i >= 0 && i <= 2);
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}
		//data
		T x, y, z;
	};
	
	template<typename T>
	class Point2 {
	public:
		//methods
		Point2() { x = y = 0; }
		Point2(T x, T y) : x(x), y(y) {
			assert(!HasNaNs());
		}
		
		explicit Point2(const Point3<T>& p) : x(p.x), y(p.y) {
			assert(!HasNaNs());
		}

		bool HasNaNs() const{
			return isnan(x) || isnan(y);
		}
		//点加向量
		Point2<T> operator+(const Vector2<T>& v) const {
			return Point2<T>(x + v.x, y + v.y);
		}
		Point2<T>& operator+=(const Vector2<T>& v) {
			x += v.x; y += v.y;
			return *this;
		}
		//点减点
		Vector2<T> operator-(const Point2<T>& p) const {
			return Vector2<T>(x - p.x, y - p.y);
		}
		//点减向量
		Point2<T> operator-(const Vector2<T>& v) const {
			return Point2<T>(x - v.x, y - v.y);
		}
		Point2<T>& operator-=(const Vector2<T>& v) {
			x -= v.x; y -= v.y;
			return *this;
		}
		//标量乘
		Point2<T> operator*(const T s)const {
			return Point2<T>(x * s, y * s);
		}
		Point2<T>& operator*=(const T s) {
			x *= s; y *= s;
			return *this;
		}
		//点加点
		Point2<T> operator+(const Point2<T>& p)const {
			return Point2(x + p.x, y + p.y);
		}
		Point2<T>& operator+(const Point2<T>& p) {
			x += p.x; y += p.y;
			return *this;
		}
		//索引
		T operator[](int i)const {
			assert(i >= 0 && i <= 1);
			if (i == 0) return x;
			return y;
		}
		T& operator[](int i) {
			assert(i >= 0 && i <= 1);
			if (i == 0) return x;
			return y;
		}
		//data
		T x, y;

	};

	typedef Normal3<float> Normal3f;

	template <typename T> 
	class Normal3 {
	public:
		//methods
		Normal3() { x = y = z = 0; }
		Normal3(T xx, T yy, T zz)
			: x(xx), y(yy), z(zz) {
		}
		explicit Normal3<T>(const Vector3<T>& v) : x(v.x), y(v.y), z(v.z) {
			assert(!v.HasNaNs());
		}
		Normal3<T> operator-() const {
			return Normal3(-x, -y, -z);
		}
		Normal3<T> operator+(const Normal3<T>& n) const {
			return Normal3<T>(x + n.x, y + n.y, z + n.z);
		}

		Normal3<T>& operator+=(const Normal3<T>& n) {
			x += n.x; y += n.y; z += n.z;
			return *this;
		}
		Normal3<T> operator- (const Normal3<T>& n) const {
			return Normal3<T>(x - n.x, y - n.y, z - n.z);
		}

		Normal3<T>& operator-=(const Normal3<T>& n) {
			x -= n.x; y -= n.y; z -= n.z;
			return *this;
		}
		bool HasNaNs() const {
			return isnan(x) || isnan(y) || isnan(z);
		}
		Normal3<T> operator*(T f) const {
			return Normal3<T>(f * x, f * y, f * z);
		}

		Normal3<T>& operator*=(T f) {
			x *= f; y *= f; z *= f;
			return *this;
		}
		Normal3<T> operator/(T f) const {
			assert(f != 0);
			float inv = (float)1 / f;
			return Normal3<T>(x * inv, y * inv, z * inv);
		}

		Normal3<T>& operator/=(T f) {
			assert(f != 0);
			float inv = (float)1 / f;
			x *= inv; y *= inv; z *= inv;
			return *this;
		}
		float LengthSquared() const { return x * x + y * y + z * z; }
		float Length() const { return sqrt(LengthSquared()); }

#ifndef NDEBUG
		Normal3<T>(const Normal3<T>& n) {
			assert(!n.HasNaNs());
			x = n.x; y = n.y; z = n.z;
		}

		Normal3<T>& operator=(const Normal3<T>& n) {
			assert(!n.HasNaNs());
			x = n.x; y = n.y; z = n.z;
			return *this;
		}
#endif // !NDEBUG
		friend std::ostream& operator<<(std::ostream& os, const Normal3<T>& v) {
			os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
			return os;
		}
		bool operator==(const Normal3<T>& n) const {
			return x == n.x && y == n.y && z == n.z;
		}
		bool operator!=(const Normal3<T>& n) const {
			return x != n.x || y != n.y || z != n.z;
		}

		T operator[](int i) const {
			assert(i >= 0 && i <= 2);
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}

		T& operator[](int i) {
			assert(i >= 0 && i <= 2);
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		}
		//data
		T x, y, z;
	};
	

	//光线
	class Ray {
	public:
		//methods
		Ray():tMax(INFINITY){}
		Ray(const Point3f &p,const Vector3f &v,float tMax = INFINITY):o(p),d(v),tMax(tMax){}
		
		Point3f operator()(float t) { return o + (d * t); }

		//data
		Point3f o;
		Vector3f d;
		mutable float tMax;
	};

	//微分光线
	class RayDifferential :public Ray {
	public:
		//Methods
		RayDifferential() { hasDifferentials = false; }
		RayDifferential(const Point3f& p, const Vector3f& v, float tMax = INFINITY) :Ray(o, d, tMax) { hasDifferentials = false; }
		RayDifferential(const Ray &r):Ray(r) { hasDifferentials = false; }

		void ScaleDifferentials(float s) {
			rxOrigin = o + (rxOrigin - o) * s;
			ryOrigin = o + (ryOrigin - o) * s;
			rxDirection = d + (rxDirection - d) * s;
			ryDirection = d + (ryDirection - d) * s;
		}
		//Data
		bool hasDifferentials;
		Point3f rxOrigin, ryOrigin;
		Vector3f rxDirection, ryDirection;

	};


	typedef Bounds2<float> Bounds2f;
	typedef Bounds2<int>   Bounds2i;
	typedef Bounds3<float> Bounds3f;
	typedef Bounds3<int>   Bounds3i;
	//包围盒
	template<typename T>
	class Bounds3 {
	public: 
		//Methods
		Bounds3() {
			T minNum = std::numeric_limits<T>::lowest();
			T maxNum = std::numeric_limits<T>::max();
			pMin = Point3<T>(maxNum, maxNum, maxNum);
			pMax = Point3<T>(minNum, minNum, minNum);//默认空盒子
		}
		Bounds3(const Point3<T> &p):pMin(p),pMax(p){}//包围一个点
		Bounds3(const Point3<T>& p1, const Point3<T>& p2) : pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
			std::min(p1.z, p2.z)),
			pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
				std::max(p1.z, p2.z)) {}

		const Point3<T>& operator[](int i) const {
			assert(i >= 0 && i <= 1);
			return i ? pMax : pMin;
		}
		Point3<T>& operator[](int i) {
			assert(i >= 0 && i <= 1);
			return i ? pMax : pMin;
		}

		Point3<T> Corner(int corner) const {
			return Point3<T>((*this)[(corner & 1)].x,
				(*this)[(corner & 2) ? 1 : 0].y,
				(*this)[(corner & 4) ? 1 : 0].z);
		}

		//返回对角向量
		Vector3<T> Diagonal() const { return pMax - pMin; }
		//表面积
		T SurfaceArea() const {
			Vector3<T> d = Diagonal();
			return 2 * (d.x * d.y + d.x * d.z + d.y * d.z);
		}
		//体积
		T Volume() const {
			Vector3<T> d = Diagonal();
			return d.x * d.y * d.z;
		}
		//最长边
		int MaximumExtent() const {
			Vector3<T> d = Diagonal();
			if (d.x > d.y && d.x > d.z)
				return 0;
			else if (d.y > d.z)
				return 1;
			else
				return 2;
		}
		//插值
		Point3<T> Lerp(const Point3f& t) const {
			return Point3<T>(::Lerp(t.x, pMin.x, pMax.x),
				::Lerp(t.y, pMin.y, pMax.y),
				::Lerp(t.z, pMin.z, pMax.z));
		}

		Vector3<T> Offset(const Point3<T>& p) const {
			Vector3<T> o = p - pMin;
			if (pMax.x > pMin.x) o.x /= pMax.x - pMin.x;
			if (pMax.y > pMin.y) o.y /= pMax.y - pMin.y;
			if (pMax.z > pMin.z) o.z /= pMax.z - pMin.z;
			return o;
		}
		//包围球
		void BoundingSphere(Point3<T>* center, float* radius) const {
			*center = (pMin + pMax) / 2;
			*radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
		}
		bool IntersectP(const Ray&, float*, float*) const;
		bool IntersectP(const Ray&, const Vector3f&,const int[3]) const;
		//Data
		Point3f pMin, pMax;
	};

	//包围盒
	template<typename T>
	class Bounds2 {
	public:
		//Methods
		Bounds2() {
			T minNum = std::numeric_limits<T>::lowest();
			T maxNum = std::numeric_limits<T>::max();
			pMin = Point2<T>(maxNum, maxNum);
			pMax = Point2<T>(minNum, minNum);//默认空盒子
		}
		Bounds2(const Point2<T>& p) :pMin(p), pMax(p) {}//包围一个点
		Bounds2(const Point2<T>& p1, const Point2<T>& p2) : pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y)),
			pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y)) {}

		const Point2<T>& operator[](int i) const {
			assert(i >= 0 && i <= 1);
			return i ? pMax : pMin;
		}
		Point2<T>& operator[](int i) {
			assert(i >= 0 && i <= 1);
			return i ? pMax : pMin;
		}

		Point2<T> Corner(int corner) const {
			return Point2<T>((*this)[(corner & 1)].x,
				(*this)[(corner & 2) ? 1 : 0].y);
		}

		//返回对角向量
		Vector2<T> Diagonal() const { return pMax - pMin; }
		//表面积
		T SurfaceArea() const {
			Vector2<T> d = Diagonal();
			return d.x * d.y;
		}

		//最长边
		int MaximumExtent() const {
			Vector2<T> d = Diagonal();
			if (d.x > d.y)
				return 0;
			else
				return 1;
		}
		//插值
		Point2<T> Lerp(const Point2f& t) const {
			return Point2<T>(::Lerp(t.x, pMin.x, pMax.x),
				::Lerp(t.y, pMin.y, pMax.y));
		}

		Vector2<T> Offset(const Point2<T>& p) const {
			Vector2<T> o = p - pMin;
			if (pMax.x > pMin.x) o.x /= pMax.x - pMin.x;
			if (pMax.y > pMin.y) o.y /= pMax.y - pMin.y;
			return o;
		}
		//包围球
		void BoundingSphere(Point2<T>* center, float* radius) const {
			*center = (pMin + pMax) / 2;
			*radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
		}
		//Data
		Point2f pMin, pMax;
	};

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
		return v1.x * v2.x + v1.y * v2.y;
	}
	//绝对值点乘
	template<typename T>
	inline T AbsDot(const Vector2<T>& v1, const Vector2<T>& v2) {
		return abs(Dot(v1, v2));
	}
	//正规化
	template <typename T>
	inline Vector2<T> Normalize(const Vector2<T>& v) {
		return v / v.Length();
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
	template <typename T>
	inline Vector3<T> Cross(const Normal3<T>& v1, const Vector3<T>& v2) {
		double v1x = v1.x, v1y = v1.y, v1z = v1.z;
		double v2x = v2.x, v2y = v2.y, v2z = v2.z;
		return Vector3<T>((v1y * v2z) - (v1z * v2y),
			(v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x));
	}
	template <typename T>
	inline Vector3<T> Cross(const Vector3<T>& v1, const Normal3<T>& v2) {
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
	template<typename T>
	inline Vector3<T>::Vector3(const Point3<T>& p) : x(p.x), y(p.y), z(p.z) {
		assert(!n.HasNaNs());
	}
	//点乘
	template<typename T>
	inline T Dot(const Normal3<T>& n1, const Vector3<T>& v2) {
		return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
	}
	template<typename T>
	inline T Dot(const Normal3<T>& n1, const Normal3<T>& v2) {
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
	template <typename T>
	inline Normal3<T> Faceforward(const Normal3<T>& n, const Normal3<T>& v) {
		return (Dot(n, v) < 0.f) ? -n : n;
	}
	//乘
	template<typename T>
	inline Normal3<T> operator*(T f, const Normal3<T>& n) {
		return n * f;
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
