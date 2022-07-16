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
        

    std::vector<std::shared_ptr<Shape>> Triangle::CreateTriangleMesh(
        const Transform* ObjectToWorld, const Transform* WorldToObject,
        bool reverseOrientation, int nTriangles,
        const int* vertexIndices, int nVertices, const Point3f* p,
        const Vector3f* s, const Normal3f* n, const Point2f* uv)
        //const std::shared_ptr<Texture<Float>>& alphaMask) 
    {
        std::shared_ptr<TriangleMesh> mesh = std::make_shared<TriangleMesh>(
            *ObjectToWorld, nTriangles, vertexIndices, nVertices, p, s, n, uv);
        std::vector<std::shared_ptr<Shape>> tris;
        for (int i = 0; i < nTriangles; ++i)
            tris.push_back(std::make_shared<Triangle>(ObjectToWorld,
                WorldToObject, reverseOrientation, mesh, i));
        return tris;
    }

    Bounds3f Triangle::ObjectBound() const {
        //<< Get triangle vertices in p0, p1, and p2 >>
        const Point3f& p0 = mesh->p[v[0]];
        const Point3f& p1 = mesh->p[v[1]];
        const Point3f& p2 = mesh->p[v[2]];

        return Union(Bounds3f((*WorldToObject)(p0), (*WorldToObject)(p1)),
            (*WorldToObject)(p2));
    };
}