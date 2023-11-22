#ifndef HITTABLE_H
#define HITTABLE_H

/*
Used to construct an abstract class of objects 
which can be hit by rays (e.g. spheres)
*/

#include "ray.h"
class hit_record{
    public:
        point3 p; //
        vec3 normal; // of point of intersection, presumably?
        double t;
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal){
            //assumption: outward_normal of unit length

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable{
    public:
        virtual ~hittable() = default; //defines destructor (?)

        virtual bool hit(const ray& r, interval ray_t,
        hit_record& rec) const = 0;
};

#endif