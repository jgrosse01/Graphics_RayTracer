/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#include "RTUtilities.h"

PPM* renderScene(int width, int height, int samplesPerPixel, int rayDepth) {
    auto cam = Camera(width/(height*1.0));

    HittableList world;

    // materials
    auto materialGround = make_shared<LambertianDiffuseMaterial>(Color(0.8,0.8,0.0));
    auto materialSphere1 = make_shared<LambertianDiffuseMaterial>(Color(0.0, 0.2, 0.9));
    auto materialSphere2 = make_shared<Metal>(Color(0.8,0.6,0.2), 0.5);
    auto materialSphere3 = make_shared<Metal>( Color(0.8, 0.8, 0.8), 0.01);
    auto materialSphere4 = make_shared<Dielectric>(1.5, Color(1.0,1.0,1.0));

    world.add(make_shared<Sphere>( Point3(0, -100.5, -2.5), 100, materialGround ) );
    world.add(make_shared<Sphere>( Point3(1.5, 0, -2.5), 0.5, materialSphere1 ) );
    world.add(make_shared<Sphere>( Point3(-1.5, 0, -2.5), 0.5, materialSphere2 ) );
    world.add(make_shared<Sphere>( Point3(0, 0, -4.0), 0.5, materialSphere3) );
    world.add(make_shared<Sphere>( Point3(0, -0.3, -1), 0.2, materialSphere4) );

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

            auto r = pixelColor.x();
            auto g = pixelColor.y();
            auto b = pixelColor.z();

            // replace NaN colors because NaN can cause black or white color acne
            if (r != r) pixelColor.setX(0.0);
            if (g != g) pixelColor.setY(0.0);
            if (b != b) pixelColor.setZ(0.0);

            ppm->at(j,i) = pixelColor /= samplesPerPixel;
        }
    }
    return ppm;
}

Color rayColor(const Ray& r, const Hittable& world, int depth) {
    HitRecord record;

    if (depth <= 0) {
        return {0,0,0};
    }
    if (world.hit(r, 0.001, c_infinity, record)) {
        Ray scattered;
        Color attenuation;
        if (record.materialPointer->scatter(r, record, attenuation, scattered))
            return attenuation * rayColor(scattered, world, depth-1);
        return {0,0,0};
    }

    // if the ray hits nothing, use a blue-white gradient background
    Vec3 unitDirection = unitVector(r.direction());
    auto t = 0.5*(unitDirection.y() + 1.0);
    return (1.0-t) * Color(1.0, 1.0, 1.0) + t * Color(0.4, 0.7, 1.0);
}

double degreesToRadians(double degrees) {
    return degrees * c_pi / 180.0;
}