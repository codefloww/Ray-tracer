#include "app/scene.hpp"

tbb::enumerable_thread_specific<float> local_max_color;

Scene::Scene() {
    background_color_m = {0.01, 0.01, 0.01};

    camera_m.setPosition(glm::vec3(0.0f, -10.0f, 0.0f));
    camera_m.setDirection(glm::vec3(0.0f, 1.0f, 0.0f));
    camera_m.setUp(glm::vec3(0.0f, 0.0f, 1.0f));
    camera_m.setWidth(0.25f);
    camera_m.setAspectRatio(4.0 / 3.0);
    camera_m.updateCameraGeometry();

    light_list_m.emplace_back(std::make_shared<PointLight>(glm::vec3(0.0f, -10.0f, 25.0f)));
    light_list_m.back()->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

//    light_list_m.emplace_back(std::make_shared<DirectionalLight>(glm::vec3(-1.0f, 2.0f, -1.0f)));
//    light_list_m.back()->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
//    light_list_m.back()->setIntensity(0.05f);
//
//    light_list_m.emplace_back(std::make_shared<Spotlight>(glm::vec3(5.0f, 5.0f, 20.0f),
//                                                          glm::vec3(0.0f, 0.0f, -1.0f), 10.0f, 20.0f));
//    light_list_m.back()->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
//    light_list_m.back()->setIntensity(0.3f);


//    light_list_m.emplace_back(std::make_shared<PointLight>(glm::vec3(25.0f, -10.0f, 25.0f)));
//    light_list_m.back()->setColor(glm::vec3(1.0f, 1.0f, 0.8f));
//    light_list_m.emplace_back(std::make_shared<PointLight>(glm::vec3(0.0f, -4.0f, 20.0f)));
//    light_list_m.back()->setColor(glm::vec3(1.0f, 1.0f, 1.0f));


    object_list_m.emplace_back(std::make_shared<Sphere>());
    Transformation transformation1;
    transformation1.setTransform(glm::vec3(-1.5f, 0.0f, 0.0f),
                                 glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(0.5f, 0.5f, 0.5f));
    Material material1;
    material1.setupMaterial(glm::vec3(0.0f, 1.0f, 0.0f),
                            glm::vec3(0.0f, 1.0f, 0.0f),
                            glm::vec3(1.0f, 1.0f, 1.0f),
                            128.0f);
    object_list_m.back()->setMaterial(material1);
    object_list_m.back()->setTransformation(transformation1);

//    object_list_m.emplace_back(std::make_shared<Sphere>());
//    Transformation transformation5;
//    transformation5.setTransform(glm::vec3(1.5f, 0.0f, 0.0f),
//                                 glm::vec3(0.0f, 0.0f, 0.0f),
//                                 glm::vec3(0.5f, 0.5f, 0.5f));
//    Material material5;
//    material5.setupMaterial(glm::vec3(0.0f, 1.0f, 0.0f),
//                            glm::vec3(0.0f, 1.0f, 0.0f),
//                            glm::vec3(1.0f, 1.0f, 1.0f),
//                            128.0f);
//    object_list_m.back()->setMaterial(material5);
//    object_list_m.back()->setTransformation(transformation5);
//
//    object_list_m.emplace_back(std::make_shared<Plane>());
//    Transformation transplane;
//    transplane.setTransform(glm::vec3(0.0f, 0.0f, -1.0f),
//                            glm::vec3(0.0f, 0.0f, 0.0f),
//                            glm::vec3(50.0f, 50.0f, 1.0f));
//
//    Material material2;
//    material2.setupMaterial(glm::vec3(0.0f, 0.0f, 1.0f),
//                            glm::vec3(0.0f, 0.0f, 1.0f),
//                            glm::vec3(0.0f, 0.0f, 1.0f),
//                            128.0f);
//    object_list_m.back()->setTransformation(transplane);
//    object_list_m.back()->setMaterial(material2);

//    object_list_m.emplace_back(std::make_shared<Plane>());
//    Transformation transformation4;
//    transformation4.setTransform(glm::vec3(0.0f, 1.0f, -1.0f),
//                                 glm::vec3(0.1f, 0.0f, 0.0f),
//                                 glm::vec3(5.0f, 5.0f, 1.0f));
//    object_list_m[3]->setTransformation(transformation4);
//    object_list_m[3]->setColor(glm::vec3(1.0f, 0.0f, 0.0f));

//    object_list_m.emplace_back(std::make_shared<TriangleMesh>("../models/suzanne.obj"));
//    object_list_m.emplace_back(std::make_shared<TriangleMesh>("../models/cube.obj"));
//
//    Transformation dda1;
//    dda1.setTransform(glm::vec3(4.0f, 0.0f, 2.0f),
//                      glm::vec3(0.0f, 0.0f, 0.0f),
//                      glm::vec3(2.0f, 2.0f, 2.0f));
//    object_list_m.back()->setTransformation(dda1);
//    Material material3;
//    material3.setupMaterial(glm::vec3(0.8f, 0.2f, 0.3f),
//                            glm::vec3(1.0f, 0.5f, 0.5f),
//                            glm::vec3(1.0f, 1.0f, 1.0f),
//                            256.0f);
//    object_list_m.back()->setMaterial(material3);



//    for (int i = 0; i < 100; i++){
//        object_list_m.emplace_back(std::make_shared<Sphere>());
//        Transformation transformation;
//        transformation.setTransform(glm::vec3(0.0f, -20.0f-i*3, 0.0f),
//                                     glm::vec3(0.0f, 0.0f, 0.0f),
//                                     glm::vec3(0.5f, 0.5f, 0.5f));
//        Material material;
//        material.setupMaterial(glm::vec3(0.0f, 1.0f, 0.0f),
//                                glm::vec3(0.0f, 1.0f, 0.0f),
//                                glm::vec3(1.0f, 1.0f, 1.0f),
//                                128.0f);
//        object_list_m.back()->setMaterial(material);
//        object_list_m.back()->setTransformation(transformation);
//    }
//    for (int i = 0; i < 0; i++){
//        light_list_m.emplace_back(std::make_shared<PointLight>(glm::vec3(-0.0f, -10.0f, 25.0f)));
//        light_list_m.back()->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
//    }
}

void Scene::render(Image &output_image) {
    namespace tbb = oneapi::tbb;
    using range_t = tbb::blocked_range2d<int>;

    const int width = output_image.getWidth();
    const int height = output_image.getHeight();

    tbb::parallel_for(range_t{0, height, 0, width},
                      [&](const range_t &range) {
                          for (int y = range.rows().begin(); y < range.rows().end(); ++y) {
                              for (int x = range.cols().begin(); x < range.cols().end(); ++x) {
                                  Ray camera_ray;
                                  glm::vec3 int_point;
                                  glm::vec3 loc_normal;
                                  double x_factor = 1.0 / (static_cast<double>(width) / 2.0);
                                  double y_factor = 1.0 / (static_cast<double>(height) / 2.0);
                                  double norm_x = static_cast<double>(x) * x_factor - 1.0;
                                  double norm_y = static_cast<double>(y) * y_factor - 1.0;
                                  camera_m.createRay(norm_x, norm_y, camera_ray);
                                  internalRender(x, y, camera_ray, output_image, int_point, loc_normal);
                              }
                          }
                      }
    );
    output_image.resetColor();
    auto max_color = static_cast<float>(output_image.max_color_m);
    for (const auto &local_color: local_max_color){
        max_color = std::max({local_color, max_color});
    }
    output_image.max_color_m = max_color;
}

void Scene::internalRender(int x, int y, const Ray &camera_ray, Image &output_image, glm::vec3 &int_point,
                           glm::vec3 &loc_normal) const {
    bool blank = true;
    std::shared_ptr<Object> closest_object;
    glm::vec3 closest_int_point;
    glm::vec3 closest_loc_normal;
    double min_distance = std::numeric_limits<double>::max();

    for (const auto &object_m: object_list_m) {
        if (object_m->testIntersections(camera_ray, int_point, loc_normal)) {
            blank = false;
            double distance = glm::length(camera_ray.getOrigin() - int_point);
            if (distance < min_distance) {
                min_distance = distance;
                closest_object = object_m;
                closest_int_point = int_point;
                closest_loc_normal = loc_normal;
            }
        }
    }

    closest_loc_normal = glm::normalize(closest_loc_normal);
    glm::vec3 output_color;
    if (!blank) {
        output_color = computeColor(camera_ray, closest_object, closest_int_point, closest_loc_normal);
    } else {
        output_color = background_color_m;
    }

    output_image.setPixel(x, y, Image::postProcess(output_image.convertColor(glm::vec4 {output_color, 1.0})));
}

glm::vec3
Scene::computeColor(const Ray &camera_ray, const std::shared_ptr<Object> &current_object, const glm::vec3 &int_point,
                    const glm::vec3 &loc_normal) const {
    glm::vec3 color{};
    glm::vec3 diffuse_color{};
    glm::vec3 specular_color{};
    glm::vec3 ambient_color{};
    glm::vec3 output_color{};
    glm::vec3 view_dir{normalize(camera_ray.getOrigin() - int_point)};
    Ray light_ray;

    glm::vec3 diffuse_component{};
    std::pair<glm::vec3, float> specular_component{};
    glm::vec3 ambient_component{};

    float shininess = current_object->getMaterial().getShininess();

    for (const auto &light_m: light_list_m) {
        // It is assumed that diffuse_color, specular_color and ambient_color will be reset in the computeIllumination().
        light_m->computeIllumination(int_point, loc_normal, object_list_m, current_object,
                                     view_dir, diffuse_component, specular_component, ambient_component);
        Scene::accumulateColors(diffuse_component, specular_component, ambient_component,
                                diffuse_color, specular_color, ambient_color, shininess);
    }

    output_color = ambient_color * current_object->getMaterial().getAmbient() +
                   diffuse_color * current_object->getMaterial().getDiffuse() +
                   specular_color * current_object->getMaterial().getSpecular();

    local_max_color.local() = std::max({local_max_color.local(), output_color.r, output_color.g, output_color.b});
    return output_color;
}

void Scene::accumulateColors(glm::vec3 diffuse_component,
                                    std::pair<glm::vec3, float> specular_component,
                                    glm::vec3 ambient_component,
                                    glm::vec3 &diffuse_color,
                                    glm::vec3 &specular_color,
                                    glm::vec3 &ambient_color,
                                    float shininess){
    diffuse_color += diffuse_component;
    float spec = std::pow(specular_component.second, shininess);
    specular_color += spec * specular_component.first;
    ambient_color += ambient_component;
}

void Scene::moveCamera(CameraMovement direction) {
    switch (direction) {
        case CameraMovement::FORWARD:
            camera_m.setPosition(camera_m.getPosition() + camera_m.getDirection() * 0.1f);
            break;
        case CameraMovement::BACKWARD:
            camera_m.setPosition(camera_m.getPosition() - camera_m.getDirection() * 0.1f);
            break;
        case CameraMovement::LEFT:
            camera_m.setPosition(
                    camera_m.getPosition() +
                    glm::normalize(glm::cross(camera_m.getUp(), camera_m.getDirection())) * 0.1f);
            break;
        case CameraMovement::RIGHT:
            camera_m.setPosition(
                    camera_m.getPosition() +
                    glm::normalize(glm::cross(camera_m.getDirection(), camera_m.getUp())) * 0.1f);
            break;
        case CameraMovement::UP:
            camera_m.setPosition(camera_m.getPosition() + camera_m.getUp() * 0.1f);
            break;
        case CameraMovement::DOWN:
            camera_m.setPosition(camera_m.getPosition() - camera_m.getUp() * 0.1f);
            break;
    }

    camera_m.updateCameraGeometry();
}

void Scene::rotateCamera(const glm::vec2 &rotation) {
    glm::vec3 x_axis = glm::normalize(glm::cross(camera_m.getDirection(), camera_m.getUp()));
    camera_m.setDirection(glm::rotate(camera_m.getDirection(), rotation.x, camera_m.getUp()));

    camera_m.setDirection(glm::rotate(camera_m.getDirection(), rotation.y, x_axis));
    camera_m.setUp(glm::rotate(camera_m.getUp(), rotation.y, x_axis));
    camera_m.updateCameraGeometry();
}

