//
// Created by john on 30/03/2022.
//

#ifndef QOI_FISH_QOI_H
#define QOI_FISH_QOI_H

///https://qoiformat.org/qoi-specification.pdf

#include <cstdint>

class QOIImageHandler {
private:
    struct qoi_header {
        char magic[4]; // magic bytes "qoif"
        uint32_t width; // image width in pixels (BE)
        uint32_t height; // image height in pixels (BE)
        uint8_t channels; // 3 = RGB, 4 = RGBA
        uint8_t colorspace; // 0 = sRGB with linear alpha
        // 1 = all channels linear
    };

    struct color {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        uint8_t a = 255;
    };

    color* previously_seen_pixels;

    ~QOIImageHandler()=default;

    QOIImageHandler(){
        this->previously_seen_pixels = new color[64];
    }

    static inline uint8_t get_QOI_OP_INDEX(color col) {
        return (col.r * 3 + col.g * 5 + col.b * 7 + col.a * 11) % 64;
    }

};
#endif //QOI_FISH_QOI_H
