/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#include "RTUtilities.h"

PPM* renderScene(int width, int height, int samplesPerPixel, int rayDepth) {
    auto cam = Camera(width/(height*1.0));

    HittableList world;

    // materials
    auto materialSphere1 = make_shared<LambertianDiffuseMaterial>(Color(0.7, 0.3, 0.3));
    auto materialSphere2 = make_shared<LambertianDiffuseMaterial>(Color(0.8,0.8,0.0));
    // issue here is constructor needs material
    world.add(make_shared<Sphere>( Point3(0, 0, -1), 0.5, materialSphere1 ) );
    world.add(make_shared<Sphere>( Point3(0, -100.5, -1), 100, materialSphere2 ) );

    PPM* ppm = new PPM(width, height);

    for (int j = height-1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            Color pixelColor = Color(0,0,0);
            for (int samples = 0; samples < samplesPerPixel; samples++) {
                auto u = (double(i) + randomDouble()) / (width-1);
                auto v = (double(j) + randomDouble()) / (height-1);
                Ray r = cam.getRay(u, v);
                pixelColor += rayColor(r, world, rayDepth);
            }

            ppm->at(j,i) = pixelColor /= samplesPerPixel;
        }
    }
    return ppm;
}

Color rayColor(const Ray& r, const hittable& world, int depth) {
    hit_record record;

    if (depth <= 0) {
        return {0,0,0};
    }
    if (world.hit(r, 0.001, c_infinity, record)) {
        Ray scattered;
        Color attenuation;
        if (record.materialPointer->scatter(r, record, attenuation, scattered))
            return attenuation * rayColor(scattered, world, depth-1);
    }

    // if the ray hits nothing, use a blue-white gradient background
    Vec3 unitDirection = unitVector(r.direction());
    auto t = 0.5*(unitDirection.y() + 1.0);
    return (1.0-t) * Color(1.0, 1.0, 1.0) + t * Color(0.4, 0.7, 1.0);
}

double degreesToRadians(double degrees) {
    return degrees * c_pi / 180.0;
}