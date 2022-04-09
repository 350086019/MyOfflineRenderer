#pragma once
#include"MyOFRenderer.h"
#include"geometry.h"
namespace MyOFRenderer {
    struct Interaction {
	    //methods
    public:
        Interaction(){}
        Interaction(const Point3f& p, const Normal3f& n,
            const Vector3f& wo)
            : p(p), wo(wo), n(n){ }
        bool IsSurfaceInteraction() const {
            return n != Normal3f();
        }
	    //data
        Point3f p;
        Vector3f wo;
        Normal3f n;
    };

    class SurfaceInteraction : public Interaction {
    public:
        //methods
        SurfaceInteraction(){}
        SurfaceInteraction(const Point3f& p,
            const Vector3f& pError, const Point2f& uv, const Vector3f& wo,
            const Vector3f& dpdu, const Vector3f& dpdv,
            const Normal3f& dndu, const Normal3f& dndv,
            const Shape* shape)
            : Interaction(p, Normal3f(Normalize(Cross(dpdu, dpdv))), wo),
            uv(uv), dpdu(dpdu), dpdv(dpdv), dndu(dndu), dndv(dndv),
            shape(shape) {
            //<< Initialize shading geometry from true geometry>>
            shading.n = n;
            shading.dpdu = dpdu;
            shading.dpdv = dpdv;
            shading.dndu = dndu;
            shading.dndv = dndv;
            //<<Adjust normal based on orientation and handedness >>
            /*if (shape && (shape->reverseOrientation ^
                shape->transformSwapsHandedness)) {
                n *= -1;
                shading.n *= -1;
            }*/
            
        }
        void SetShadingGeometry(const Vector3f& dpdus,
            const Vector3f& dpdvs, const Normal3f& dndus,
            const Normal3f& dndvs, bool orientationIsAuthoritative) {
            //<< Compute shading.n for SurfaceInteraction>>
            shading.n = Normalize((Normal3f)Cross(dpdus, dpdvs));
            /*if (shape && (shape->reverseOrientation ^
                shape->transformSwapsHandedness))
                shading.n = -shading.n;
            if (orientationIsAuthoritative)
                n = Faceforward(n, shading.n);
            else
                shading.n = Faceforward(shading.n, n);*/
            
            //<<Initialize shading partial derivative values >>
            shading.dpdu = dpdus;
            shading.dpdv = dpdvs;
            shading.dndu = dndus;
            shading.dndv = dndvs;
        }
        //data
        Point2f uv;
        Vector3f dpdu, dpdv;
        Normal3f dndu, dndv;
        const Shape* shape = nullptr;
        struct {
            Normal3f n;
            Vector3f dpdu, dpdv;
            Normal3f dndu, dndv;
        } shading;
    };
}
