#pragma once
#include"../core/shape.h"
#include"../core/MyOFRenderer.h"

namespace MyOFRenderer {
    class Sphere : public Shape {
    public:
        //<< Sphere Public Methods >>
        Sphere(const Transform* ObjectToWorld, const Transform* WorldToObject,
            bool reverseOrientation, float radius)
            : Shape(ObjectToWorld, WorldToObject, reverseOrientation),
            radius(radius) { }

        Bounds3f ObjectBound() const {
            return Bounds3f(Point3f(-radius, -radius, -radius),
                Point3f(radius, radius, radius));
        }

        bool Intersect(const Ray& r, float* tHit,
            SurfaceInteraction* isect, bool testAlphaTexture) const {
            float phi;
            Point3f pHit;
            //<< Transform Ray to object space>>
            //<<Compute quadratic sphere coefficients>>
            //<<Solve quadratic equation for t values>>
            //<<Compute sphere hit positionand >>
            //<<Test sphere intersection against clipping parameters>>
            //<<Find parametric representation of sphere hit>>
            //<<Compute error bounds for sphere intersection>>
            //<<Initialize SurfaceInteraction from parametric information>>
            //<<Update tHit for quadric intersection >>
            return true;
        }
    private:
        //<< Sphere Private Data >>
        const float radius;
        //const float zMin, zMax;
        //const float thetaMin, thetaMax, phiMax;
    };
}