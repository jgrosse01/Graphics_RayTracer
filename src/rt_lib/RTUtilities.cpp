/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#include "RTUtilities.h"

void renderBalls(HittableList* world) {
    // lights
    auto diffLight = make_shared<DiffuseLight>(Color(6,6,6));

    // materials
    auto materialGround = make_shared<LambertianDiffuseMaterial>(Color(0.8,0.8,0.0));
    auto materialSphere1 = make_shared<LambertianDiffuseMaterial>(Color(0.0, 0.2, 0.9));
    auto materialSphere2 = make_shared<Metal>(Color(0.8,0.6,0.2), 0.5);
    auto materialSphere3 = make_shared<Metal>( Color(0.8, 0.8, 0.8), 0.01);
    auto materialSphere4 = make_shared<Dielectric>(1.5, Color(1.0,1.0,1.0));

    world->add(make_shared<Sphere>( Point3(0, -100.5, -2.5), 100, materialGround ) );
    world->add(make_shared<Sphere>( Point3(1.5, 0, -2.5), 0.5, materialSphere1 ) );
    world->add(make_shared<Sphere>( Point3(-1.5, 0, -2.5), 0.5, materialSphere2 ) );
    world->add(make_shared<Sphere>( Point3(0, 0, -4.0), 0.5, materialSphere3) );
    world->add(make_shared<Sphere>( Point3(0.5, -0.3, -1), 0.2, materialSphere4) );
    world->add(make_shared<Sphere>(Point3(0,3,-2), 0.3, diffLight));
}

void renderCornell(HittableList* world) {
    // light
    auto lightMaterial = make_shared<DiffuseLight>(Color(4,4,4));

    // materials
    auto rightWallMaterial = make_shared<LambertianDiffuseMaterial>(Color(0.0, 1.0, 0.0));
    auto leftWallMaterial = make_shared<LambertianDiffuseMaterial>(Color(1.0, 0.0, 0.0));
    auto otherMaterial = make_shared<LambertianDiffuseMaterial>(Color(0.95,0.95,0.95));
    auto sphere1Material = make_shared<Dielectric>(1.5, Color(0.9,1.0,0.9));
    auto sphere2Material = make_shared<Metal>(Color(0.8,0.6,0.35), 0.01);

    // objects
    world->add(make_shared<XZRect>(113, 443, 127, 432, 554, lightMaterial));
    world->add(make_shared<YZRect>(0,555,0,555,555,rightWallMaterial));
    world->add(make_shared<YZRect>(0,555,0,555,0,leftWallMaterial));
    world->add(make_shared<XYRect>(0,555,0,555,555,otherMaterial));
    world->add(make_shared<XZRect>(0,555,0,555,555,otherMaterial));
    world->add(make_shared<XZRect>(0,555,0,555,0,otherMaterial));

    // spheres to top blocks
    world->add(make_shared<Translate>(make_shared<RotateY>(make_shared<Sphere>(Point3(82.5, 92.5, 82.5), 92.5, sphere1Material), -18), Vec3(130, 165, 65)));
    world->add(make_shared<Translate>(make_shared<RotateY>(make_shared<Sphere>(Point3(82.5, 82.5, 82.5), 82.5, sphere2Material), 15), Vec3(265,330,295)));

    // make and rotate boxes then add to world.
    world->add(make_shared<Translate>(make_shared<RotateY>(make_shared<Box>(Vec3(0, 0, 0), Vec3(165, 165, 165), otherMaterial), -18), Vec3(130,0,65)));
    world->add(make_shared<Translate>(make_shared<RotateY>(make_shared<Box>(Vec3(0, 0, 0), Vec3(165, 330, 165), otherMaterial), 15), Vec3(265,0,295)));
}

PPM* renderScene(int width, int height, int samplesPerPixel, int rayDepth, char scene) {
    auto* world = new HittableList();

    Color background;

    Camera cam;

    switch (scene) {
        case 'b':
            cam = Camera({0,0.1,0}, {0,0,-1});
            renderBalls(world);
            // sky blue background color
            background = Color(135.0/256.0,206.0/256.0,235.0/256.0);
            break;
        case 'c':
            cam = Camera({278, 278, -800}, {278,278,0}, width/(height*1.0), 40.0);
            renderCornell(world);
            break;
        default:
            background = Color(0,0,0);
            break;
    }

    PPM* ppm = new PPM(width, height);

    for (int j = height-1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            Color pixelColor = Color(0,0,0);
            for (int samples = 0; samples < samplesPerPixel; samples++) {
                auto u = (double(i) + randomDouble()) / (width-1);
                auto v = (double(j) + randomDouble()) / (height-1);
                Ray r = cam.getRay(u, v);
                pixelColor += rayColor(r, background, *world, rayDepth);
            }

            auto r = pixelColor.x();
            auto g = pixelColor.y();
            auto b = pixelColor.z();

            // replace NaN colors because NaN can cause black or white color acne
            if (r != r) r = 0.0;
            if (g != g) g = 0.0;
            if (b != b) b = 0.0;

            auto scale = 1.0 / samplesPerPixel;

            r = pow(scale*r, 1.0/2.0);
            g = pow(scale*g, 1.0/2.0);
            b = pow(scale*b, 1.0/2.0);

            pixelColor.setX(r);
            pixelColor.setY(g);
            pixelColor.setZ(b);

            ppm->at(j,i) = pixelColor;
        }
    }
    return ppm;
}

PPM* renderScene(PPM* existing, int width, int height, int samplesPerPixel, int rayDepth, char scene) {
    auto* world = new HittableList();

    Color background;

    Camera cam;

    switch (scene) {
        case 'b':
            cam = Camera({0,0.1,0}, {0,0,-1});
            renderBalls(world);
            // sky blue background color
            background = Color(135.0/256.0,206.0/256.0,235.0/256.0);
            break;
        case 'c':
            cam = Camera({278, 278, -800}, {278,278,0}, width/(height*1.0), 40.0);
            renderCornell(world);
            break;
        default:
            background = Color(0,0,0);
            break;
    }

    for (int j = height-1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            Color pixelColor = existing->at(j,i);
            // undo gamma correction to be redone later at the end
            pixelColor.setX(pow(pixelColor.x(), 2));
            pixelColor.setY(pow(pixelColor.y(), 2));
            pixelColor.setZ(pow(pixelColor.z(), 2));

            for (int samples = 0; samples < samplesPerPixel; samples++) {
                auto u = (double(i) + randomDouble()) / (width-1);
                auto v = (double(j) + randomDouble()) / (height-1);
                Ray r = cam.getRay(u, v);
                pixelColor += rayColor(r, background, *world, rayDepth);
            }

            auto r = pixelColor.x();
            auto g = pixelColor.y();
            auto b = pixelColor.z();

            // replace NaN colors because NaN can cause black or white color acne
            if (r != r) r = 0.0;
            if (g != g) g = 0.0;
            if (b != b) b = 0.0;

            auto scale = 1.0 / samplesPerPixel;

            r = pow(scale*r, 1.0/2.0);
            g = pow(scale*g, 1.0/2.0);
            b = pow(scale*b, 1.0/2.0);

            pixelColor.setX(r);
            pixelColor.setY(g);
            pixelColor.setZ(b);

            existing->at(j,i) = pixelColor;
        }
    }
    return existing;
}

Color rayColor(const Ray& r, const Color& background, const Hittable& world, int depth) {
    HitRecord record;

    if (depth <= 0) {
        return {0,0,0};
    }
    if (!world.hit(r, 0.001, c_infinity, record)) {
        return background;
    }

    Ray scattered;
    Color attenuation;
    Color emitted = record.materialPointer_->emitted(record.u, record.v, record.p);

    if (!record.materialPointer_->scatter(r, record, attenuation, scattered))
        return emitted;

    return emitted + attenuation * rayColor(scattered, background, world, depth-1);
}