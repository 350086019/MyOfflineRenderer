#pragma once
#include"MyOFRenderer.h"
#include"transform.h"

namespace MyOFRenderer {
    class Shape {
    public:
        //<< Shape Interface>>
        Shape(const Transform* ObjectToWorld,
            const Transform* WorldToObject, bool reverseOrientation)
            : ObjectToWorld(ObjectToWorld), WorldToObject(WorldToObject),
            reverseOrientation(reverseOrientation),
            transformSwapsHandedness(ObjectToWorld->SwapsHandedness()) {
        }
        virtual Bounds3f ObjectBound() const = 0;
        Bounds3f WorldBound() const {
            return (*ObjectToWorld)(ObjectBound());
        }

        virtual bool Intersect(const Ray& ray, float* tHit,
            SurfaceInteraction* isect, bool testAlphaTexture = true) const = 0;

        virtual bool IntersectP(const Ray& ray,
            bool testAlphaTexture = true) const {
            return Intersect(ray, nullptr, nullptr, testAlphaTexture);
        }

        virtual float Area() const = 0;
        //<<Shape Public Data >>
        const Transform* ObjectToWorld, * WorldToObject;
        const bool reverseOrientation;
        const bool transformSwapsHandedness;
    };
}