#include"triangle.h"

namespace MyOFRenderer {
    TriangleMesh::TriangleMesh(const Transform& ObjectToWorld,
        int nTriangles, const int* vertexIndices, int nVertices,
        const Point3f* P, const Vector3f* S, const Normal3f* N,
        const Point2f* UV
        //,const std::shared_ptr<Texture<Float>>& alphaMask
    ) :nTriangles(nTriangles), nVertices(nVertices),
        vertexIndices(vertexIndices, vertexIndices + 3 * nTriangles)//alphaMask(alphaMask)
    {
        //Transform mesh vertices to world space
        p.reset(new Point3f[nVertices]);
        for (int i = 0; i < nVertices; ++i)
            p[i] = ObjectToWorld(P[i]);
        //Copy UV, N, and S vertex data, if present
        if (UV) {
            uv.reset(new Point2f[nVertices]);
            memcpy(uv.get(), UV, nVertices * sizeof(Point2f));
        }
        if (N) {
            n.reset(new Normal3f[nVertices]);
            for (int i = 0; i < nVertices; ++i) n[i] = ObjectToWorld(N[i]);
        }
        if (S) {
            s.reset(new Vector3f[nVertices]);
            for (int i = 0; i < nVertices; ++i) s[i] = ObjectToWorld(S[i]);
        }
    }
        
 

    class Triangle : public Shape {
    public:
        //<< Sphere Public Methods >>
        Triangle(const Transform* ObjectToWorld, const Transform* WorldToObject,
            bool reverseOrientation, float radius)
            : Shape(ObjectToWorld, WorldToObject, reverseOrientation),
            radius(radius) { }

        Bounds3f ObjectBound() const;

        bool Intersect(const Ray& r, float* tHit,
            SurfaceInteraction* isect, bool testAlphaTexture) const;

        bool IntersectP(const Ray& r,
            bool testAlphaTexture) const;

        float Area() const;

    private:
        //<< Sphere Private Data >>
        const float radius;
        //const float zMin, zMax;
        //const float 0, Pi, (2*Pi);
    };
}