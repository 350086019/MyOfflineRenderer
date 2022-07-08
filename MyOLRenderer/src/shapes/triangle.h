#pragma once
#include"../core/shape.h"
#include"../core/MyOFRenderer.h"

namespace MyOFRenderer {
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