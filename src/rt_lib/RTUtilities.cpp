/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#include "RTUtilities.h"

void renderScene(int width, int height) {
    auto aspect = 16.0/10.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect*viewport_height;
    auto ray_origin = Point3(0, 0, 0);
    auto horizontal = Vec3(viewport_width, 0, 0);
    auto vertical = Vec3(0, viewport_height, 0);
    int focal_length = 1.0;
    auto lower_left = ray_origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);

    HittableList world;
    world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5) );
    world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    PPM* ppm = new PPM(width, height);

    for (int j = height-1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            auto u = double(i) / (width-1);
            auto v = double(j) / (height-1);
            Ray r(ray_origin, lower_left + u*horizontal + v*vertical - ray_origin);
            ppm->at(j,i) = rayColor(r, world);
        }
    }
    ppm->savePPM("raytrace");
}

Color rayColor(const Ray& r, const hittable& world) {
    hit_record record;
    if (world.hit(r, 0, c_infinity, record)) {
        return 0.5 * (record.normal + Color(1, 1, 1));
    }
    Vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t) * Color(1.0, 1.0, 1.0) + t * Color(0.4, 0.7, 1.0);
}

double degreesToRadians(double degrees) {
    return degrees * c_pi / 180.0;
}