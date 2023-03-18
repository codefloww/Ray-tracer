//
// Created by paul on 3/8/23.
//

#ifndef RAY_TRACER_IMAGE_HPP
#define RAY_TRACER_IMAGE_HPP

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Image {

    std::vector<std::vector<double>> r_channel_m;
    std::vector<std::vector<double>> g_channel_m;
    std::vector<std::vector<double>> b_channel_m;
    std::vector<std::vector<double>> a_channel_m;
    int width_m = 0;
    int height_m = 0;
    SDL_Renderer *renderer_m = nullptr;
    SDL_Texture *texture_m = nullptr;

public:
    Image() = default;

    ~Image();

    void initialize(int width, int height, SDL_Renderer *renderer);

    void setPixel(int x, int y, double r, double g, double b, double a);

    void display() const;

    // get pixel color
    [[nodiscard]] std::vector<double> getPixel(int x, int y) const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] Uint32 convertColor(double r, double g, double b, double a) const;

    void initTexture();

};

#endif //RAY_TRACER_IMAGE_HPP
