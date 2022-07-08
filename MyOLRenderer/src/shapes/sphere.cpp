#include"sphere.h"

namespace MyOFRenderer {
    Bounds3f Sphere::ObjectBound() const {
        return Bounds3f(Point3f(-radius, -radius, -radius),
        Point3f(radius, radius, radius));
    }

    bool Sphere::Intersect(const Ray& r, float* tHit,
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
        pHit = ray((float)tShapeHit);
        //<< Refine sphere intersection point >>
        if (pHit.x == 0 && pHit.y == 0) pHit.x = 1e-5f * radius;
        phi = std::atan2(pHit.y, pHit.x);
        if (phi < 0) phi += 2 * Pi;
        //<<Find parametric representation of sphere hit>>
        float u = phi / (Pi * 2);
        float theta = std::acos(Clamp(pHit.z / radius, -1, 1));
        float v = (theta) / (Pi);

        float zRadius = std::sqrt(pHit.x * pHit.x + pHit.y * pHit.y);
        float invZRadius = 1 / zRadius;
        float cosPhi = pHit.x * invZRadius;
        float sinPhi = pHit.y * invZRadius;
        Vector3f dpdu(-2 * Pi * pHit.y, 2 * Pi * pHit.x, 0);
        Vector3f dpdv = (Pi)*Vector3f(pHit.z * cosPhi, pHit.z * sinPhi,
            -radius * std::sin(theta));

        Vector3f d2Pduu = -(2 * Pi) * (2 * Pi) * Vector3f(pHit.x, pHit.y, 0);
        Vector3f d2Pduv = Pi * pHit.z * (2 * Pi) *
            Vector3f(-sinPhi, cosPhi, 0.);
        Vector3f d2Pdvv = -Pi * Pi * Vector3f(pHit.x, pHit.y, pHit.z);
        //<< Compute coefficients for fundamental forms>>
        float E = Dot(dpdu, dpdu);
        float F = Dot(dpdu, dpdv);
        float G = Dot(dpdv, dpdv);
        Vector3f N = Normalize(Cross(dpdu, dpdv));
        float e = Dot(N, d2Pduu);
        float f = Dot(N, d2Pduv);
        float g = Dot(N, d2Pdvv);
        //<<Compute and from fundamental form coefficients >>
        float invEGF2 = 1 / (E * G - F * F);
        Normal3f dndu = Normal3f((f * F - e * G) * invEGF2 * dpdu +
            (e * F - f * E) * invEGF2 * dpdv);
        Normal3f dndv = Normal3f((g * F - f * G) * invEGF2 * dpdu +
            (f * F - g * E) * invEGF2 * dpdv);
        //<<Compute error bounds for sphere intersection>>
        //<<Initialize SurfaceInteraction from parametric information>>
        *isect = (*ObjectToWorld)(
            SurfaceInteraction(pHit, Point2f(u, v), -ray.d, dpdu, dpdv,
                dndu, dndv, this));
        //<<Update tHit for quadric intersection >>
        *tHit = (float)tShapeHit;
        return true;
    }

    bool Sphere::IntersectP(const Ray& r,
        bool testAlphaTexture) const {
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
        return true;
    }

    float Sphere::Area() const {
        return 4 * Pi * radius * radius;
    }
        
}