#pragma once
#include"../core/shape.h"
#include"../core/MyOFRenderer.h"

namespace MyOFRenderer {
    struct TriangleMesh {
        //Methods
        TriangleMesh(const Transform& ObjectToWorld,
            int nTriangles, const int* vertexIndices, int nVertices,
            const Point3f* P, const Vector3f* S, const Normal3f* N,
            const Point2f* UV);
            //,const std::shared_ptr<Texture<Float>>& alphaMask
        
        //Data
        const int nTriangles, nVertices;
        std::vector<int> vertexIndices;
        std::unique_ptr<Point3f[]> p;
        std::unique_ptr<Normal3f[]> n;
        std::unique_ptr<Vector3f[]> s;
        std::unique_ptr<Point2f[]> uv;
        //std::shared_ptr<Texture<Float>> alphaMask;
    };

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