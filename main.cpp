#include <vector>
#include <cmath>
#include <limits>
#include <memory>

#include "src/geometry/Sphere.h"
#include "src/geometry/Ray.h"
#include "src/geometry/vec3.h"
#include "src/geometry/hittable.h"
#include "src/geometry/hittable_list.h"
#include "src/ppm/ppm.h"


// some utility

using namespace std;
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}


int width = 600, height = 400;

color ray_color(const Ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.8, 1.0);
}

void renderScene() {
    auto ray_origin = point3(0,0,0);
    auto horizontal = vec3(width, 0, 0);
    auto vertical = vec3(0, height, 0);
    int focal_length = 1.0;
    auto lower_left = ray_origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    hittable_list world;
    world.add(make_shared<Sphere>( point3(0,0,-1), 100) );
    world.add(make_shared<Sphere>(point3(0,-100.5,-1), 100));

    PPM* ppm = new PPM(width, height);

    for (int j = height-1; j >= 0; j--) {
        for (int i = 0; i < width; ++i) {
            auto u = double(i) / (width-1);
            auto v = double(j) / (height-1);
            Ray r(ray_origin, lower_left + u*horizontal + v*vertical);
            ppm->at(j, i) = ray_color(r, world);
        }
    }
    ppm->savePPM("raytrace");
}

int main() {
    renderScene();
    return 0;
}
