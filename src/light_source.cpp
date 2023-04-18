//
// Created by paul on 3/18/23.
//

#include "light_source.hpp"

void LightSource::setPosition(const glm::vec3 &position) {
    position_m = position;
}

void LightSource::setColor(const glm::vec3 &color) {
    color_m = color;
}

void LightSource::setIntensity(double intensity) {
    intensity_m = intensity;
}
