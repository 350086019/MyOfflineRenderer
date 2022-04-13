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
            Ray ray = (*WorldToObject)(r);
            //<<Compute quadratic sphere coefficients>>
            float ox(ray.o.x), oy(ray.o.y), oz(ray.o.z);
            float dx(ray.d.x), dy(ray.d.y), dz(ray.d.z);
            float a = dx * dx + dy * dy + dz * dz;
            float b = 2 * (dx * ox + dy * oy + dz * oz);
            float c = ox * ox + oy * oy + oz * oz - float(radius) * float(radius);
            //<<Solve quadratic equation for t values>>
            float t0, t1;
            if (!Quadratic(a, b, c, &t0, &t1))
                return false;
            //<<Compute sphere hit positionand >>
            if (t0 > ray.tMax || t1 <= 0)
                return false;
            float tShapeHit = t0;
            if (tShapeHit <= 0) {
                tShapeHit = t1;
                if (tShapeHit > ray.tMax)
                    return false;
            }
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