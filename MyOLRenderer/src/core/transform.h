#pragma once
#include"MyOFRenderer.h"
#include"geometry.h"

namespace MyOLRenderer {
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
    private:
        //data
        Matrix4x4 m, mInv;
	};
}