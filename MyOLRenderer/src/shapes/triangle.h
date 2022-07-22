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
        Triangle(const Transform* ObjectToWorld, const Transform* WorldToObject,
            bool reverseOrientation, const std::shared_ptr<TriangleMesh>& mesh, int triNumber)
            : Shape(ObjectToWorld, WorldToObject, reverseOrientation),
            mesh(mesh) {
            v = &mesh->vertexIndices[3 * triNumber];
        }

        //从别的shape转化成一系列triangle
        std::vector<std::shared_ptr<Shape>> CreateTriangleMesh(
            const Transform* ObjectToWorld, const Transform* WorldToObject,
            bool reverseOrientation, int nTriangles,
            const int* vertexIndices, int nVertices, const Point3f* p,
            const Vector3f* s, const Normal3f* n, const Point2f* uv);

        Bounds3f ObjectBound() const;

        bool Intersect(const Ray& r, float* tHit,
            SurfaceInteraction* isect, bool testAlphaTexture) const;

        bool IntersectP(const Ray& r,
            bool testAlphaTexture) const;

        float Area() const;

    private:
        void GetUVs(Point2f uv[3]) const {
            if (mesh->uv) {
                uv[0] = mesh->uv[v[0]];
                uv[1] = mesh->uv[v[1]];
                uv[2] = mesh->uv[v[2]];
            }
            else {
                uv[0] = Point2f(0, 0);
                uv[1] = Point2f(1, 0);
                uv[2] = Point2f(1, 1);
            }
        }
        //Data
        std::shared_ptr<TriangleMesh> mesh;
        const int* v;

    };
}