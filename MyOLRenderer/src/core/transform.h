#pragma once
#include"MyOFRenderer.h"
#include"geometry.h"
#include"interaction.h"

namespace MyOFRenderer {
    // Matrix4x4 Declarations
    struct Matrix4x4 {
        // Matrix4x4 Public Methods
        Matrix4x4() {
            m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.f;
            m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][0] =
                m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.f;
        }
        Matrix4x4(float mat[4][4]);
        Matrix4x4(float t00, float t01, float t02, float t03, float t10, float t11,
            float t12, float t13, float t20, float t21, float t22, float t23,
            float t30, float t31, float t32, float t33);
        bool operator==(const Matrix4x4& m2) const {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (m[i][j] != m2.m[i][j]) return false;
            return true;
        }
        bool operator!=(const Matrix4x4& m2) const {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (m[i][j] != m2.m[i][j]) return true;
            return false;
        }
        friend Matrix4x4 Transpose(const Matrix4x4&);
        void Print(FILE* f) const {
            fprintf(f, "[ ");
            for (int i = 0; i < 4; ++i) {
                fprintf(f, "  [ ");
                for (int j = 0; j < 4; ++j) {
                    fprintf(f, "%f", m[i][j]);
                    if (j != 3) fprintf(f, ", ");
                }
                fprintf(f, " ]\n");
            }
            fprintf(f, " ] ");
        }
        static Matrix4x4 Mul(const Matrix4x4& m1, const Matrix4x4& m2) {
            Matrix4x4 r;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    r.m[i][j] = m1.m[i][0] * m2.m[0][j] + m1.m[i][1] * m2.m[1][j] +
                    m1.m[i][2] * m2.m[2][j] + m1.m[i][3] * m2.m[3][j];
            return r;
        }
        friend Matrix4x4 Inverse(const Matrix4x4&);

        /*
        friend std::ostream& operator<<(std::ostream& os, const Matrix4x4& m) {
            // clang-format off
            os << StringPrintf("[ [ %f, %f, %f, %f ] "
                "[ %f, %f, %f, %f ] "
                "[ %f, %f, %f, %f ] "
                "[ %f, %f, %f, %f ] ]",
                m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3],
                m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3],
                m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3],
                m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]);
            // clang-format on
            return os;
        }
        */

        float m[4][4];
    };


	class Transform {
	public:
		//methods
		Transform(){}
        Transform(const float mat[4][4]) {
            m = Matrix4x4(mat[0][0], mat[0][1], mat[0][2], mat[0][3],
                mat[1][0], mat[1][1], mat[1][2], mat[1][3],
                mat[2][0], mat[2][1], mat[2][2], mat[2][3],
                mat[3][0], mat[3][1], mat[3][2], mat[3][3]);
            mInv = Inverse(m);
        }
        Transform(const Matrix4x4& m) : m(m), mInv(Inverse(m)) { }
        Transform(const Matrix4x4& m, const Matrix4x4& mInv)
            : m(m), mInv(mInv) {
        }


        friend Transform Inverse(const Transform& t) {
            return Transform(t.mInv, t.m);
        }

        friend Transform Transpose(const Transform& t) {
            return Transform(Transpose(t.m), Transpose(t.mInv));
        }
        bool operator==(const Transform& t) const {
            return t.m == m && t.mInv == mInv;
        }
        bool operator!=(const Transform& t) const {
            return t.m != m || t.mInv != mInv;
        }
        bool operator<(const Transform& t2) const {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j) {
                    if (m.m[i][j] < t2.m.m[i][j]) return true;
                    if (m.m[i][j] > t2.m.m[i][j]) return false;
                }
            return false;
        }
        bool IsIdentity() const {
            return (m.m[0][0] == 1.f && m.m[0][1] == 0.f && m.m[0][2] == 0.f &&
                m.m[0][3] == 0.f && m.m[1][0] == 0.f && m.m[1][1] == 1.f &&
                m.m[1][2] == 0.f && m.m[1][3] == 0.f && m.m[2][0] == 0.f &&
                m.m[2][1] == 0.f && m.m[2][2] == 1.f && m.m[2][3] == 0.f &&
                m.m[3][0] == 0.f && m.m[3][1] == 0.f && m.m[3][2] == 0.f &&
                m.m[3][3] == 1.f);
        }

        template <typename T> 
        inline Point3<T> operator()(const Point3<T>& p) const {
                T x = p.x, y = p.y, z = p.z;
                T xp = m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z + m.m[0][3];
                T yp = m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z + m.m[1][3];
                T zp = m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z + m.m[2][3];
                T wp = m.m[3][0] * x + m.m[3][1] * y + m.m[3][2] * z + m.m[3][3];
                if (wp == 1) return Point3<T>(xp, yp, zp);
                else         return Point3<T>(xp, yp, zp) / wp;
        }
        template <typename T> 
        inline Vector3<T> operator()(const Vector3<T>& v) const {
                T x = v.x, y = v.y, z = v.z;
                return Vector3<T>(m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z,
                    m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z,
                    m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z);
        }

        //法线的变换需要特殊对待
        template <typename T> 
        inline Normal3<T> operator()(const Normal3<T>& n) const {
                T x = n.x, y = n.y, z = n.z;
                return Normal3<T>(mInv.m[0][0] * x + mInv.m[1][0] * y + mInv.m[2][0] * z,
                    mInv.m[0][1] * x + mInv.m[1][1] * y + mInv.m[2][1] * z,
                    mInv.m[0][2] * x + mInv.m[1][2] * y + mInv.m[2][2] * z);
            }

        inline Ray operator()(const Ray& r) const {
            Vector3f oError;
            Point3f o = (*this)(r.o);//浮点误差暂时忽略
            Vector3f d = (*this)(r.d);
            float tMax = r.tMax;
            return Ray(o, d, tMax);
        }

        Bounds3f operator()(const Bounds3f& b) const {
            const Transform& M = *this;
            Bounds3f ret(M(Point3f(b.pMin.x, b.pMin.y, b.pMin.z)));
            ret = Union(ret, M(Point3f(b.pMax.x, b.pMin.y, b.pMin.z)));
            ret = Union(ret, M(Point3f(b.pMin.x, b.pMax.y, b.pMin.z)));
            ret = Union(ret, M(Point3f(b.pMin.x, b.pMin.y, b.pMax.z)));
            ret = Union(ret, M(Point3f(b.pMin.x, b.pMax.y, b.pMax.z)));
            ret = Union(ret, M(Point3f(b.pMax.x, b.pMax.y, b.pMin.z)));
            ret = Union(ret, M(Point3f(b.pMax.x, b.pMin.y, b.pMax.z)));
            ret = Union(ret, M(Point3f(b.pMax.x, b.pMax.y, b.pMax.z)));
            return ret;
        }

        SurfaceInteraction operator()(const SurfaceInteraction& si) const {
            SurfaceInteraction ret;
            //<< Transform p and pError in SurfaceInteraction>>
            //  ret.p = (*this)(si.p, si.pError, &ret.pError);
            ret.p = (*this)(si.p);
            //<<Transform remaining members of SurfaceInteraction >>
            const Transform& t = *this;
            ret.n = Normalize(t(si.n));
            ret.wo = t(si.wo);
            ret.uv = si.uv;
            ret.shape = si.shape;
            ret.dpdu = t(si.dpdu);
            ret.dpdv = t(si.dpdv);
            ret.dndu = t(si.dndu);
            ret.dndv = t(si.dndv);
            ret.shading.n = Normalize(t(si.shading.n));
            ret.shading.dpdu = t(si.shading.dpdu);
            ret.shading.dpdv = t(si.shading.dpdv);
            ret.shading.dndu = t(si.shading.dndu);
            ret.shading.dndv = t(si.shading.dndv);
            ret.dudx = si.dudx;
            ret.dvdx = si.dvdx;
            ret.dudy = si.dudy;
            ret.dvdy = si.dvdy;
            ret.dpdx = t(si.dpdx);
            ret.dpdy = t(si.dpdy);
            ret.bsdf = si.bsdf;
            ret.bssrdf = si.bssrdf;
            ret.primitive = si.primitive;
            //    ret.n = Faceforward(ret.n, ret.shading.n);
            ret.shading.n = Faceforward(ret.shading.n, ret.n);
            return ret;
        }

        Transform operator*(const Transform& t2) const {
            return Transform(Matrix4x4::Mul(m, t2.m),
                Matrix4x4::Mul(t2.mInv, mInv));
        }

        bool SwapsHandedness() const {
            float det =
                m.m[0][0] * (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1]) -
                m.m[0][1] * (m.m[1][0] * m.m[2][2] - m.m[1][2] * m.m[2][0]) +
                m.m[0][2] * (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]);
            return det < 0;
        }
    private:
        //data
        Matrix4x4 m, mInv;
	};
}