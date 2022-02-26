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

		bool HasNaNs() {
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

		bool HasNaNs() {
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
		bool HasNaNs() {
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

		bool HasNaNs() {
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
}
