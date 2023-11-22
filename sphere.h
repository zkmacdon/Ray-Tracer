#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        // defines constructor and assigns values to class attributes
        sphere(point3 _center, double _rad) : center(_center), rad(_rad) {}


        bool hit(const ray& r, interval ray_t,hit_record& rec) const override{
            vec3 oc = r.origin() - center;
            auto a = r.direction().length_squared();
            auto half_b = dot(oc, r.direction());
            auto c = oc.length_squared() - rad*rad;

            auto discriminant = half_b*half_b - a*c;
            if (discriminant < 0) return false;
            auto sqrtd = sqrt(discriminant);

            // finding nearest root w/in acceptable range --> remember, only interested in + vals for the most part
            auto root = (-half_b - sqrtd) / a;
            if (!ray_t.surrounds(root)){
                root = (-half_b + sqrtd) /a ;
                if (!ray_t.surrounds(root)) return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);

            vec3 outward_normal = (rec.p  - center) / rad;
            rec.set_face_normal(r,outward_normal);
            return true;
        }

    private:
        point3 center;
        double rad;

};

#endif