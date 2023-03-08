//
// Created by paul on 3/8/23.
//

#ifndef RAY_TRACER_IMAGE_HPP
#define RAY_TRACER_IMAGE_HPP

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Image {
public:
    Image();
//    Image(int width, int height);
//    Image(const std::string& filename);
    ~Image();

    void Initialize(int width, int height, SDL_Renderer* pRenderer);

//    void SetPixel(int x, int y, const SDL_Color& color);
    void SetPixel(int x, int y, double r, double g, double b, double a);

    void Display() const;

//    SDL_Color GetPixel(int x, int y) const;
//    int GetWidth() const;
//    int GetHeight() const;
private:
    Uint32 ConvertColor(double r, double g, double b, double a) const;
    void InitTexture();

    std::vector<std::vector<double>> m_rChannel;
    std::vector<std::vector<double>> m_gChannel;
    std::vector<std::vector<double>> m_bChannel;
    std::vector<std::vector<double>> m_aChannel;
    int m_width;
    int m_height;
    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;



};
#endif //RAY_TRACER_IMAGE_HPP
